// MGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
# define INFINITY 1000
# define MAX_VERTEX_NUM 20 //���ֵ
# define OK 1
typedef enum
{
	DG,DN,UDG,UDN
}GraphKind;// {����ͼ��������������ͼ��������}

typedef int EType;			//����EType����Ϊint
typedef int InfoType; 
typedef int VertexType;		//����VertexType����Ϊint
typedef struct ArcCell		
{	
	EType adj;				//EType�Ƕ����ϵ���͡�����Ȩͼ����1��0��ʾ���ڷ�//��Ȩͼ����ΪȨֵ����
	EType *info;			//�û������Ϣָ��	
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];//��������
    AdjMatrix  arcs;                //�ڽӾ���
   int vexnum,arcnum;              //ͼ�ĵ�ǰ�������ͻ���
   GraphKind kind;                 //ͼ�������־
}MGraph;

//�ڽӱ����͵Ķ��壺
//#define MAX_VERTEX_NUM   20        //���峣��MAX_VERTEX_NUMΪ20
//#define OK 1
typedef int VertexType;
//typedef int InfoType;
typedef struct ArcNode		//����ͼ�Ĵ洢�ṹ
{
	int adjvex;              //�û���ָ��Ķ����λ��
    int weight;              //�û���Ȩֵ
    struct ArcNode *nextarc;  //ָ����һ������ָ��
}ArcNode;

typedef struct VNode
{
	VertexType data;       //������Ϣ
    ArcNode *firstarc;     //ָ���һ�������ö���Ļ���ָ��
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
	AdjList vertices;
    int vexnum,arcnum;  //ͼ�ĵ�ǰ�������ͻ���
    int kind;           //ͼ�������־
}ALGraph;

//3������ĺ����ǲ������飨�ڽӾ��󣩱�ʾ��������������������ա�
int CreatUDN(MGraph &G)		 
{
	int IncInfo,i,j,k,v1,v2,w;
	printf("���붥�����ͱ���,���磨1,1,0��, 0��ʾ����������Ϣ:");
	//getchar();
	scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &IncInfo);
  /*  printf("Please input the number of G.vexnum (eg,G.vexnum=4):");
    scanf("%d", &G.vexnum); //���붥����G.vexnum
    printf("Please input the number of G.arcnum (eg,G.arcnum=4):");
    scanf("%d", &G.arcnum); //�������G.arcnum*/
	
	for(i = 0; i < G.vexnum; ++i)
	{
		printf("�����붥�㣺");
		scanf("%d", &G.vexs[i]);
	}
    for(i=0;i<G.vexnum;++i)
	{
		for(j=0;j<G.vexnum;++j)
        {
			G.arcs[i][j].adj=INFINITY;	//��ʼ���ڽӾ���
	        G.arcs[i][j].info=NULL;	
        }
	}
   printf("Plese input arc(V1-->V2), For example: (1,3,2),(2,4,3)...\n");
   for(k=0; k < G.arcnum; ++k)		//�����ڽӾ���
   {
	   printf("Please input the %dth arc's v1 and v2:",k+1);//����һ����
       scanf("%d,%d,%d",&v1,&v2,&w);			
      /* printf("Please input the arc's weight :");
       scanf(" ", &G.arcs);  	//����ߵ�Ȩֵ*/
       i=v1; j=v2;
	   i--;  j--;
	   G.arcs[i][j].adj = w;
       
       G.arcs[j][i] = G.arcs[i][j];
	   //�ڽӾ����Ӧλ��Ԫ�ظ�ֵ
   } 
   return (OK);
} 
//4�������������ͼ���ڽӾ���ĺ�����
void  print_GreatMGraph(MGraph &G) 
 {
	int i,j;
    printf("The Graph is :\n");
    for(i=0; i< G.vexnum; i++)
	{
		for(j=0; j< G.vexnum; j++)
        {
			if(G.arcs[i][j].adj == INFINITY)
				printf("��  ");
			else
			printf("%d  ", G.arcs[i][j]); 
		}
		printf("\n");
	} 
 }

//5�����������ڽӱ�Ĵ洢�ṹ������
int CreateDG(ALGraph &G)	
{
	int IncInfo,i,j,k,v1,v2,w;
    printf("Please input the number of G.vexnum (eg,G.vexnum=4): ");
    scanf("%d", &G.vexnum);                      		//���붥����G.vexnum
    printf("Please input the number of G.arcnum (eg,G.arcnum=4): ");
    scanf("%d", &G.arcnum);                      		//���뻡��G.arcnum
    printf("Please input the number of IncInfo (0 for none)    : ");
    scanf("%d",&IncInfo);		//������Ϣû�У�������0
    for(i=0;i<G.vexnum;++i)      //��ʼ��ͼ
    {
		G.vertices[i].data=i; 
	    G.vertices[i].firstarc = NULL;                             	
    }
   printf("Plese input arc(V1-->V2), For example: (1,3,2),(2,4,3)...\n");
   for(k=0;k<G.arcnum;++k)	//�������еı�
   {
	  printf("Please input the %dth arc's v1 and v2:",k+1);//����һ����
      scanf("%d,%d,%d",&v1,&v2,&w);
      i=v1; j=v2;
      i--;  j--;
      ArcNode *p;
      p=(ArcNode *)malloc(sizeof(ArcNode));                               	//����һ��ArcNode���͵Ľ���p
      if(!p)
      {
		  printf("Overflow!");
	      return (0);
      }
      p->adjvex=j;		//�� p->adjvex��ֵ
      p->weight=w;
      p->nextarc = G.vertices[i].firstarc;                                   
      G.vertices[i].firstarc=p;
   } 
   return (OK);
} 
//6�������������ͼ���ڽӾ�������
void  print_GreatALGraph(ALGraph &G) 
 {
	int i;
	ArcNode *p;
    printf("The Graph is :\n");
    for(i=0;i<G.vexnum;i++)
	{
		printf("%d",i+1);
		p= G.vertices[i].firstarc;//��p��ֵΪ�����ڵ�i+1������Ļ���ָ��
		while(p)
		{
			printf("->%d(%d)",(p->adjvex)+1,p->weight);
			 p = p->nextarc;	 //��pָ������ֻ��һ�����
		}
		printf("\n");
	}
 }

int main(int argc, char* argv[])
{
	MGraph MG;
	ALGraph ALG;
	CreatUDN(MG);
	print_GreatMGraph(MG);
	CreateDG(ALG);
	print_GreatALGraph(ALG);
	return 0;
}
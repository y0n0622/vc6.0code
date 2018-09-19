// MGraphPrim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
# define INFINITY 1000
# define MAX_VERTEX_NUM 20 //���ֵ
# define OK 1

typedef int EType;			//����EType����Ϊint
typedef int InfoType; 
typedef int VertexType;		//����VertexType����Ϊint
typedef int VRType;
typedef int lowcost;

typedef struct		
{
	VertexType adjvex;
    VRType    lowcost;
}Closedge;


typedef enum
{
	DG,DN,UDG,UDN
}GraphKind;// {����ͼ��������������ͼ��������}


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


int Minimum(Closedge *closedge,int Vexnum)	
{   int min=1,j;                        
    if(closedge[min].lowcost!=0)
      min++;				//closedge[min].lowcost!=0
    for(j=0;j<Vexnum;++j)
      if(closedge[j].lowcost<closedge[min].lowcost
	      &&closedge[j].lowcost>0)
	       //min=closedge[j].lowcost;
	       min = j;//                  
    return (min);
} 

int LocatedVex(MGraph G,VertexType u)	
{ 
	return u;//����ֵ u
}

void MiniSpanTree_Prim(MGraph G,VertexType u)	//������ķ�㷨�ӵ�u���������������G����С������
{  int k,j,i,Vexnum=G.vexnum;
   k=LocatedVex(G,u);
   Closedge closedge[MAX_VERTEX_NUM];
   for(j=0;j<G.vexnum;++j)	//���������ʼ��
     if(j!=k)
     {
		 closedge[j].adjvex=u;  	// (u,j)
		 closedge[j].lowcost=G.arcs[k][j].adj;
     }
   closedge[k].lowcost=0;	//U include k
   for(i=1;i<G.vexnum;++i)
   {
	   k=Minimum(closedge,Vexnum);	//select k=min(closedge[vi].lowcost)
      printf("(%d,%d)",closedge[k-1].adjvex,G.vexs[k]);
      printf("=%d\n",G.arcs[closedge[k-1].adjvex-1][G.vexs[k]-1].adj);
      closedge[k].lowcost=0;	//U include k
      for(j=0;j<G.vexnum;++j)   //renew closedge[k]
	if(G.arcs[k][j].adj<closedge[j].lowcost)
	   {  closedge[j].adjvex=k;
	      closedge[j].lowcost=G.arcs[k][j].adj;
	   } 
   } 
} 

int main(int argc, char* argv[])
{
	MGraph G;
    VertexType u=1;
    printf("=====================\n");
    CreatUDN(G);                   //����CreatUDN()��������ͼ	
	print_GreatMGraph(G);
	printf("The MiniSpanTree_Prim is created as follow order:\n");
    MiniSpanTree_Prim(G, u);      	//����MiniSpanTree_Prim������������С������   
	return 0;
}
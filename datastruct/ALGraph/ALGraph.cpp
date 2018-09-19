// ALGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <iostream.h>
#include <stdlib.h>
#define INFINITY 1000
#define MAX_NUM 20
#define MAX_VERTEX_NUM 20 //���ֵ
#define OK 1
typedef enum
{
	DG,DN,UDG,UDN
}GraphKind;// {����ͼ��������������ͼ��������}
//�ڽӱ����͵Ķ��壺
//#define MAX_VERTEX_NUM   20        //���峣��MAX_VERTEX_NUMΪ20
//#define OK 1
typedef int VertexType;
typedef int InfoType;
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
/////////////
//2����������������ȱ���������
void DFS(ALGraph G,int v)
{
	int w;
	int visited[MAX_NUM] = {0};
    visited[v]=1;//v
	printf("%d->", G.vertices[v].data + 1);
    //cout<<G.vertices[v].data<<"->";
    for(w=G.vertices[v].data; G.vertices[v].firstarc!=NULL;
	  w=G.vertices[v].firstarc->adjvex,
       G.vertices[v].firstarc=G.vertices[v].firstarc->nextarc)
     if(visited[w]==0)
	   DFS(G, w);                            	
} 
void DFSTraverse(ALGraph G)	
{
	int v;
    int visited[MAX_VERTEX_NUM];
    for(v=0;v<G.vexnum;++v)
       visited[v] = 0;   	//��ʼ��visited���飬��ֵΪ0
    for(v=0;v<G.vexnum;++v)
    {
	   if(visited[v]==0)
	      DFS(G, v);     	//����DFS()
    }
	printf("NULL\n");
} 

/*�˹�������Ҫ�õ������������ݽṹ�����еĶ����ʵ����ͬѧ�ǲο�ʵ�����������õ��Ķ������ͺͽ��ӡ����Ӻ�����ԭ����˵����
������������SqQueue;
���г�ʼ����int InitQueue(SqQueue &Q)	
���ӣ�int EnQueue(SqQueue &Q,QElemType e)	
���ӣ�int DeQueue(SqQueue &Q,QElemType &e)
�жӿգ�int QueueEmpty(SqQueue Q)	
*/

#define MAXQSIZE 100
typedef struct
{
	int *data;
	int front;
	int rear;
}SqQueue;

/* �����˳�����*/
int InitQueue(SqQueue &Q)	//InitQueue() sub-function
{
	Q.data = (int *)malloc(MAXQSIZE * sizeof(int));
	if(!Q.data)
	{
		printf("�����ڴ�ʧ�ܣ�\n");
		exit(0);
	}
	Q.rear = 0;
	Q.front = Q.rear;
    return (OK);
}

/*��˳�����β������Ԫ��*/
int EnQueue(SqQueue &Q,int e)	
{  
	if((Q.rear +1) % MAXQSIZE == Q.front)
    {
		printf("��������! \n");
	    return (0);
    }
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
    return (OK);
}
int QueueEmpty(SqQueue Q)
{
	if(Q.front == Q.rear)
	{
		//printf("����Ϊ�գ�");
		return 1;
	}
	return 0;
}

/*��˳�����ͷɾ��Ԫ��*/
SqQueue DeQueue(SqQueue &Q,int e)	
{
	if(Q.front == Q.rear)
	{
		printf("����Ϊ�գ�");
		exit(0);
	}
	e = Q.data[Q.front];

	Q.front = (Q.front + 1) % MAXQSIZE;
	
    return Q;
} 

//3����������������ȱ���������
void BFSTraverse(ALGraph G)	
{
	int v,w;
	int visited[MAX_VERTEX_NUM];
	SqQueue Q;
	for(v=0;v<G.vexnum;++v)
		visited[v]=0;		
	InitQueue(Q);	
	for(v=0;v<G.vexnum;++v)
	{
		if(visited[v]==0)
		{
			visited[v]=1;
			printf("%d-->",G.vertices[v].data + 1);
			EnQueue(Q,v);		
			while(QueueEmpty(Q) == 0)
			{
				DeQueue(Q, v);//
				for(w=G.vertices[v].data; G.vertices[v].firstarc!=NULL; 
					w=G.vertices[v].firstarc->adjvex,G.vertices[v].firstarc=G.vertices[v].firstarc->nextarc)
				{
					if(visited[w]==0)
					{
						visited[w]=1;
						printf("%d-->",G.vertices[w].data+1);
						EnQueue(Q,w);//                           	
					} 
				}

			}
		} 
	}
	printf("NULL\n");
}

int main(int argc, char* argv[])
{
	ALGraph G;
    printf("===============\n");
    CreateDG(G);  //����ͼG
	print_GreatALGraph(G);
    printf("DFS Traverse is as follows :\n");
    printf("Begin->");
    DFSTraverse(G);                        //����DFSTraverse����������ͼ����������ȱ���
    printf("BFS Traverse is as follows :\n");
    printf("Begin->");
    BFSTraverse(G);//����BFSTraverse()������ͼ���й�����ȱ���        

	return 0;
}
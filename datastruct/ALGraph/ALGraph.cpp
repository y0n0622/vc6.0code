// ALGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <iostream.h>
#include <stdlib.h>
#define INFINITY 1000
#define MAX_NUM 20
#define MAX_VERTEX_NUM 20 //最大值
#define OK 1
typedef enum
{
	DG,DN,UDG,UDN
}GraphKind;// {有向图，有向网，无向图，无向网}
//邻接表类型的定义：
//#define MAX_VERTEX_NUM   20        //定义常量MAX_VERTEX_NUM为20
//#define OK 1
typedef int VertexType;
typedef int InfoType;
typedef struct ArcNode		//定义图的存储结构
{
	int adjvex;              //该弧所指向的顶点的位置
    int weight;              //该弧的权值
    struct ArcNode *nextarc;  //指向下一条弧的指针
}ArcNode;

typedef struct VNode
{
	VertexType data;       //顶点信息
    ArcNode *firstarc;     //指向第一条依附该顶点的弧的指针
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
	AdjList vertices;
    int vexnum,arcnum;  //图的当前顶点数和弧数
    int kind;           //图的种类标志
}ALGraph;
//5、补充完整邻接表的存储结构函数。
int CreateDG(ALGraph &G)	
{
	int IncInfo,i,j,k,v1,v2,w;
    printf("Please input the number of G.vexnum (eg,G.vexnum=4): ");
    scanf("%d", &G.vexnum);                      		//输入顶点数G.vexnum
    printf("Please input the number of G.arcnum (eg,G.arcnum=4): ");
    scanf("%d", &G.arcnum);                      		//输入弧数G.arcnum
    printf("Please input the number of IncInfo (0 for none)    : ");
    scanf("%d",&IncInfo);		//弧的信息没有，就输入0
    for(i=0;i<G.vexnum;++i)      //初始化图
    {
		G.vertices[i].data=i; 
	    G.vertices[i].firstarc = NULL;                             	
    }
   printf("Plese input arc(V1-->V2), For example: (1,3,2),(2,4,3)...\n");
   for(k=0;k<G.arcnum;++k)	//输入所有的边
   {
	  printf("Please input the %dth arc's v1 and v2:",k+1);//输入一条边
      scanf("%d,%d,%d",&v1,&v2,&w);
      i=v1; j=v2;
      i--;  j--;
      ArcNode *p;
      p=(ArcNode *)malloc(sizeof(ArcNode));                               	//申请一个ArcNode类型的结点给p
      if(!p)
      {
		  printf("Overflow!");
	      return (0);
      }
      p->adjvex=j;		//给 p->adjvex赋值
      p->weight=w;
      p->nextarc = G.vertices[i].firstarc;                                   
      G.vertices[i].firstarc=p;
   } 
   return (OK);
} 
//6、补充完整输出图的邻接矩阵函数。
void  print_GreatALGraph(ALGraph &G) 
 {
	int i;
	ArcNode *p;
    printf("The Graph is :\n");
    for(i=0;i<G.vexnum;i++)
	{
		printf("%d",i+1);
		p= G.vertices[i].firstarc;//给p赋值为依附于第i+1个顶点的弧的指针
		while(p)
		{
			printf("->%d(%d)",(p->adjvex)+1,p->weight);
			 p = p->nextarc;	 //让p指向链表只下一个结点
		}
		printf("\n");
	}
 }
/////////////
//2、补充完整深度优先遍历函数。
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
       visited[v] = 0;   	//初始化visited数组，初值为0
    for(v=0;v<G.vexnum;++v)
    {
	   if(visited[v]==0)
	      DFS(G, v);     	//调用DFS()
    }
	printf("NULL\n");
} 

/*此功能中需要用到队列这种数据结构，队列的定义和实现请同学们参考实验二，这里对用到的队列类型和进队、出队函数的原型做说明。
队列类型名：SqQueue;
队列初始化：int InitQueue(SqQueue &Q)	
进队：int EnQueue(SqQueue &Q,QElemType e)	
出队：int DeQueue(SqQueue &Q,QElemType &e)
判队空：int QueueEmpty(SqQueue Q)	
*/

#define MAXQSIZE 100
typedef struct
{
	int *data;
	int front;
	int rear;
}SqQueue;

/* 构造空顺序队列*/
int InitQueue(SqQueue &Q)	//InitQueue() sub-function
{
	Q.data = (int *)malloc(MAXQSIZE * sizeof(int));
	if(!Q.data)
	{
		printf("分配内存失败！\n");
		exit(0);
	}
	Q.rear = 0;
	Q.front = Q.rear;
    return (OK);
}

/*在顺序队列尾插入新元素*/
int EnQueue(SqQueue &Q,int e)	
{  
	if((Q.rear +1) % MAXQSIZE == Q.front)
    {
		printf("队列已满! \n");
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
		//printf("队列为空！");
		return 1;
	}
	return 0;
}

/*在顺序队列头删除元素*/
SqQueue DeQueue(SqQueue &Q,int e)	
{
	if(Q.front == Q.rear)
	{
		printf("队列为空！");
		exit(0);
	}
	e = Q.data[Q.front];

	Q.front = (Q.front + 1) % MAXQSIZE;
	
    return Q;
} 

//3、补充完整广度优先遍历函数。
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
    CreateDG(G);  //创建图G
	print_GreatALGraph(G);
    printf("DFS Traverse is as follows :\n");
    printf("Begin->");
    DFSTraverse(G);                        //调用DFSTraverse（）函数对图进行深度优先遍历
    printf("BFS Traverse is as follows :\n");
    printf("Begin->");
    BFSTraverse(G);//调用BFSTraverse()函数对图进行广度优先遍历        

	return 0;
}
// MGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
# define INFINITY 1000
# define MAX_VERTEX_NUM 20 //最大值
# define OK 1
typedef enum
{
	DG,DN,UDG,UDN
}GraphKind;// {有向图，有向网，无向图，无向网}

typedef int EType;			//定义EType类型为int
typedef int InfoType; 
typedef int VertexType;		//定义VertexType类型为int
typedef struct ArcCell		
{	
	EType adj;				//EType是顶点关系类型。对无权图，用1或0表示相邻否；//带权图，则为权值类型
	EType *info;			//该弧相关信息指针	
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];//顶点向量
    AdjMatrix  arcs;                //邻接矩阵
   int vexnum,arcnum;              //图的当前顶点数和弧数
   GraphKind kind;                 //图的种类标志
}MGraph;

//邻接表类型的定义：
//#define MAX_VERTEX_NUM   20        //定义常量MAX_VERTEX_NUM为20
//#define OK 1
typedef int VertexType;
//typedef int InfoType;
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

//3、下面的函数是采用数组（邻接矩阵）表示法，构造无向网，请填空。
int CreatUDN(MGraph &G)		 
{
	int IncInfo,i,j,k,v1,v2,w;
	printf("输入顶点数和边数,例如（1,1,0）, 0表示不含其它信息:");
	//getchar();
	scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &IncInfo);
  /*  printf("Please input the number of G.vexnum (eg,G.vexnum=4):");
    scanf("%d", &G.vexnum); //输入顶点数G.vexnum
    printf("Please input the number of G.arcnum (eg,G.arcnum=4):");
    scanf("%d", &G.arcnum); //输入边数G.arcnum*/
	
	for(i = 0; i < G.vexnum; ++i)
	{
		printf("请输入顶点：");
		scanf("%d", &G.vexs[i]);
	}
    for(i=0;i<G.vexnum;++i)
	{
		for(j=0;j<G.vexnum;++j)
        {
			G.arcs[i][j].adj=INFINITY;	//初始化邻接矩阵
	        G.arcs[i][j].info=NULL;	
        }
	}
   printf("Plese input arc(V1-->V2), For example: (1,3,2),(2,4,3)...\n");
   for(k=0; k < G.arcnum; ++k)		//构造邻接矩阵
   {
	   printf("Please input the %dth arc's v1 and v2:",k+1);//输入一条边
       scanf("%d,%d,%d",&v1,&v2,&w);			
      /* printf("Please input the arc's weight :");
       scanf(" ", &G.arcs);  	//输入边的权值*/
       i=v1; j=v2;
	   i--;  j--;
	   G.arcs[i][j].adj = w;
       
       G.arcs[j][i] = G.arcs[i][j];
	   //邻接矩阵对应位置元素赋值
   } 
   return (OK);
} 
//4、补充完整输出图的邻接矩阵的函数。
void  print_GreatMGraph(MGraph &G) 
 {
	int i,j;
    printf("The Graph is :\n");
    for(i=0; i< G.vexnum; i++)
	{
		for(j=0; j< G.vexnum; j++)
        {
			if(G.arcs[i][j].adj == INFINITY)
				printf("∞  ");
			else
			printf("%d  ", G.arcs[i][j]); 
		}
		printf("\n");
	} 
 }

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
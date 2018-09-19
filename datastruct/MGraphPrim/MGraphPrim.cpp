// MGraphPrim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
# define INFINITY 1000
# define MAX_VERTEX_NUM 20 //最大值
# define OK 1

typedef int EType;			//定义EType类型为int
typedef int InfoType; 
typedef int VertexType;		//定义VertexType类型为int
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
}GraphKind;// {有向图，有向网，无向图，无向网}


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
	return u;//返回值 u
}

void MiniSpanTree_Prim(MGraph G,VertexType u)	//用普里姆算法从第u个顶点出发构造网G的最小生成树
{  int k,j,i,Vexnum=G.vexnum;
   k=LocatedVex(G,u);
   Closedge closedge[MAX_VERTEX_NUM];
   for(j=0;j<G.vexnum;++j)	//辅助数组初始化
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
    CreatUDN(G);                   //调用CreatUDN()函数创建图	
	print_GreatMGraph(G);
	printf("The MiniSpanTree_Prim is created as follow order:\n");
    MiniSpanTree_Prim(G, u);      	//调用MiniSpanTree_Prim（）函数求最小生成树   
	return 0;
}
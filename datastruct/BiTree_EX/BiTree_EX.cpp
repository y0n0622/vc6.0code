// BiTree_EX.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef char TElemType;

typedef struct BiTNode 
{
	TElemType data;                                                      
	BiTNode *lchild, *rchild;                          
} BiTNode, *BiTree;

void  PrintData(TElemType x)
{
	printf("%c",x);
}

/*按先序序列建立一棵二叉树*/
void CreatBiTree(BiTree &T)
{
	TElemType  ch;
	scanf("%c",&ch);
	if(ch==' ')
	{
		T=NULL;
		return;
	}
	else
	{
		if(	!(T = (BiTNode *)malloc(sizeof(BiTNode))))
		{
			printf("Overflow.\n");
			exit(0);
		}
		T->data = ch;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);                                                                  
	}
}

void PreOrder(BiTree T, void (*Visit)(TElemType item))
/*前序遍历二叉树t，访问操作为Visit()函数*/
{
	if(T!= NULL)
	{
		Visit(T->data);
		PreOrder(T->lchild, Visit);
		PreOrder(T->rchild, Visit);  
	}
}

void InOrder(BiTree T, void (*Visit)(TElemType item)) /*中序t */
{
	if(T!= NULL)
	{
		 
		InOrder(T->lchild, Visit);
		Visit(T->data);
		InOrder(T->rchild, Visit);
	}
}
 
void PostOrder(BiTree T, void (*Visit)(TElemType item)) /*后序 */
{
	if(T!= NULL)
	{
		PostOrder(T->lchild, Visit);
		PostOrder(T->rchild, Visit);
		Visit(T->data);
	}
}

/////////任务二/////////

int BTreeDepth(BiTree T)
{
	int leftdep,rightdep;
	if (T==NULL)
		return(0);
	else
	{
		leftdep = BTreeDepth(T->lchild);
		rightdep = BTreeDepth(T->rchild);                                  
		if (leftdep > rightdep)
			return(leftdep+1);
		else
			return(rightdep+1);
	}
}

int NodeCount(BiTree T)
{
	if (T == NULL)
		return(0);
	else 
		return (NodeCount(T->lchild) + NodeCount(T->rchild) + 1);
}


int LeafCount(BiTree T)
{
	if (T == NULL)
		return(0);
	else
	{
		if ( T->lchild == NULL && T->rchild == NULL)
			return(1);
		else
			return(LeafCount(T->lchild) + LeafCount(T->rchild));
	}
}


int OneChildCount(BiTree T)
{
	if (T==NULL)
		return(0);
	else
		if( T->lchild != NULL && T->rchild == NULL || T->lchild == NULL && T->rchild !=NULL)
        return(OneChildCount(T->lchild) + OneChildCount(T->rchild) + 1);
   else
		return(OneChildCount(T->lchild) + OneChildCount(T->rchild));
}

int TwoChildCount(BiTree T)
{
	if (T==NULL)
		return(0);
	else
	{
		if ( T->lchild != NULL && T->rchild != NULL )
			return( TwoChildCount(T->lchild) + TwoChildCount(T->rchild) + 1);
		else
			return (TwoChildCount(T->lchild) + TwoChildCount(T->rchild));
	}
}



int main(int argc, char* argv[])
{
	int choice;
	BiTree root;

	printf("下面建立一棵二叉树，结点数据输入按先序次序。\n");
	printf("输入数据请注意，每一个非空结点的所有孩子数据都要给出\n");
	printf("若孩子为空，请用空格符表示。\n");
	printf("请输入二叉树结点的数据，这里设定为字符:\n");
	CreatBiTree(root);

	printf("================================\n");
	printf("1：先序序列：\n");
	printf("2：中序序列：\n");
	printf("3：后序序列：\n");
	printf("4：二叉树的深（高）度：\n");
	printf("5：二叉树的结点数：\n");
	printf("6：二叉树的叶子结点数：\n");
	printf("7：二叉树的度为2的结点数：\n");
	printf("8：二叉树的度为1的结点数：\n");
	printf("其它值则退出：\n");
	printf("================================\n");
	
	
	do
	{
		printf("请输入对应的操作码：");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\n先序序列为：");
				   PreOrder(root,PrintData);printf("\n");break;
			case 2:printf("\n中序序列为：");
				   InOrder(root,PrintData);printf("\n");break;
			case 3:printf("\n后序序列为：");
				   PostOrder(root,PrintData);printf("\n");break;
			case 4:printf("二叉树的深度是：%d\n",BTreeDepth(root));break;
			case 5:printf("二叉树的结点数是：%d\n",NodeCount(root));break;
			case 6:printf("二叉树的叶子数是：%d\n",LeafCount(root));break;
			case 7:printf("二叉树的度为2的结点数是：%d\n",TwoChildCount(root));break;
			case 8:printf("二叉树的度为1的结点数是：%d\n",OneChildCount(root));break;
		}
	}while(choice>0&&choice<9);
    return 0;

}

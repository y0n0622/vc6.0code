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

/*���������н���һ�ö�����*/
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
/*ǰ�����������t�����ʲ���ΪVisit()����*/
{
	if(T!= NULL)
	{
		Visit(T->data);
		PreOrder(T->lchild, Visit);
		PreOrder(T->rchild, Visit);  
	}
}

void InOrder(BiTree T, void (*Visit)(TElemType item)) /*����t */
{
	if(T!= NULL)
	{
		 
		InOrder(T->lchild, Visit);
		Visit(T->data);
		InOrder(T->rchild, Visit);
	}
}
 
void PostOrder(BiTree T, void (*Visit)(TElemType item)) /*���� */
{
	if(T!= NULL)
	{
		PostOrder(T->lchild, Visit);
		PostOrder(T->rchild, Visit);
		Visit(T->data);
	}
}

/////////�����/////////

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

	printf("���潨��һ�ö�����������������밴�������\n");
	printf("����������ע�⣬ÿһ���ǿս������к������ݶ�Ҫ����\n");
	printf("������Ϊ�գ����ÿո����ʾ��\n");
	printf("������������������ݣ������趨Ϊ�ַ�:\n");
	CreatBiTree(root);

	printf("================================\n");
	printf("1���������У�\n");
	printf("2���������У�\n");
	printf("3���������У�\n");
	printf("4������������ߣ��ȣ�\n");
	printf("5���������Ľ������\n");
	printf("6����������Ҷ�ӽ������\n");
	printf("7���������Ķ�Ϊ2�Ľ������\n");
	printf("8���������Ķ�Ϊ1�Ľ������\n");
	printf("����ֵ���˳���\n");
	printf("================================\n");
	
	
	do
	{
		printf("�������Ӧ�Ĳ����룺");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\n��������Ϊ��");
				   PreOrder(root,PrintData);printf("\n");break;
			case 2:printf("\n��������Ϊ��");
				   InOrder(root,PrintData);printf("\n");break;
			case 3:printf("\n��������Ϊ��");
				   PostOrder(root,PrintData);printf("\n");break;
			case 4:printf("������������ǣ�%d\n",BTreeDepth(root));break;
			case 5:printf("�������Ľ�����ǣ�%d\n",NodeCount(root));break;
			case 6:printf("��������Ҷ�����ǣ�%d\n",LeafCount(root));break;
			case 7:printf("�������Ķ�Ϊ2�Ľ�����ǣ�%d\n",TwoChildCount(root));break;
			case 8:printf("�������Ķ�Ϊ1�Ľ�����ǣ�%d\n",OneChildCount(root));break;
		}
	}while(choice>0&&choice<9);
    return 0;

}

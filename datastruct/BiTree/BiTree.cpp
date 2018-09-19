// BiTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include<stdlib.h>

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
	printf("����ֵ���˳���\n");
	printf("================================\n");
	
	do
	{
		printf("�������Ӧ�Ĳ����룺");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n��������Ϊ��");
				PreOrder(root, PrintData);
				printf("\n");
				break;
			case 2:
				printf("\n��������Ϊ��");
				InOrder(root, PrintData);
				printf("\n");
				break;
			case 3:
				printf("\n��������Ϊ��");
				PostOrder(root, PrintData);
				printf("\n");
		}
	}while(choice>0&&choice<4);
    return 0;
}
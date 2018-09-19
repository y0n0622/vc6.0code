// LinkListTelBook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>*/

#define   MaxSize   100

typedef struct
{
	char xuehao[14];//学号
	char name[20];  //姓名
	int sex;        //性别
	char tel[14];  //联系电话
	char qq[12];   //QQ号

}DataType;

typedef struct node
{
	DataType data;
	node *next;
}ListNode, *LinkList;

/////////建立通讯录/////////
LinkList CreatList()
{
	LinkList head;
	ListNode *pNode;
	char flag = 'y';
	head = (ListNode *)malloc(sizeof(ListNode));
	memset(head, 0, sizeof(LinkList));
	head->next = NULL;
	while((flag == 'y') || (flag == 'Y'))
	{
		pNode = (ListNode *)malloc(sizeof(ListNode));
		if(!pNode)
		{
			printf("创建失败！\n");
			exit(-1);
		}
		printf("请输入数据(学号  姓名  性别（0或1） 联系电话  QQ号)：\n");
		scanf("%s%s%d%s%s", &pNode->data.xuehao, &pNode->data.name, &pNode->data.sex, &pNode->data.tel, &pNode->data.qq);
		pNode->next = head->next;
		head->next = pNode;
		printf("创建成功！\n");
		getchar();
		printf("是否继续输入？（y/n）:\n");
		scanf("%c", &flag);
	}
	return head;
}

/////////在通讯录中插入数据/////////
void InsertLinkList(LinkList head,int sort)
{
	LinkList p; //游标
	LinkList pNode;//新节点
	int ListBegin = 0;
	char flag = 'y';
	p = head;
	while((flag == 'y') || flag == ('Y'))
	{	
		while(p && ListBegin < sort - 1)
		{
			p = p->next;
			++ListBegin;
		}
		if(!p || ListBegin > sort - 1)
		{
			printf("插入失败！\n");
			exit(-1);
		}
		pNode = (ListNode *)malloc(sizeof(ListNode));  //新节点
		if(!pNode)
		{
			printf("插入失败！\n");
			exit(-1);
		}
		printf("请输入数据(学号  姓名  性别（0或1） 联系电话  QQ号)：\n");
		scanf("%s%s%d%s%s", &pNode->data.xuehao, &pNode->data.name, &pNode->data.sex, &pNode->data.tel, &pNode->data.qq);
		pNode->next = p->next; 
		p->next = pNode;
		printf("插入成功！\n");
		getchar();
		printf("继续插入？（y/n）:\n");
		scanf("%c", &flag);
	}
}

/////////删除通讯录中的数据/////////
void DeleteElemLinkList(LinkList head, int sort)
{ 
	LinkList pNode; //游标
	LinkList qNode;
	DataType data;
	int ListBegin = 0;
	char flag = 'y';
	pNode = head;
	while((flag == 'y') || flag == ('Y'))
	{
		while(pNode->next && ListBegin < sort - 1)
		{
		pNode = pNode->next;
		++ListBegin;
		}
		if(!(pNode->next) || ListBegin > sort - 1)
		{
		printf("删除失败！\n");
		exit(-1);
		}
		data = pNode->next->data;
		qNode = pNode->next;
		pNode->next = pNode->next->next;	
		free(qNode);
		printf("删除成功！\n");
		getchar();
		printf("继续删除？(y/n):\n");
		scanf("%c", &flag);
	}
}

/////////查询通讯录中的数据/////////
DataType GetElemList(LinkList head,int sort)
{
	LinkList pNode;
	DataType data;
	int Count = 1;
	pNode = head->next;
	
	while(pNode && Count < sort)
	{
		pNode = pNode->next;
		++Count;
	}
	if(pNode == NULL || Count > sort)
	{
		printf("查询失败！\n");
		exit(-1);
	}
	data = pNode->data;
	
	return data;
}

/////////输出通讯录中的数据/////////
void PrintList(LinkList head)
{
    LinkList pNode;
	pNode = head->next;
	if(pNode == NULL)
	{
		printf("通讯录为空没有数据！");
		return;
	}
	printf("----------------------------------------------------------------------------\n");
	printf("学号\t\t姓名\t\t性别\t\t联系电话\tQQ号\n");
	printf("----------------------------------------------------------------------------\n");
	while(pNode != NULL)
	{
		if(pNode->data.sex)
		{	
			printf("%s\t\t%s\t\t男\t\t%s\t\t%s\n", pNode->data.xuehao,pNode->data.name,pNode->data.tel, pNode->data.qq);
		}
		else 
		{    
			printf("%s\t\t%s\t\t女\t\t%s\t\t%s\n", pNode->data.xuehao,pNode->data.name,pNode->data.tel, pNode->data.qq);
		}   
		printf("----------------------------------------------------------------------------\n");
        pNode = pNode->next;
	}

}
int main(int argc, char* argv[])
{
	LinkList  head;
	DataType  data;
	char flag = 'y';
	int choice;
	int sort;
	do
	{
		printf("     通讯录管理系统\n");
		printf("======================================\n");
		printf("               0:退出\n");
		printf("               1:建立通讯录\n");
		printf("               2:插入\n");
		printf("               3:删除\n");
		printf("               4:查询\n");
		printf("               5:输出\n");
		printf("======================================\n");
		printf("请选择0-5\n");
		scanf("%d",&choice);
		while(choice<0||choice>5)
		{
			printf("输入错误，请重新输入:");
			scanf("%d",&choice);
		}
		switch(choice)
		{
			case 0:
				exit(1);
			case 1:
				head=CreatList();
				break;
			case 2:
				printf("请输入要插入元素的位置：");
				scanf("%d", &sort);
				InsertLinkList(head, sort);
				break;
			case 3:
				printf("请输入要删除元素的位置：");
				scanf("%d", &sort);
				DeleteElemLinkList(head,sort);
				break;
			case 4:
				printf("请输入要查找元素的位置：");
				scanf("%d", &sort);
				printf("----------------------------------------------------------------------------\n");
				printf("学号\t\t姓名\t\t性别\t\t联系电话\tQQ号\n");
				printf("----------------------------------------------------------------------------\n");
				while((flag == 'y') || flag == ('Y'))
				{
				
					data = GetElemList(head,sort);
					
					if(data.sex)
					{	
						printf("%s\t\t%s\t\t男\t\t%s\t\t%s\n", data.xuehao,data.name,data.tel, data.qq);
					}
					else 
					{    
						printf("%s\t\t%s\t\t女\t\t%s\t\t%s\n", data.xuehao,data.name,data.tel, data.qq);
					}  
					printf("----------------------------------------------------------------------------\n");
					getchar();
					printf("继续查询？(y/n):\n");
					scanf("%c", &flag);
				}
				break;
			case 5:
				PrintList(head);
				break;
			default :
				exit(0);
		}

	}while(choice);
	return 0;
}

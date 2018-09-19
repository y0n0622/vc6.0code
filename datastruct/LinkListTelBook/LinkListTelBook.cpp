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
	char xuehao[14];//ѧ��
	char name[20];  //����
	int sex;        //�Ա�
	char tel[14];  //��ϵ�绰
	char qq[12];   //QQ��

}DataType;

typedef struct node
{
	DataType data;
	node *next;
}ListNode, *LinkList;

/////////����ͨѶ¼/////////
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
			printf("����ʧ�ܣ�\n");
			exit(-1);
		}
		printf("����������(ѧ��  ����  �Ա�0��1�� ��ϵ�绰  QQ��)��\n");
		scanf("%s%s%d%s%s", &pNode->data.xuehao, &pNode->data.name, &pNode->data.sex, &pNode->data.tel, &pNode->data.qq);
		pNode->next = head->next;
		head->next = pNode;
		printf("�����ɹ���\n");
		getchar();
		printf("�Ƿ�������룿��y/n��:\n");
		scanf("%c", &flag);
	}
	return head;
}

/////////��ͨѶ¼�в�������/////////
void InsertLinkList(LinkList head,int sort)
{
	LinkList p; //�α�
	LinkList pNode;//�½ڵ�
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
			printf("����ʧ�ܣ�\n");
			exit(-1);
		}
		pNode = (ListNode *)malloc(sizeof(ListNode));  //�½ڵ�
		if(!pNode)
		{
			printf("����ʧ�ܣ�\n");
			exit(-1);
		}
		printf("����������(ѧ��  ����  �Ա�0��1�� ��ϵ�绰  QQ��)��\n");
		scanf("%s%s%d%s%s", &pNode->data.xuehao, &pNode->data.name, &pNode->data.sex, &pNode->data.tel, &pNode->data.qq);
		pNode->next = p->next; 
		p->next = pNode;
		printf("����ɹ���\n");
		getchar();
		printf("�������룿��y/n��:\n");
		scanf("%c", &flag);
	}
}

/////////ɾ��ͨѶ¼�е�����/////////
void DeleteElemLinkList(LinkList head, int sort)
{ 
	LinkList pNode; //�α�
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
		printf("ɾ��ʧ�ܣ�\n");
		exit(-1);
		}
		data = pNode->next->data;
		qNode = pNode->next;
		pNode->next = pNode->next->next;	
		free(qNode);
		printf("ɾ���ɹ���\n");
		getchar();
		printf("����ɾ����(y/n):\n");
		scanf("%c", &flag);
	}
}

/////////��ѯͨѶ¼�е�����/////////
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
		printf("��ѯʧ�ܣ�\n");
		exit(-1);
	}
	data = pNode->data;
	
	return data;
}

/////////���ͨѶ¼�е�����/////////
void PrintList(LinkList head)
{
    LinkList pNode;
	pNode = head->next;
	if(pNode == NULL)
	{
		printf("ͨѶ¼Ϊ��û�����ݣ�");
		return;
	}
	printf("----------------------------------------------------------------------------\n");
	printf("ѧ��\t\t����\t\t�Ա�\t\t��ϵ�绰\tQQ��\n");
	printf("----------------------------------------------------------------------------\n");
	while(pNode != NULL)
	{
		if(pNode->data.sex)
		{	
			printf("%s\t\t%s\t\t��\t\t%s\t\t%s\n", pNode->data.xuehao,pNode->data.name,pNode->data.tel, pNode->data.qq);
		}
		else 
		{    
			printf("%s\t\t%s\t\tŮ\t\t%s\t\t%s\n", pNode->data.xuehao,pNode->data.name,pNode->data.tel, pNode->data.qq);
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
		printf("     ͨѶ¼����ϵͳ\n");
		printf("======================================\n");
		printf("               0:�˳�\n");
		printf("               1:����ͨѶ¼\n");
		printf("               2:����\n");
		printf("               3:ɾ��\n");
		printf("               4:��ѯ\n");
		printf("               5:���\n");
		printf("======================================\n");
		printf("��ѡ��0-5\n");
		scanf("%d",&choice);
		while(choice<0||choice>5)
		{
			printf("�����������������:");
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
				printf("������Ҫ����Ԫ�ص�λ�ã�");
				scanf("%d", &sort);
				InsertLinkList(head, sort);
				break;
			case 3:
				printf("������Ҫɾ��Ԫ�ص�λ�ã�");
				scanf("%d", &sort);
				DeleteElemLinkList(head,sort);
				break;
			case 4:
				printf("������Ҫ����Ԫ�ص�λ�ã�");
				scanf("%d", &sort);
				printf("----------------------------------------------------------------------------\n");
				printf("ѧ��\t\t����\t\t�Ա�\t\t��ϵ�绰\tQQ��\n");
				printf("----------------------------------------------------------------------------\n");
				while((flag == 'y') || flag == ('Y'))
				{
				
					data = GetElemList(head,sort);
					
					if(data.sex)
					{	
						printf("%s\t\t%s\t\t��\t\t%s\t\t%s\n", data.xuehao,data.name,data.tel, data.qq);
					}
					else 
					{    
						printf("%s\t\t%s\t\tŮ\t\t%s\t\t%s\n", data.xuehao,data.name,data.tel, data.qq);
					}  
					printf("----------------------------------------------------------------------------\n");
					getchar();
					printf("������ѯ��(y/n):\n");
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

// SqListTelBook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory.h>
//#define LIST_INIT_SIZE 50
#define MAX_SIZE 10

///////�������ݽṹ///////
typedef struct
{
		char xuehao[14];//ѧ��
		char name[20];  //����
		int sex;        //�Ա�
		char tel[15];  //��ϵ�绰
		char qq[12];   //QQ��

}DataType;

typedef struct
{
	DataType data[MAX_SIZE]; //������
	int length; //˳�����
	int listsize; //˳����С
}SqList;

///////��ʼ��˳���///////
SqList* InitSqList()
{
	//SqList* L;
	char flag;
	int i,n;
	SqList *p;
	p = (SqList*)malloc(sizeof(SqList));
	memset(p->data, 0, sizeof(SqList));
	
	p->length = 0;
	p->listsize = sizeof(SqList);//LIST_INIT_SIZE;

	//���˽�����һ�ձ��������������ڳ�ʼ��ʱ��¼������
	printf("�Ƿ������ʼ���ݣ���Y/N��");
	scanf("%c",&flag);
	if(flag=='N'||flag=='n')    return 0;
	printf("�������ʼ�����ݵĸ���:");
	scanf("%d",&n);
	if(n>p->listsize)
    {
		printf("����̫�࣬�����Դ洢��");
		return 0;
	}
	//p=L.elem;
	p->length=n;
	for(i=0;i<n;i++)
	{
		printf("�������%d������(ѧ��  ����  �Ա�0��1�� ��ϵ�绰  QQ��)��\n",i+1);
		scanf("%s%s%d%s%s", &p->data[i].xuehao, &p->data[i].name, &p->data[i].sex, &p->data[i].tel, &p->data[i].qq);
	}
	//L=p;
	return p;
}

///////��ӡ˳���///////
void  PrintSqList(SqList *L)
{
	int i;
	printf("----------------------------------------------------------------------------\n");
	printf("ѧ��\t\t����\t\t�Ա�\t\t��ϵ�绰\tQQ��\n");
	printf("----------------------------------------------------------------------------\n");
	for(i = 0; i < L->length; i++)
	{
		if(L->data[i].sex)
		{	
			printf("%s\t\t%s\t\t��\t\t%s\t\t%s\n", L->data[i].xuehao,L->data[i].name,L->data[i].tel, L->data[i].qq);
		}
		else 
		{    
			printf("%s\t\t%s\t\tŮ\t\t%s\t\t%s\n", L->data[i].xuehao,L->data[i].name,L->data[i].tel,L->data[i].qq);
		}                                                              
		printf("----------------------------------------------------------------------------\n");
	}
	
}

///////��˳����в�������///////
SqList* InsertSqList(SqList *L,int i)
{
	DataType *q, *p;
	DataType e;

	printf("����������(ѧ��  ����  �Ա�0��1�� ��ϵ�绰  QQ��)��\n");
	scanf("%s%s%d%s%s", &e.xuehao, &e.name, &e.sex, &e.tel, &e.qq);
	if(L->length+1>L->listsize)
	{
		printf("������ʧ�ܣ�");
		return 0;
	}
	if(i < 1 || i > L->length + 1)
	{
		printf("����λ�ô���ʧ�ܣ�");
		return 0;
	}
	
	q = &(L->data[i-1]);
	for(p = &(L->data[L->length - 1]); p >= q; --p)
	{
		*(p + 1) = *p;
	}
	*q = e;
	L->length++;
                     
	return L;
}

///////ɾ��˳����е�Ԫ��///////
int DeleteList(SqList *L,int i)
{
	DataType *p, *q;
	DataType e;
	if(i<1||i>L->length+1)
	{
		printf("������Χɾ��ʧ�ܣ�");
		return 0;
	}
	p = &(L->data[i - 1]);
	e = *p;
	q = L->data + L->length - 1;
	for(++p; p <= q; ++p)
	{
		*(p - 1) = *p;
	}
	--L->length;
	return 1;
}

///////��ѯ˳����е�����///////
int LocateList(SqList *L,char name[])
{
	int i = 0;

	while(i < L->length && strcmp(L->data[i].name, name))
		i++;
	if(i < L->length)
	{
		printf("��ѯ�ɹ���\n");
		printf("----------------------------------------------------------------------------\n");
		printf("ѧ��\t\t����\t\t�Ա�\t\t��ϵ�绰\tQQ��\n");
		if(L->data[i].sex)
		{	
			printf("%s\t\t%s\t\t��\t\t%s\t\t%s\n", L->data[i].xuehao,L->data[i].name,L->data[i].tel, L->data[i].qq);
		}
		else 
		{    
			printf("%s\t\t%s\t\tŮ\t\t%s\t\t%s\n", L->data[i].xuehao,L->data[i].name,L->data[i].tel,L->data[i].qq);
		}  
		printf("----------------------------------------------------------------------------\n");
		return i+1;
	}
	else
	{
		printf("δ�ҵ����ݣ�\n");
	}
	return 0;

}

int main(int argc, char* argv[])
{
	SqList *L;
	int sort;
	char name[20];
	printf("==========˳���ͨѶ¼==========\n");
	L=InitSqList();
	PrintSqList(L);
	printf("������Ҫ����Ԫ�ص�λ�ã�");
	scanf("%d", &sort);
	L=InsertSqList(L, sort);
	PrintSqList(L);
	printf("������Ҫɾ��Ԫ�ص�λ�ã�");
	scanf("%d", &sort);
	if(DeleteList(L, sort))
	{
		printf("ɾ���ɹ���\n");
		PrintSqList(L);
	}
	printf("������Ҫ����Ԫ�ص����֣�");
	scanf("%s", &name);
	LocateList(L, name);
	getchar();
	return 0;
}

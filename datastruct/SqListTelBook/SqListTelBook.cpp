// SqListTelBook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory.h>
//#define LIST_INIT_SIZE 50
#define MAX_SIZE 10

///////定义数据结构///////
typedef struct
{
		char xuehao[14];//学号
		char name[20];  //姓名
		int sex;        //性别
		char tel[15];  //联系电话
		char qq[12];   //QQ号

}DataType;

typedef struct
{
	DataType data[MAX_SIZE]; //数据域
	int length; //顺序表长度
	int listsize; //顺序表大小
}SqList;

///////初始化顺序表///////
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

	//至此建好了一空表，下面代码是完成在初始化时能录入数据
	printf("是否输入初始数据？（Y/N）");
	scanf("%c",&flag);
	if(flag=='N'||flag=='n')    return 0;
	printf("请输入初始化数据的个数:");
	scanf("%d",&n);
	if(n>p->listsize)
    {
		printf("数据太多，不足以存储！");
		return 0;
	}
	//p=L.elem;
	p->length=n;
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个数据(学号  姓名  性别（0或1） 联系电话  QQ号)：\n",i+1);
		scanf("%s%s%d%s%s", &p->data[i].xuehao, &p->data[i].name, &p->data[i].sex, &p->data[i].tel, &p->data[i].qq);
	}
	//L=p;
	return p;
}

///////打印顺序表///////
void  PrintSqList(SqList *L)
{
	int i;
	printf("----------------------------------------------------------------------------\n");
	printf("学号\t\t姓名\t\t性别\t\t联系电话\tQQ号\n");
	printf("----------------------------------------------------------------------------\n");
	for(i = 0; i < L->length; i++)
	{
		if(L->data[i].sex)
		{	
			printf("%s\t\t%s\t\t男\t\t%s\t\t%s\n", L->data[i].xuehao,L->data[i].name,L->data[i].tel, L->data[i].qq);
		}
		else 
		{    
			printf("%s\t\t%s\t\t女\t\t%s\t\t%s\n", L->data[i].xuehao,L->data[i].name,L->data[i].tel,L->data[i].qq);
		}                                                              
		printf("----------------------------------------------------------------------------\n");
	}
	
}

///////在顺序表中插入数据///////
SqList* InsertSqList(SqList *L,int i)
{
	DataType *q, *p;
	DataType e;

	printf("请输入数据(学号  姓名  性别（0或1） 联系电话  QQ号)：\n");
	scanf("%s%s%d%s%s", &e.xuehao, &e.name, &e.sex, &e.tel, &e.qq);
	if(L->length+1>L->listsize)
	{
		printf("表满，失败！");
		return 0;
	}
	if(i < 1 || i > L->length + 1)
	{
		printf("插入位置错误，失败！");
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

///////删除顺序表中的元素///////
int DeleteList(SqList *L,int i)
{
	DataType *p, *q;
	DataType e;
	if(i<1||i>L->length+1)
	{
		printf("超出范围删除失败！");
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

///////查询顺序表中的数据///////
int LocateList(SqList *L,char name[])
{
	int i = 0;

	while(i < L->length && strcmp(L->data[i].name, name))
		i++;
	if(i < L->length)
	{
		printf("查询成功！\n");
		printf("----------------------------------------------------------------------------\n");
		printf("学号\t\t姓名\t\t性别\t\t联系电话\tQQ号\n");
		if(L->data[i].sex)
		{	
			printf("%s\t\t%s\t\t男\t\t%s\t\t%s\n", L->data[i].xuehao,L->data[i].name,L->data[i].tel, L->data[i].qq);
		}
		else 
		{    
			printf("%s\t\t%s\t\t女\t\t%s\t\t%s\n", L->data[i].xuehao,L->data[i].name,L->data[i].tel,L->data[i].qq);
		}  
		printf("----------------------------------------------------------------------------\n");
		return i+1;
	}
	else
	{
		printf("未找到数据！\n");
	}
	return 0;

}

int main(int argc, char* argv[])
{
	SqList *L;
	int sort;
	char name[20];
	printf("==========顺序表通讯录==========\n");
	L=InitSqList();
	PrintSqList(L);
	printf("请输入要插入元素的位置：");
	scanf("%d", &sort);
	L=InsertSqList(L, sort);
	PrintSqList(L);
	printf("请输入要删除元素的位置：");
	scanf("%d", &sort);
	if(DeleteList(L, sort))
	{
		printf("删除成功！\n");
		PrintSqList(L);
	}
	printf("请输入要查找元素的名字：");
	scanf("%s", &name);
	LocateList(L, name);
	getchar();
	return 0;
}

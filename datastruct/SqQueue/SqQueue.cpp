// SqQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
# define MAXQSIZE 100
# define OK 1
# define ERROR 0

typedef char QElemType;
typedef struct
{
	QElemType *base;
	int front;
	int rear;
}SqQueue; 

/* �����˳�����*/
int InitQueue(SqQueue &Q)	//InitQueue() sub-function
{
	Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if(!Q.base)
	{
		printf("�����ڴ�ʧ�ܣ�\n");
		exit(0);
	}
	Q.rear = 0;
	Q.front = Q.rear;
    return (OK);
}

/* ��˳����г���*/
int QueueLength(SqQueue Q)  	
{
    return  (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

/*��˳�����β������Ԫ��*/
int EnQueue(SqQueue &Q,QElemType e)	
{  
	if((Q.rear +1) % MAXQSIZE == Q.front)
    {
		printf("��������! \n");
	    return (ERROR);
    }
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
    return (OK);
}

/*��˳�����ͷɾ��Ԫ��*/
SqQueue DeQueue(SqQueue &Q,QElemType &e)	
{
	if(Q.front == Q.rear)
	{
		printf("����Ϊ�գ�");
		exit(0);
	}
	e = Q.base[Q.front];

	Q.front = (Q.front + 1) % MAXQSIZE;
	
    return Q;
} 

/*��ʾ˳���������Ԫ��*/
void display(SqQueue Q)
{
	if(Q.rear - Q.front == 0)
	{
		printf("�ӿգ�");
	}
	else
	{
		while(Q.front != Q.rear)
		{
			printf("%c\n", Q.base[Q.front]);
			Q.front++;
		}
	}
}

int main(int argc, char* argv[])
{
	QElemType e;
	int choice;
	SqQueue  Q;
	                                 
	printf("==============================\n");
	printf("0���˳�\n");
	printf("1�����\n");
	printf("2������\n");
	printf("3����ʾ����Ԫ��\n");
	printf("4����ʾ���г���\n");
	printf("==============================\n");
	InitQueue(Q);
	memset(Q.base, 0, MAXQSIZE * sizeof(QElemType));
	do
	{
		printf("�����ѡ����(0-3):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				fflush(stdin);//������뻺����
				e = 0;
				printf("������Ҫ��ӵ��ַ����ַ���,��'#'����:");
				while(e != '#')
				{
					scanf("%c", &e);
					if(e != '#')
					EnQueue(Q, e); 	                                             
				}
				 
				break;
			case 2:	
				Q = DeQueue(Q, e);
				printf("���ӵ��ַ���:");
				if(e != NULL)
				{
					printf("%c\n",e);
				}
				else 
				{
					printf("�ӿա�\n");
				}
				break;
			case 3:
				display(Q);
				break;
			case 4:
				printf("����Ϊ:%d\n", QueueLength(Q));
				break;
		}
	}while(choice>0&&choice<=4);
	return 0;
}

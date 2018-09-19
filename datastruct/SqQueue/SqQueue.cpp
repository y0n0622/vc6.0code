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

/* 构造空顺序队列*/
int InitQueue(SqQueue &Q)	//InitQueue() sub-function
{
	Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if(!Q.base)
	{
		printf("分配内存失败！\n");
		exit(0);
	}
	Q.rear = 0;
	Q.front = Q.rear;
    return (OK);
}

/* 求顺序队列长度*/
int QueueLength(SqQueue Q)  	
{
    return  (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

/*在顺序队列尾插入新元素*/
int EnQueue(SqQueue &Q,QElemType e)	
{  
	if((Q.rear +1) % MAXQSIZE == Q.front)
    {
		printf("队列已满! \n");
	    return (ERROR);
    }
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
    return (OK);
}

/*在顺序队列头删除元素*/
SqQueue DeQueue(SqQueue &Q,QElemType &e)	
{
	if(Q.front == Q.rear)
	{
		printf("队列为空！");
		exit(0);
	}
	e = Q.base[Q.front];

	Q.front = (Q.front + 1) % MAXQSIZE;
	
    return Q;
} 

/*显示顺序队列所有元素*/
void display(SqQueue Q)
{
	if(Q.rear - Q.front == 0)
	{
		printf("队空！");
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
	printf("0、退出\n");
	printf("1、入队\n");
	printf("2、出队\n");
	printf("3、显示队列元素\n");
	printf("4、显示队列长度\n");
	printf("==============================\n");
	InitQueue(Q);
	memset(Q.base, 0, MAXQSIZE * sizeof(QElemType));
	do
	{
		printf("你操作选择是(0-3):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				fflush(stdin);//清除输入缓冲区
				e = 0;
				printf("请输入要入队的字符或字符串,以'#'结束:");
				while(e != '#')
				{
					scanf("%c", &e);
					if(e != '#')
					EnQueue(Q, e); 	                                             
				}
				 
				break;
			case 2:	
				Q = DeQueue(Q, e);
				printf("出队的字符是:");
				if(e != NULL)
				{
					printf("%c\n",e);
				}
				else 
				{
					printf("队空。\n");
				}
				break;
			case 3:
				display(Q);
				break;
			case 4:
				printf("长度为:%d\n", QueueLength(Q));
				break;
		}
	}while(choice>0&&choice<=4);
	return 0;
}

// SqStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


///////���ݶ���
#define  STACK_INIT_SIZE   100
#define  STACKINCREMENT   10

typedef char SElemType;

typedef struct
{        
     SElemType *base;  //ջ��
	 SElemType *top;   //ջ��
	 int stacksize;    //��ǰ�洢�ռ�                                                              
}SqStack;

////////˳��ջ�ĳ�ʼ��////////
SqStack* InitStack(SqStack *S)	
{
	
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));                               
    if(!S->base)
    {
		printf("����ռ�ʧ��!\n");
		exit(0);
    }
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    printf("ջ��ʼ���ɹ���\n");
    return S;                 
}

////////��ջ////////
int Push(SqStack *S)	
{ 
	bool flag = true;
	int num = 0;
	SElemType e = NULL;
	while(flag)
	{
	if(S->top - S->base >= S->stacksize)//ջ��
    {
		S = (SqStack *)realloc(S, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S->base)
		{   
			printf("�洢�ռ����ʧ��!\n");
			exit(0);
		}
	    S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
    }
	fflush(stdin);//������뻺����������ԭ���������Ĭ���͸�����x
	printf("������Ҫ��ջ��Ԫ�ص�ֵ:");

		scanf("%c", &e);
		*S->top = e;
		S->top++;
		printf("��ջ�ɹ���\n");
		printf("�Ƿ�������룿(����1����0,1��ʾ����)"); 
		scanf("%d", &num);
		if(num)
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
	}
	
    return 0;
} 

////////��ջ////////
SElemType Pop(SqStack *S)	
{ 
	SElemType e = NULL;
	if(S->top == S->base)//ջ��
	{
		printf("ջ��!\n");
		exit(0);
	}
	e = *--S->top;
	printf("��ջ�ɹ���\n");
	return e;

} 

////////���Ԫ�ص�ֵ////////
SElemType GetTop(SqStack *S)	//GetTop() sub-function
{   
	SElemType e = NULL;
	SElemType *p;
	p = S->top;
	if(p == S->base)
	{
		printf("ջ�գ�\n");
		exit(0);
	}
	e = *(p - 1);
	return e;
} //GetTop() end

/////////��ʾջ��Ԫ��//////////
void display(SqStack *S)
{
	SElemType *p;
	p = S->top;
	while(S->base != p)
	{
		printf("%c ",*(p - 1));
		p--;
	}
	printf("\n");
}


int main(int argc, char* argv[])
{
	int choice;
	SElemType e;
	SqStack *S;
	S = (SqStack *)malloc(sizeof(SqStack));
	do
	{
		printf("===============================\n");
		printf("           0:�˳�\n");
		printf("           1:��ʼ��ջ\n");
		printf("           2:��ջ\n");
		printf("           3:��ջ\n");
		printf("           4:��ȡջ��Ԫ��\n");
        printf("           5:��ʾջ��Ԫ��\n");
		printf("===============================\n");
		printf("�������ѡ�����(0-5):");
		scanf("%d",&choice);
		while(choice<0||choice>5)
		{
			printf("������������������(0-5):");
			scanf("%d",&choice);
		}
		switch(choice)
		{
			case 0:exit(1);
			case 1:
				S = InitStack(S);
				break;
			case 2:
				printf("2\n");
				Push(S);
				break;
			case 3:
			    e = Pop(S);
				printf("��ջԪ�ص�ֵ��:%c\n",e);
				break;
			case 4:
				e = GetTop(S);
				printf("ջ��Ԫ�ص�ֵ��:%c\n",e);
				break;
            case 5:
				printf("ջ��Ԫ�ص�ֵ��Ϊ��\n");
				display(S);
				break;
		}

	}while(choice);
    return 0;

}

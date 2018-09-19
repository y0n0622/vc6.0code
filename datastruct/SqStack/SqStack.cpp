// SqStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


///////数据定义
#define  STACK_INIT_SIZE   100
#define  STACKINCREMENT   10

typedef char SElemType;

typedef struct
{        
     SElemType *base;  //栈底
	 SElemType *top;   //栈顶
	 int stacksize;    //当前存储空间                                                              
}SqStack;

////////顺序栈的初始化////////
SqStack* InitStack(SqStack *S)	
{
	
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));                               
    if(!S->base)
    {
		printf("分配空间失败!\n");
		exit(0);
    }
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    printf("栈初始化成功！\n");
    return S;                 
}

////////入栈////////
int Push(SqStack *S)	
{ 
	bool flag = true;
	int num = 0;
	SElemType e = NULL;
	while(flag)
	{
	if(S->top - S->base >= S->stacksize)//栈满
    {
		S = (SqStack *)realloc(S, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S->base)
		{   
			printf("存储空间分配失败!\n");
			exit(0);
		}
	    S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
    }
	fflush(stdin);//清除输入缓冲区，否则原来的输入会默认送给变量x
	printf("请输入要入栈的元素的值:");

		scanf("%c", &e);
		*S->top = e;
		S->top++;
		printf("入栈成功！\n");
		printf("是否继续输入？(输入1或者0,1表示继续)"); 
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

////////出栈////////
SElemType Pop(SqStack *S)	
{ 
	SElemType e = NULL;
	if(S->top == S->base)//栈空
	{
		printf("栈空!\n");
		exit(0);
	}
	e = *--S->top;
	printf("出栈成功！\n");
	return e;

} 

////////获得元素的值////////
SElemType GetTop(SqStack *S)	//GetTop() sub-function
{   
	SElemType e = NULL;
	SElemType *p;
	p = S->top;
	if(p == S->base)
	{
		printf("栈空！\n");
		exit(0);
	}
	e = *(p - 1);
	return e;
} //GetTop() end

/////////显示栈中元素//////////
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
		printf("           0:退出\n");
		printf("           1:初始化栈\n");
		printf("           2:入栈\n");
		printf("           3:出栈\n");
		printf("           4:读取栈顶元素\n");
        printf("           5:显示栈中元素\n");
		printf("===============================\n");
		printf("输入操作选择代码(0-5):");
		scanf("%d",&choice);
		while(choice<0||choice>5)
		{
			printf("输入有误，请重新输入(0-5):");
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
				printf("出栈元素的值是:%c\n",e);
				break;
			case 4:
				e = GetTop(S);
				printf("栈顶元素的值是:%c\n",e);
				break;
            case 5:
				printf("栈中元素的值是为：\n");
				display(S);
				break;
		}

	}while(choice);
    return 0;

}

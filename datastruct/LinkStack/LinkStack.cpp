// LinkStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

///////////数据结构定义///////////
typedef char SElemType;

typedef struct SNode		
{
	SElemType elem[20];
	SNode *next;                             
}SNode,*LinkStack;

///////////链栈初始化///////////
LinkStack InitStack_L ()
{
	LinkStack top;
	top = (LinkStack)malloc(sizeof(SNode));
	memset(top->elem, 0, sizeof(SElemType));
	//top->elem = (SElemType *)malloc(sizeof(SElemType));
	top->next = NULL;
	printf("\n栈初始化成功！\n");
	return top;
}

///////////将元素入链栈///////////
LinkStack Push_L(LinkStack top)	//Push_L() sub-function
{ 
	LinkStack q;
    q = (LinkStack)malloc(sizeof(SNode));                                  
    if(!q)
    {   printf("存储空间分配失败! \n");
	    exit(0);
    }
    fflush(stdin);//清除输入缓冲区，否则原来的输入会默认送给变量e
	printf("\n请输入要入栈的元素的值:");
	scanf("%s", q->elem);
	q->next = top;                          
    top = q;                             
    printf("入链栈成功！\n");                                                                                   
    return top;
}

///////////将元素弹出链式栈///////////
LinkStack Pop_L(LinkStack top)	//Pop_L() sub-function
{
	LinkStack p;
	if(NULL == (*top->elem))
	{
		printf("栈已空！\n");
		exit(0);
	}
	p = top;
	top = p->next;
	int i = 0;
	printf("出栈的元素的值是: ");
	while(p->elem[i] != '\0')
	{
		printf("%c", p->elem[i]);
		i++;
	}
	printf("\n");
	free(p);
	return top;
}

///////////取链式栈顶元素///////////
int GetTop_L(LinkStack top) 
{  
	if(NULL == top->elem)
	{
		printf("栈已空！\n");
		exit(0);
	}
	int i = 0;
	printf("栈顶元素的值是:");
	while(top->elem[i] != '\0')
	{
		printf("%c", top->elem[i]);
		i++;
	}
	printf("\n");
//	e = top->elem;
	return 0;
} //GetTop_L() end

///////////显示栈中所有元素///////////
void display(LinkStack top)
{
	LinkStack p;
	p = top;
	if(NULL == p)
	{
		printf("栈已空！\n");
		exit(0);
	}
	while(NULL != p)
	{
		printf("%s ", p->elem);
		p = p->next;
	}
	printf("\n");
}


int main(int argc, char* argv[])
{
	char choice;
	int i = 0;
	LinkStack s;
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
		fflush(stdin);
		scanf("%c",&choice);
		while(choice<'0'||choice>'5') 
		{
			printf("输入有误，请重新输入(0-5):");
			fflush(stdin);
			scanf("%c",&choice);
		}
		switch(choice)
		{
			case '0':exit(1);
			case '1':
				s = InitStack_L();
				break;
			case '2':
				s = Push_L(s);
				break;
			case '3':
				s = Pop_L(s);
				break;
			case '4':
				GetTop_L(s);
				
			break;
         case '5':
			 printf("栈中元素的值是: ");
			 display(s);
		}
	}while(choice);
return 0;

}

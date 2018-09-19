// LinkStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

///////////���ݽṹ����///////////
typedef char SElemType;

typedef struct SNode		
{
	SElemType elem[20];
	SNode *next;                             
}SNode,*LinkStack;

///////////��ջ��ʼ��///////////
LinkStack InitStack_L ()
{
	LinkStack top;
	top = (LinkStack)malloc(sizeof(SNode));
	memset(top->elem, 0, sizeof(SElemType));
	//top->elem = (SElemType *)malloc(sizeof(SElemType));
	top->next = NULL;
	printf("\nջ��ʼ���ɹ���\n");
	return top;
}

///////////��Ԫ������ջ///////////
LinkStack Push_L(LinkStack top)	//Push_L() sub-function
{ 
	LinkStack q;
    q = (LinkStack)malloc(sizeof(SNode));                                  
    if(!q)
    {   printf("�洢�ռ����ʧ��! \n");
	    exit(0);
    }
    fflush(stdin);//������뻺����������ԭ���������Ĭ���͸�����e
	printf("\n������Ҫ��ջ��Ԫ�ص�ֵ:");
	scanf("%s", q->elem);
	q->next = top;                          
    top = q;                             
    printf("����ջ�ɹ���\n");                                                                                   
    return top;
}

///////////��Ԫ�ص�����ʽջ///////////
LinkStack Pop_L(LinkStack top)	//Pop_L() sub-function
{
	LinkStack p;
	if(NULL == (*top->elem))
	{
		printf("ջ�ѿգ�\n");
		exit(0);
	}
	p = top;
	top = p->next;
	int i = 0;
	printf("��ջ��Ԫ�ص�ֵ��: ");
	while(p->elem[i] != '\0')
	{
		printf("%c", p->elem[i]);
		i++;
	}
	printf("\n");
	free(p);
	return top;
}

///////////ȡ��ʽջ��Ԫ��///////////
int GetTop_L(LinkStack top) 
{  
	if(NULL == top->elem)
	{
		printf("ջ�ѿգ�\n");
		exit(0);
	}
	int i = 0;
	printf("ջ��Ԫ�ص�ֵ��:");
	while(top->elem[i] != '\0')
	{
		printf("%c", top->elem[i]);
		i++;
	}
	printf("\n");
//	e = top->elem;
	return 0;
} //GetTop_L() end

///////////��ʾջ������Ԫ��///////////
void display(LinkStack top)
{
	LinkStack p;
	p = top;
	if(NULL == p)
	{
		printf("ջ�ѿգ�\n");
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
		printf("           0:�˳�\n");
		printf("           1:��ʼ��ջ\n");
		printf("           2:��ջ\n");
		printf("           3:��ջ\n");
		printf("           4:��ȡջ��Ԫ��\n");
		printf("           5:��ʾջ��Ԫ��\n");
		printf("===============================\n");
		printf("�������ѡ�����(0-5):");
		fflush(stdin);
		scanf("%c",&choice);
		while(choice<'0'||choice>'5') 
		{
			printf("������������������(0-5):");
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
			 printf("ջ��Ԫ�ص�ֵ��: ");
			 display(s);
		}
	}while(choice);
return 0;

}

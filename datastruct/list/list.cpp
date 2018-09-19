// list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//9-9-1
//#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct student)
struct student
{
	long num;
	float score;      
	struct student *next;
};

int n; 

int main()
{
	struct student *creat();
	struct student *del(struct student * ,long);
	struct student *insert(struct student *, struct student *);

	void print(struct student *);
	struct student *head,stu;
	long del_num;
	
	printf("input records:\n");
	head=creat();
	print(head);                     
	
	printf("input the deleted number:");
	scanf("%ld",&del_num); 
	head=del(head,del_num); 
	print(head);                
	
	printf("input the inserted record:");     
	scanf("%ld,%f",&stu.num,&stu.score);
	head=insert(head,&stu); 
	print(head);
	
	return 0;
}

struct student *creat()
{
	struct student *head;
	struct student *p1,*p2;
	n=0;
	p1=p2=( struct student*) malloc(LEN);
	scanf("%ld,%f",&p1->num,&p1->score);
	head=NULL;
	while(p1->num!=0)
	{
		n=n+1;
		if(n==1)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(struct student*)malloc(LEN);
		scanf("%ld,%f",&p1->num,&p1->score);
	}
	p2->next=NULL;
	return(head);
}

struct student *del(struct student *head,long num)
{
	struct student *p1,*p2;
	if (head==NULL)
	{
		printf("\nlist null!\n");
		return(head);
	}
	p1=head;
	while(num!=p1->num && p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
		if(num==p1->num)
		{
			if(p1==head)
				head=p1->next;
			else
				p2->next=p1->next;
			printf("delete:%ld\n",num);
			n=n-1;
		}
		else printf("%ld not been found!\n",num);    
		return(head);
}

struct student *insert(struct student *head, struct student *stud)
{
	struct student *p0,*p1,*p2;
	p1=head;
	p0=stud;               
	if(head==NULL) //head存在且没有元素，直接将p0中的元素插入
	{
		head=p0;
		p0->next=NULL;
	}  
	else
	{
		while((p0->num>p1->num) && (p1->next!=NULL))//执行循环条件，当插入的元素的num大于当前元素的num，且元素不是最后一个元素
		{
			p2=p1;     
			p1=p1->next;
		}          //循环查找插入的位置
	if(p0->num<=p1->num)
	{
		if(head==p1)
			head=p0; 
		else
			p2->next=p0;      
		p0->next=p1;//插入
	}
	else
	{
		p1->next=p0;
		p0->next=NULL;
	}//若为最后一个元素，则执行此语句
}
	n=n+1;                 
	return(head);
}

void print(struct student *head)
{
	struct student *p;
	printf("\nNow,These %d records are:\n",n);  
	p=head;
	if(head!=NULL)
	do	
	{
		printf("%ld %5.1f\n",p->num,p->score);
		p=p->next;
	}while(p!=NULL);
}



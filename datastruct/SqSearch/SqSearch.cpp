// SqSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()��
 #include<limits.h> // INT_MAX��
 //#include<stdio.h> // EOF(=^Z��F6),NULL
 #include<stdlib.h> // atoi()
 #include<io.h> // eof()
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #include<iostream.h> // cout,cin
 // �������״̬����
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 // #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������
 typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
 typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE
#define MAX_LENGTH 100
#include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()��
 #include<limits.h> // INT_MAX��
 //#include<stdio.h> // EOF(=^Z��F6),NULL
 #include<stdlib.h> // atoi()
 #include<io.h> // eof()
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #include<iostream.h> // cout,cin
 // �������״̬����
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 // #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������
 typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
 typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE 
#define N 5 // ����Ԫ�ظ���
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))
typedef long KeyType; // ��ؼ�����Ϊ������
 #define key number // ����ؼ���Ϊ׼��֤��
 struct ElemType // ����Ԫ������
 {
   long number; // ׼��֤�ţ���ؼ�������ͬ
   char name[9]; // ����(4�����ּ�1����������־)
   int politics; // ����
   int Chinese; // ����
   int English; // Ӣ��
   int math; // ��ѧ
   int physics; // ����
   int chemistry; // ��ѧ
   int biology; // ����
   int total; // �ܷ�
 };
//1�������Ǿ�̬���ұ�Ĵ洢�ṹ�Ķ��壬�벹��������
typedef struct {
      ElemType *elem;       // ����Ԫ�ش洢�ռ��ַ
      int length;          // ����
 }SSTable;
//2�������ǹ�����ұ�ĺ����Ķ��壬����������ɺ�n������Ԫ�ص�����r���쾲̬˳����ұ�ST���벹��������
void Creat_Seq(SSTable &ST,ElemType r[],int n)
 { 
   int i;
    ST.elem = (ElemType *)malloc((n + 1) * sizeof(ElemType));             // ��̬����n+1������Ԫ�ؿռ�(0�ŵ�Ԫ����)
   if(!ST.elem)
     exit(ERROR);
   for(i=1;i<=n;i++)
     ST.elem[i] = r[i];                                // ������r��ֵ���θ���ST
   ST.length=n;
 }
//3�����溯���������ǣ��ؽ���̬���ұ�Ϊ���ؼ��ַǽ��������벹��������
 void Ascend(SSTable &ST)
 { 
   int i,j,k;
   for(i=1;i<ST.length;i++)
   {
     k=i;
     ST.elem[0] =  ST.elem[i];     // ���Ƚ�ֵ��[0]��Ԫ
     for(j=i+1;j<=ST.length;j++)
       if LT(ST.elem[j].key,ST.elem[0].key)
       {
         k=j;
         ST.elem[0]=ST.elem[j];
       }
     if LT(ST.elem[i].key, ST.elem[k].key) // �и�С��ֵ�򽻻�
     {
       ST.elem[k]=ST.elem[i];
       ST.elem[i]=ST.elem[0];
     }
   }
 }
//4�����溯���������ǣ��ɺ�n������Ԫ�ص�����r���찴�ؼ��ַǽ�����ұ�ST���벹��������
 void Creat_Ord(SSTable &ST,ElemType r[],int n)
 { 
       Creat_Seq(ST, r, n);    // ��������Ĳ��ұ�ST
        Ascend (ST);           // ������Ĳ��ұ�ST�ؽ�Ϊ���ؼ��ַǽ�����ұ�
 }
//5�����溯���������ǣ����پ�̬���ұ�ST���벹��������
 Status Destroy(SSTable &ST)
 { 
   free(ST.elem);                         
   ST.elem=NULL;
   ST.length=0;
   return OK;
 }
//6�����溯���������ǣ���˳���ST��˳�������ؼ��ֵ���key������Ԫ�ء����ҵ����򷵻ظ�Ԫ���ڱ��е�λ�ã����򷵻�0������ݺ���ͷ������������
 int Search_Seq(SSTable ST,KeyType key)
 {
	int i;
	ST.elem[0].key = key;
	for(i = ST.length; !EQ(ST.elem[i].key, key); --i);
	
	return i;
	
	

 }
//7�����к����������ǣ��������ST���۰������ؼ��ֵ���key������Ԫ�ء����ҵ����򷵻ظ�Ԫ���ڱ��е�λ�ã����򷵻�0������ݺ���ͷ������������
int Search_Bin(SSTable ST,KeyType key)
 { 
   int low = 1;
   int high = ST.length;
   int mid = 0;
   while(low <= high)
   {
	   mid = (low + high) / 2;
	   if(EQ(key, ST.elem[mid].key))
		   return mid;
	   else if(LT(key, ST.elem[mid].key))
	   {
		   high = mid - 1;
	   }
	   else
	   {
			low = mid + 1;
	   }
	  
   }
	return 0;
 }
//8�����溯���������ǣ���˳���ST��ÿ��Ԫ�ص��ú���Visit()һ���ҽ�һ�Σ��벹��������
void print(ElemType c) // Traverse()���õĺ���
 {
   printf("%-8ld%-8s%4d%5d%5d%5d%5d%5d%5d%5d\n",c.number,c.name,c.politics,
	   c.Chinese,c.English,c.math,c.physics,c.chemistry,c.biology,c.total);
 }
void Traverse(SSTable ST,void(*Visit)(ElemType))
 { 
   ElemType *p;
   int i;
   p = ST.elem;                           // pָ���һ��Ԫ��
   for(i=1;i<=ST.length;i++)
       print(*p++);                        
 }

//9��������˳��������������벹��������
int main(int argc, char* argv[])
{
   ElemType r[N]={{179328,"�η���",85,89,98,100,93,80,47},
   {179325,"�º�",85,86,88,100,92,90,45},
	{179326,"½��",78,75,90,80,95,88,37},
	{179327,"��ƽ",82,80,78,98,84,96,40},
	{179324,"��С��",76,85,94,57,77,69,44}}; // ���鲻���ؼ�������
   SSTable st;
   int i;
   long s;
   for(i=0;i<N;i++) // �����ܷ�
     r[i].total= r[i].biology + r[i].chemistry + r[i].Chinese + r[i].English + r[i].math + r[i].physics + r[i].politics;
       Creat_Ord(st, r, 5); // ������r����˳��̬���ұ�st
   printf("׼��֤��  ����  ���� ���� ���� ��ѧ ���� ��ѧ ���� �ܷ�\n");
   Traverse(st,print); // ��˳�������̬���ұ�st
   printf("������������˵Ŀ���: ");
   scanf("%ld",&s);
   i=    Search_Seq(st, s) ; // ˳�����
   if(i)
     print(st.elem[i]);
   else
     printf("û�ҵ�\n");
   Destroy(st);
	return 0;
}
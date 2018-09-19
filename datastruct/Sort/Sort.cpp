// Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()��
 #include<limits.h> // INT_MAX��
 #include<stdio.h> // EOF(=^Z��F6),NULL
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
 typedef int InfoType; // �������������������
 #define EQ(a,b) ((a)==(b))
 #define LT(a,b) ((a)<(b))
 #define LQ(a,b) ((a)<=(b)) 
#define MAX_SIZE 20 // һ������ʾ����С˳������󳤶�
 typedef int KeyType; // ����ؼ�������Ϊ����
//1��������˳�������Ͷ��壬�벹��������
 typedef struct // ��¼����
 {
   KeyType key; // �ؼ�����
   InfoType otherinfo; // ������������������������ж���
 }RedType;
 typedef struct // ˳�������
 {
      RedType r[MAX_SIZE + 1];                        // r[0]���û������ڱ���Ԫ
      int length;                     // ˳�����
 }SqList; 
//2��������ֱ�Ӳ��������㷨������ݺ���ͷ������������
void InsertSort(SqList &L)
 { // ��˳���L��ֱ�Ӳ�������
   int i = 0, j = 0;
	for(i = 2; i <= L.length; ++i)
	{
		if(LT(L.r[i].key, L.r[i - 1].key))
		{
			L.r[0] = L.r[i];
			L.r[i] = L.r[i-1];
			for(j = i - 2; LT(L.r[0].key, L.r[j].key); --j)
			{
				L.r[j + 1] = L.r[j];
			}
			L.r[j + 1] = L.r[0];
		}
	}
 }
//3���������۰������������ղ���������
 void BInsertSort(SqList &L)
 { // ��˳���L���۰��������
   int i,j,m,low,high;
   for( i = 2; i <= L.length; ++i                      )
   {
     L.r[0] = L.r[i]; // ��L.r[i]�ݴ浽L.r[0]
     low=1;
     high=i-1;
     while(  low <= high   )
     { // ��r[low..high]���۰������������λ��
       m = (low + high)/2;        // �۰�
       if LT(L.r[0].key,L.r[m].key)
           high = m - 1;                        // ������ڵͰ���
       else
           low = m + 1;                        // ������ڸ߰���
     }
     for( j = i - 1; j >= high + 1; --j )
        L.r[j + 1] = L.r[j];                          // ��¼����
     L.r[high + 1] = L.r[0];                          // ����
   }
 }
//4��������2_·���������㷨������ղ���������
 void P2_InsertSort(SqList &L)
 { // 2_·��������
   int i,j,first,final;
   RedType *d;
   d = (RedType*)malloc(L.length*sizeof(RedType));        // ����L.length����¼����ʱ�ռ�
    d[0] = L.r[1];     // ��L�ĵ�1����¼Ϊd���ź���ļ�¼(��λ��[0])
     first = final = 0;                     // first��final�ֱ�ָʾd���ź���ļ�¼�ĵ�1�������1����¼��λ��
   for( i = 2; i <= L.length; ++i   ) 
// ���ν�L�ĵ�2�������1����¼����d��
     if(L.r[i].key<d[first].key)
     { // �����¼С��d����Сֵ���嵽d[first]֮ǰ(�����ƶ�d�����Ԫ��)
       first = (first - 1 + L.length) % L.length;    // ��dΪѭ������
       d[first]=L.r[i];
     }
     else if(L.r[i].key>d[final].key)
     { // �����¼����d�����ֵ���嵽d[final]֮��(�����ƶ�d�����Ԫ��)
       final=final+1;
       d[final] = L.r[i];                                        
     }
     else
     { // �����¼����d����Сֵ��С��d�����ֵ���嵽d���м�(��Ҫ�ƶ�d�����Ԫ��)
        j = final++;   // �ƶ�d��β��Ԫ���Ա㰴������¼
       while(L.r[i].key<d[j].key)
       {
         d[(j+1)%L.length]=d[j];
         j=(j-1+L.length)%L.length;
       }
       d[j+1]=L.r[i];
     }
   for(i = 1; i <= L.length; i++) // ��d����L.r
         L.r[i] = d[(i+first-1)%L.length];                            // ���Թ�ϵ
 }
//5�����������˳����Ԫ�صĺ���������ݺ���ͷ������������
void print(SqList L)
{
	int i;
	for(i = 1; i <= L.length; i++)
	{
		printf("<%d, %d> ", L.r[i].key, L.r[i].otherinfo);
	}
	printf("\n");
 }
//6����������������
 #define N 8
 int main()
 {
   RedType d[N]={{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}};
   SqList l1,l2,l3;
   int i;
   for(i=0;i<N;i++) // ��l1.r��ֵ
     l1.r[i+1]=d[i];
   l1.length=N;
   l2=l3=l1; // ����˳���l2��l3��l1��ͬ
   printf("����ǰ:\n");
   print(l1);
   InsertSort(l1);
   printf("ֱ�Ӳ��������:\n");
   print(l1);
   BInsertSort(l2);
   printf("�۰���������:\n");
   print(l2);
   P2_InsertSort(l3);
   printf("2_·���������:\n");
   print(l3);
   return 0;
 }


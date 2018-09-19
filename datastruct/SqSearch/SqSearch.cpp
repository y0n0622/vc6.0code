// SqSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()等
 #include<limits.h> // INT_MAX等
 //#include<stdio.h> // EOF(=^Z或F6),NULL
 #include<stdlib.h> // atoi()
 #include<io.h> // eof()
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #include<iostream.h> // cout,cin
 // 函数结果状态代码
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 // #define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行
 typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
 typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE
#define MAX_LENGTH 100
#include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()等
 #include<limits.h> // INT_MAX等
 //#include<stdio.h> // EOF(=^Z或F6),NULL
 #include<stdlib.h> // atoi()
 #include<io.h> // eof()
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #include<iostream.h> // cout,cin
 // 函数结果状态代码
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 // #define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行
 typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
 typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE 
#define N 5 // 数据元素个数
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))
typedef long KeyType; // 设关键字域为长整型
 #define key number // 定义关键字为准考证号
 struct ElemType // 数据元素类型
 {
   long number; // 准考证号，与关键字类型同
   char name[9]; // 姓名(4个汉字加1个串结束标志)
   int politics; // 政治
   int Chinese; // 语文
   int English; // 英语
   int math; // 数学
   int physics; // 物理
   int chemistry; // 化学
   int biology; // 生物
   int total; // 总分
 };
//1、下面是静态查找表的存储结构的定义，请补充完整。
typedef struct {
      ElemType *elem;       // 数据元素存储空间基址
      int length;          // 表长度
 }SSTable;
//2、下面是构造查找表的函数的定义，操作结果：由含n个数据元素的数组r构造静态顺序查找表ST。请补充完整。
void Creat_Seq(SSTable &ST,ElemType r[],int n)
 { 
   int i;
    ST.elem = (ElemType *)malloc((n + 1) * sizeof(ElemType));             // 动态生成n+1个数据元素空间(0号单元不用)
   if(!ST.elem)
     exit(ERROR);
   for(i=1;i<=n;i++)
     ST.elem[i] = r[i];                                // 将数组r的值依次赋给ST
   ST.length=n;
 }
//3、下面函数的作用是：重建静态查找表为按关键字非降序排序。请补充完整。
 void Ascend(SSTable &ST)
 { 
   int i,j,k;
   for(i=1;i<ST.length;i++)
   {
     k=i;
     ST.elem[0] =  ST.elem[i];     // 待比较值存[0]单元
     for(j=i+1;j<=ST.length;j++)
       if LT(ST.elem[j].key,ST.elem[0].key)
       {
         k=j;
         ST.elem[0]=ST.elem[j];
       }
     if LT(ST.elem[i].key, ST.elem[k].key) // 有更小的值则交换
     {
       ST.elem[k]=ST.elem[i];
       ST.elem[i]=ST.elem[0];
     }
   }
 }
//4、下面函数的作用是：由含n个数据元素的数组r构造按关键字非降序查找表ST，请补充完整。
 void Creat_Ord(SSTable &ST,ElemType r[],int n)
 { 
       Creat_Seq(ST, r, n);    // 建立无序的查找表ST
        Ascend (ST);           // 将无序的查找表ST重建为按关键字非降序查找表
 }
//5、下面函数的作用是：销毁静态查找表ST，请补充完整。
 Status Destroy(SSTable &ST)
 { 
   free(ST.elem);                         
   ST.elem=NULL;
   ST.length=0;
   return OK;
 }
//6、下面函数的作用是：在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则返回该元素在表中的位置，否则返回0。请根据函数头部补充完整。
 int Search_Seq(SSTable ST,KeyType key)
 {
	int i;
	ST.elem[0].key = key;
	for(i = ST.length; !EQ(ST.elem[i].key, key); --i);
	
	return i;
	
	

 }
//7、下列函数的作用是：在有序表ST中折半查找其关键字等于key的数据元素。若找到，则返回该元素在表中的位置，否则返回0。请根据函数头部补充完整。
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
//8、下面函数的作用是：按顺序对ST的每个元素调用函数Visit()一次且仅一次，请补充完整。
void print(ElemType c) // Traverse()调用的函数
 {
   printf("%-8ld%-8s%4d%5d%5d%5d%5d%5d%5d%5d\n",c.number,c.name,c.politics,
	   c.Chinese,c.English,c.math,c.physics,c.chemistry,c.biology,c.total);
 }
void Traverse(SSTable ST,void(*Visit)(ElemType))
 { 
   ElemType *p;
   int i;
   p = ST.elem;                           // p指向第一个元素
   for(i=1;i<=ST.length;i++)
       print(*p++);                        
 }

//9、下面是顺序查找主函数，请补充完整。
int main(int argc, char* argv[])
{
   ElemType r[N]={{179328,"何芳芳",85,89,98,100,93,80,47},
   {179325,"陈红",85,86,88,100,92,90,45},
	{179326,"陆华",78,75,90,80,95,88,37},
	{179327,"张平",82,80,78,98,84,96,40},
	{179324,"赵小怡",76,85,94,57,77,69,44}}; // 数组不按关键字有序
   SSTable st;
   int i;
   long s;
   for(i=0;i<N;i++) // 计算总分
     r[i].total= r[i].biology + r[i].chemistry + r[i].Chinese + r[i].English + r[i].math + r[i].physics + r[i].politics;
       Creat_Ord(st, r, 5); // 由数组r产生顺序静态查找表st
   printf("准考证号  姓名  政治 语文 外语 数学 物理 化学 生物 总分\n");
   Traverse(st,print); // 按顺序输出静态查找表st
   printf("请输入待查找人的考号: ");
   scanf("%ld",&s);
   i=    Search_Seq(st, s) ; // 顺序查找
   if(i)
     print(st.elem[i]);
   else
     printf("没找到\n");
   Destroy(st);
	return 0;
}
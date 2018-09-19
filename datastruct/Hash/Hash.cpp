// Hash.cpp : Defines the entry point for the console application.
//任务二：完成下列程序，该程序完成哈希表的开放定址法。在输出结果中显示查找成功与查找不成功信息。

#include "stdafx.h"
#include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()等
 #include<limits.h> // INT_MAX等
 #include<stdio.h> // EOF(=^Z或F6),NULL
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
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))
//#define N 11 // 数据元素个数
#define SUCCESS 1
 #define UNSUCCESS 0
 #define DUPLICATE -1
 #define NULL_KEY 0 // 0为无记录标志
 #define N 10 // 数据元素个数
 typedef int KeyType; // 设关键字域为整型
 struct ElemType // 数据元素类型
 {
   KeyType key;
   int ord;
 };
int hashsize[]={11,19,29,37}; // 哈希表容量递增表，一个合适的素数序列
 int m=0; // 哈希表表长，全局变量
 struct HashTable
 {
   ElemType *elem; // 数据元素存储基址，动态分配数组
   int count; // 当前数据元素个数
   int sizeindex; // hashsize[sizeindex]为当前容量
 };
//1、下面是构造一个空的哈希表的函数，请填空补充完整。
void InitHashTable(HashTable &H)
 { 
   int i;
      H.count=0;                       // 当前元素个数为0
      H.sizeindex=0;                       // 初始存储容量为hashsize[0]
      m=hashsize[0];
     H.elem=(ElemType*)malloc(m*sizeof(ElemType));                                   
   if(!H.elem)
     exit(OVERFLOW); // 存储分配失败
   for(i=0;i<m;i++)
     H.elem[i].key=NULL_KEY; // 未填记录的标志
 }
//2、下面是销毁哈希表的函数，请填空补充完整。
 void DestroyHashTable(HashTable &H)
 { 
   free(H.elem);                          
   H.elem=NULL;
   H.count=0;
   H.sizeindex=0;
 }

 unsigned Hash(KeyType K)
 { // 一个简单的哈希函数(m为表长，全局变量)
   return K%m;
 }

 void collision(int &p,int d) // 线性探测再散列
 { // 开放定址法处理冲突
   p=(p+d)%m;
 }
//3、下面函数的作用是：在开放定址哈希表H中查找关键码为K的元素，若查找成功，以p指示待查数据，元素在表中位置，并返回SUCCESS；否则，以p指示插入位置，并返回UNSUCCESS，c用以计冲突次数，其初值置零，供建表插入时参考。请填空补充完整。
 Status SearchHash(HashTable H,KeyType K,int &p,int &c)
 { 

       p = Hash(K);                        // 求得哈希地址
   while(   H.elem[p].key!= NULL_KEY &&!EQ(K,H.elem[p].key))
   { // 该位置中填有记录．并且关键字不相等
     c++;
     if(c<m)
         collision(p,c); // 求得下一探查地址p
     else
       break;
   }
   if EQ(K,H.elem[p].key)
     return SUCCESS; // 查找成功，p返回待查数据元素位置
   else
     return UNSUCCESS; 
// 查找不成功(H.elem[p].key==NULL_KEY)，p返回的是插入位置
 }
//4、下面是重建哈希表的函数，请填空补充完整。
 Status InsertHash(HashTable &,ElemType); // 对函数的声明
 void RecreateHashTable(HashTable &H)
 { 
   int i,count=H.count;
    ElemType *p,*elem=(ElemType*)malloc(count*sizeof(ElemType));                                             
   p=elem;
   printf("重建哈希表\n");
   for(i=0;i<m;i++) // 保存原有的数据到elem中
     if(   (H.elem+i)->key!=NULL_KEY ) // 该单元有数据
       *p++=*(H.elem+i);
   H.count=0;
      H.sizeindex++;                          // 增大存储容量
   m=hashsize[H.sizeindex];
   p=(ElemType*)realloc(H.elem,m*sizeof(ElemType));
   if(!p)
     exit(OVERFLOW); // 存储分配失败
   H.elem=p;
   for(i=0;i<m;i++)
       H.elem[i].key=NULL_KEY;    // 未填记录的标志(初始化)
   for(p=elem;p<elem+count;p++) // 将原有的数据按照新的表长插入到重建的哈希表中
        InsertHash(H,*p);                            
 }
//5、下面函数的作用是：在哈希表中查找数据元素e，查找不成功时插入数据元素e到开放定址哈希表H中，并返回OK； 若冲突次数过大，则重建哈希表。请填空补充完整。
 Status InsertHash(HashTable &H,ElemType e)
 { 
   int c,p;
   c=0;
   if(  SearchHash(H,e.key,p,c))  // 表中已有与e有相同关键字的元素
     return DUPLICATE;
   else if(c<hashsize[H.sizeindex]/2) // 冲突次数c未达到上限，(c的阀值可调)
   { // 插入e
      H.elem[p]=e;                              
     ++H.count;
     return OK;
   }
   else
   {
     RecreateHashTable(H);   // 重建哈希表
     return UNSUCCESS;
   }
 }
//6、下列函数的作用是：按哈希地址的顺序遍历哈希表，请填空补充完整。
 void TraverseHash(HashTable H,void(*Vi)(int,ElemType))
 { 
   printf("哈希地址0～%d\n",m-1);
   for(int i=0;i<m;i++)
     if(   H.elem[i].key!=NULL_KEY ) // 有数据
       Vi(i,H.elem[i]);
 }


//7、下列函数的作用是：在开放定址哈希表H中查找关键码为K的元素，若查找成功，以p指示待查数据元素在表中位置，并返回SUCCESS；否则，返回UNSUCCESS
 Status Find(HashTable H,KeyType K,int &p)
 { 
   int c=0;
       p=Hash(K);               // 求得哈希地址
   while(H.elem[p].key!=NULL_KEY&&!EQ(K,H.elem[p].key))
   { // 该位置中填有记录．并且关键字不相等
     c++;
     if(c<m)
     collision(p,c);   // 求得下一探查地址p
     else
     return UNSUCCESS; // 查找不成功(H.elem[p].key==NULL_KEY)
   }
   if EQ(K,H.elem[p].key)
     return SUCCESS; // 查找成功，p返回待查数据元素位置
   else
     return UNSUCCESS; // 查找不成功(H.elem[p].key==NULL_KEY)
 }
 void print(int p,ElemType r)
 {
   printf("address=%d (%d,%d)\n",p,r.key,r.ord);
 }

//8、下面是主函数的定义，请补充完整。
int main(int argc, char* argv[])
{
 ElemType r[N]={{17,1},{60,2},{29,3},{38,4},{1,5},{2,6},{3,7},{4,8},{60,9},{13,10}};
   HashTable h;
   int i,p;
   Status j;
   KeyType k;
   InitHashTable(h);
   for(i=0;i<N-1;i++)
   { // 插入前N-1个记录
     j=InsertHash(h,r[i]);
     if(j==DUPLICATE)
       printf("表中已有关键字为%d的记录，无法再插入记录(%d,%d)\n",r[i].key,r[i].key,r[i].ord);
   }
   printf("按哈希地址的顺序遍历哈希表:\n");
      TraverseHash(h,print);//
   printf("请输入待查找记录的关键字: ");
   scanf("%d",&k);
   j= Find(h,k,p); //
   if(j==SUCCESS)
     print(p,h.elem[p]);
   else
     printf("没找到\n");
   j=InsertHash(h,r[i]); // 插入第N个记录
   if(j==ERROR) // 重建哈希表
     j=InsertHash(h,r[i]); // 重建哈希表后重新插入
   printf("按哈希地址的顺序遍历重建后的哈希表:\n");
   TraverseHash(h,print);
   printf("请输入待查找记录的关键字: ");
   scanf("%d",&k);
   j=Find(h,k,p);
   if(j==SUCCESS)
     print(p,h.elem[p]);
   else
     printf("没找到\n");
   DestroyHashTable(h);
   return 0;
}


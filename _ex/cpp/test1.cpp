// test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//bool type and length 
//	bool b = false;  //byte
struct SS{
	int a;
	int b;
	int c;
};
void put(SS s)
{
	s.a = 1;
	s.b = 2;
	s.c = 3;
}
int main(int argc, char* argv[])
{
	SS s1;
	/*
0040108D 8B 4D F4             mov         ecx,dword ptr [ebp-0Ch]
00401090 89 08                mov         dword ptr [eax],ecx
00401092 8B 55 F8             mov         edx,dword ptr [ebp-8]
00401095 89 50 04             mov         dword ptr [eax+4],edx
00401098 8B 4D FC             mov         ecx,dword ptr [ebp-4]
0040109B 89 48 08             mov         dword ptr [eax+8],ecx
	*/
	//�ṹ�����С��3ʱ��pushָ�����ѹ���ջ���������üĴ����ڴ���д���
	put(s1);
	return 0;
}

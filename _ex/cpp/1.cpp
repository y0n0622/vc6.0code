// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "memory.h"


int gi;
	
void buildCode(int* address)
{
	char* code = (char*)malloc(16);
	memset(code, 0, sizeof(code));
	char* pMov = code;
	char* pJmp = code + 10;
	char* pAddress;
	//mov gi, 18
	pMov[0] = (char)0xc7;
	pMov[1] = (char)0x05;
	pAddress = pMov + 2;
	*((int*)pAddress) = (int)&gi;
	*((int*)(pAddress + 4)) = 18;
	//jmp address
	pJmp[0] = (char)0xff;
	pJmp[1] = (char)0x25;
	*((int*)(&pJmp[2])) = (int)&address;

	//修改页面属性
	
	//跳转到执行构造代码处
	
	
	//恢复页面属性
	__asm {
		jmp  code
	}
	free(code);
    
}
int main(int argc, wchar_t* argv[])
{
	int* address;
	gi = 12;
	__asm {mov address, offset _lb1}
	
	printf("gi = %d\n", gi);
    buildCode(address);

	
	gi = 13;


_lb1:
	printf("gi = %d\n", gi);
	return 0;
}

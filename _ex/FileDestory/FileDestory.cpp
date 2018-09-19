// FileDestory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"

int main(int argc, char* argv[])
{
	FILE *fp;
	FILE *temp;
	char ch;
	char strFileName[256];
	char strTempBuff[256];
	printf("请将要加密的文件名称重命名为1.txt,同时将该文件放入f盘根目录下，请输入1.txt:");
	//输入要处理的文件名
	//gets(strFileName);
	scanf("%s", &strFileName);
//	strFileName[255] = '\0';
	//以读方式打开
	if((fp = fopen("F:\\1.txt", "rb+")) == NULL)
	{
		printf("Open File %s Error!\n", strFileName);
		return -1;
	}
	//以写方式创建一个临时文件
	if((temp = fopen("TempFile.pyq", "wb+")) == NULL)
	{
		printf("Create Tempporary File Error!\n");
		return -1;
	}
	//如果没有到文件末尾继续循环
	while(!feof(fp))
	{
		ch = fgetc(fp);//读取字符
		if((int)ch != -1 && (int)ch != 0)
		{
			ch = ~ch;//取反
			fputc(ch, temp);//写入临时文件
		}
	}
	fclose(temp);
	fclose(fp);
	//删除原文件
	sprintf(strTempBuff, "del %s", strFileName);
	system(strTempBuff);
	//将临时文件改为原文件名
	sprintf(strTempBuff, "ren TempFile.pyq %s", strFileName);
	system(strTempBuff);
	printf("加密成功！\n");
	getchar();
	return 0;
}


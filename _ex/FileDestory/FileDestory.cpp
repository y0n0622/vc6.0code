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
	printf("�뽫Ҫ���ܵ��ļ�����������Ϊ1.txt,ͬʱ�����ļ�����f�̸�Ŀ¼�£�������1.txt:");
	//����Ҫ������ļ���
	//gets(strFileName);
	scanf("%s", &strFileName);
//	strFileName[255] = '\0';
	//�Զ���ʽ��
	if((fp = fopen("F:\\1.txt", "rb+")) == NULL)
	{
		printf("Open File %s Error!\n", strFileName);
		return -1;
	}
	//��д��ʽ����һ����ʱ�ļ�
	if((temp = fopen("TempFile.pyq", "wb+")) == NULL)
	{
		printf("Create Tempporary File Error!\n");
		return -1;
	}
	//���û�е��ļ�ĩβ����ѭ��
	while(!feof(fp))
	{
		ch = fgetc(fp);//��ȡ�ַ�
		if((int)ch != -1 && (int)ch != 0)
		{
			ch = ~ch;//ȡ��
			fputc(ch, temp);//д����ʱ�ļ�
		}
	}
	fclose(temp);
	fclose(fp);
	//ɾ��ԭ�ļ�
	sprintf(strTempBuff, "del %s", strFileName);
	system(strTempBuff);
	//����ʱ�ļ���Ϊԭ�ļ���
	sprintf(strTempBuff, "ren TempFile.pyq %s", strFileName);
	system(strTempBuff);
	printf("���ܳɹ���\n");
	getchar();
	return 0;
}


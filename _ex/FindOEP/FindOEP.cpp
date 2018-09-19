// FindOEP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

//通过文件读取OEP
BOOL ReadOEPByFile(LPCSTR szFileName)
{
	HANDLE hFile;

	if ((hFile = CreateFile(szFileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, 0)) == INVALID_HANDLE_VALUE)
	{
		printf("Can't not open file.\n");
		return FALSE;
	}

	DWORD dwOEP, cbRead;
	IMAGE_DOS_HEADER dos_head[sizeof(IMAGE_DOS_HEADER)];
	if (!ReadFile(hFile, dos_head, sizeof(IMAGE_DOS_HEADER), &cbRead, NULL))
	{
		printf("Read image_dos_header failed.\n");
		CloseHandle(hFile);
		return FALSE;
	}

	int nEntryPos = dos_head->e_lfanew + 40;
	SetFilePointer(hFile, nEntryPos, NULL, FILE_BEGIN);

	if (!ReadFile(hFile, &dwOEP, sizeof(dwOEP), &cbRead, NULL))
	{
		printf("read OEP failed.\n");
		CloseHandle(hFile);
		return FALSE;
	}

	CloseHandle(hFile);

	printf("OPE by file: %x\n", dwOEP);
	return TRUE;
}

//通过文件内存映射读取OEP
BOOL ReadOEPByMenory(LPCSTR szFileName)
{
	struct PE_HEADER_MAP
	{
		DWORD signature;
		IMAGE_FILE_HEADER _head;
		IMAGE_OPTIONAL_HEADER opt_head;
		IMAGE_SECTION_HEADER section_header[6];
	} *header;

	HANDLE hFile;
	HANDLE hMapping;
	void *basepointer;

	if ((hFile = CreateFile(szFileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, 0)) == INVALID_HANDLE_VALUE)
	{
		printf("Can't open file.\n");
		return FALSE;
	}

	if (!(hMapping = CreateFileMapping(hFile, 0, PAGE_READONLY | SEC_COMMIT, 0, 0, 0)))
	{
		printf("Mapping faild.\n");
		CloseHandle(hFile);
		return FALSE;
	}

	if (!(basepointer = MapViewOfFile(hMapping, FILE_MAP_READ, 0, 0, 0)))
	{
		printf("view failed.\n");
		CloseHandle(hMapping);
		CloseHandle(hFile);
		return FALSE;
	}

	IMAGE_DOS_HEADER *dos_head = (IMAGE_DOS_HEADER*)basepointer;

	header = (PE_HEADER_MAP*)((char*)dos_head + dos_head->e_lfanew);

	DWORD dwOEP = header->opt_head.AddressOfEntryPoint;

	UnmapViewOfFile(basepointer);
	CloseHandle(hMapping);
	CloseHandle(hFile);

	printf("OEP By memory: %x\n", dwOEP);
	return TRUE;
}
int main(int argc, char* argv[])
{
	//LPCSTR szFileName;
	
	ReadOEPByFile("HelloWorld.exe");
	ReadOEPByMenory("HelloWorld.exe");
	return 0;
}

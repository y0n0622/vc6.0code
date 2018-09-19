// DM1_36.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int gi;
void usage()
{
	printf("please input s to set gi or d to display gi\n");
}
int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		usage();
		return 0;
	}
	if(argv[1][0] == 's')
	{
		gi = 12;
		printf("gi = %d\n", gi);
		getchar();
	}
	else if(argv[1][0] == 'd')
	{
		printf("gi = %d\n", gi);
	}
	else 
	{
		usage();
	}

	return 0;
}

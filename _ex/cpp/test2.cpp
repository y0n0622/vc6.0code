// test2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char* argv[])
{
	int i1, i2;
	char sample[1024][1024];
	for(i1 = 0; i1 < 1024; i1++)
	{
		for(i2 = 0; i2 < 1024; i2++)
		{
			sample[i1][i2] = 'c';
		}
	}
	return 0;
}

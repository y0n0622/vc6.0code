// DM1_10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int Add(int x, int y)
{
	int sum;
	sum = x + y;
	return sum;
}
int main(int argc, char* argv[])
{
	int z;
	z = Add(1, 2);
	printf("z = %d\n", z);
	return 0;
}

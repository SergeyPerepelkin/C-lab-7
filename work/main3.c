#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "task3.h"

#define SIZE 256
#define READ "rb" 
#define WRITE "wb"

int main(int argc, char* argv[])
{
	int count = 0;
	int countUnique = 0;
	SYM_t *syms = (SYM_t*)calloc(SIZE, sizeof(SYM_t));
	FILE *fp;
	if (argc > 1)
		fp = fopen(argv[1], READ);
	else
		fp = fopen("left.txt", READ);
	if (!fp)
	{
		perror("File:");
		return 1;
	}
	createBuf(syms);
	count = simbolCounter(fp, syms);
	countUnique = UniqueSimbol(syms);
	bubleSort(syms);
	tofraction(syms, count);
	printTable(syms);
	return 0;
}
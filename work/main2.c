#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "task2.h"

int main()
{
	CWORD_T *head = 0;
	FILE *fp;
	fp = fopen("word.txt", "rt");
	if (!fp)
	{
		perror("File:");
		return 1;
	}
	head = makeTree(fp);
	if (head == 0)
	{
		puts("Data error!");
		return 2;
	}
	fclose(fp);
	fp = fopen("task1.c", "rt");
	if (!fp)
	{
		perror("File:");
		return 1;
	}

	readFile(fp, head);

	return 0;

}
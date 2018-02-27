#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "task1.h"

int main()
{
	char sregion[50] = { 0 };
	char abr[3] = { 0 };
	COUNTRY_T *head = 0;
	FILE *fp;

	fp = fopen("fips10_4.csv", "rt");
	if (!fp)
	{
		perror("File:");
		return 1;
	}
	head = mkList(fp);
	if (head == 0)
	{
		puts("Data error!");
		return 2;
	}
	fclose(fp);
	//printList(head);

	printf("Enter abr country\n");
	scanf("%s", abr);
	if (abr[strlen(abr) - 1] == '\n')
		abr[strlen(abr) - 1] = '\0';
	searchCountry(head, abr);

	printf("Enter region - ''Name''\n");
	scanf("%s", sregion);
	if (abr[strlen(sregion) - 1] == '\n')
		abr[strlen(sregion) - 1] = '\0';
	searchRegion(head, sregion);
	return 0;
}


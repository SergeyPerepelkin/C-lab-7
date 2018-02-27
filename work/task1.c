#include <stdlib.h>
#include<stdio.h>
#include "task1.h"


COUNTRY_T* mkList(FILE *fp)
{
	COUNTRY_T *head = 0;
	char buf[256];
	while (fgets(buf, 256, fp))
	{
		if (checkLine(buf))
		{
			if (head == 0)
				head = create(buf);
			else
				addTail(head, buf);
		}
	}
	return head;
}

COUNTRY_T* create(char *line)
{
	COUNTRY_T *country = (COUNTRY_T*)malloc(sizeof(COUNTRY_T));
	setStruct(country, line);
	country->next = NULL;
	return country;
}

COUNTRY_T* addTail(COUNTRY_T* head, char *line)
{
	while (head->next)
		head = head->next;
	head->next = create(line);
}

void setStruct(COUNTRY_T *country, char *line)
{
	char tmp[4];
	char *p = line;
	p = copySub(p, country->abr2);
	p = copySub(p + 1, tmp);
	country->unid = atoi(tmp);
	p = copySub(p + 1, country->region);

}

char* copySub(char *where, char *to)
{
	while (*where != ',' &&*where != '\n' &&*where != '\0')
		*to++ = *where++;
	*to = '\0';
	return where;
}

int checkLine(char *line)
{
	char tmp[256];
	char *p = line;
	p = copySub(p, tmp);//AA
	if (strlen(tmp) != 2)
		return 0;
	p = copySub(p + 1, tmp);//id
	if (strlen(tmp) != 2)
		return 0;
	if (atoi(tmp) == 0)
		return 0;
	return 1;
}


void printList(COUNTRY_T *head)
{
	putchar('\n');
	while (head)
	{
		printf("%s %02d %50s\n",
			head->abr2,
			head->unid,
			head->region);
		head = head->next;
	}
}


void searchCountry(COUNTRY_T *head, char *abr)
{
	while (head)
	{
		if (head->abr2[0] == abr[0] && head->abr2[1] == abr[1])
		{
			printf("%s %02d %50s\n",
				head->abr2,
				head->unid,
				head->region);
		}
	head = head->next;
	}
}

void searchRegion(COUNTRY_T *head, char *sregion)
{
	if (strcmp(head->region, sregion) == 0)
	{
		printf("%s %02d %50s\n",
			head->abr2,
			head->unid,
			head->region);
		return;
	}
	head = head->next;
}
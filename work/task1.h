#include <stdio.h>

typedef unsigned short US;
typedef struct COUNTRY COUNTRY_T;

struct COUNTRY
{
	US unid; //код страны
	char abr2[3]; // аббревиатура двухзначная
	char region[256];
	COUNTRY_T *next;
};

COUNTRY_T* mkList(FILE *fp);//открывает файл
void setStruct(COUNTRY_T *country, char *line);//перевод корректной строки в структуру
char* copySub(char *where, char *to);
int checkLine(char *line);//проверка строки
COUNTRY_T* create(char *line);
COUNTRY_T* addTail(COUNTRY_T *head, char *line);
void printList(COUNTRY_T *head);
void searchCountry(COUNTRY_T *head, char *abr);
void searchRegion(COUNTRY_T *head, char *sregion);
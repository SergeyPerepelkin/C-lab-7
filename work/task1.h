#include <stdio.h>

typedef unsigned short US;
typedef struct COUNTRY COUNTRY_T;

struct COUNTRY
{
	US unid; //��� ������
	char abr2[3]; // ������������ �����������
	char region[256];
	COUNTRY_T *next;
};

COUNTRY_T* mkList(FILE *fp);//��������� ����
void setStruct(COUNTRY_T *country, char *line);//������� ���������� ������ � ���������
char* copySub(char *where, char *to);
int checkLine(char *line);//�������� ������
COUNTRY_T* create(char *line);
COUNTRY_T* addTail(COUNTRY_T *head, char *line);
void printList(COUNTRY_T *head);
void searchCountry(COUNTRY_T *head, char *abr);
void searchRegion(COUNTRY_T *head, char *sregion);
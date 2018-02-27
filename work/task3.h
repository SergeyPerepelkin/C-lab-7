#include <stdio.h>
#define MAXSTRING 128

struct SYM
{
	unsigned char ch;
	float freq;
	char code[MAXSTRING];
	struct SYM* left;
	struct SYM* right;
};

typedef struct SYM SYM_t;


void createBuf(SYM_t *syms);
int simbolCounter(FILE *fp, SYM_t *syms);
int UniqueSimbol(SYM_t *syms);
void bubleSort(SYM_t *syms);
void tofraction(SYM_t *syms, int count);
void printTable(SYM_t *syms);
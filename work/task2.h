#include <stdio.h>

typedef struct CWORD CWORD_T;

struct CWORD
{
	char word[256];
	unsigned int count;
	CWORD_T *left;
	CWORD_T *right;
};

CWORD_T* makeTree(FILE *fp);
CWORD_T* create(char *line);
CWORD_T* addBranch(CWORD_T* head, char *line);
void searchTree(char *buf, CWORD_T* head);
void readFile(FILE *fp, CWORD_T * head);
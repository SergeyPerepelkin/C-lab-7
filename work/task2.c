#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "task2.h"

CWORD_T* makeTree(FILE *fp)
{
	CWORD_T *head = 0;
	char buf[256];
	while (fgets(buf, 256, fp))
	{
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';
		if (head == 0)
			head = create(buf);
		else
			addBranch(head, buf);
	}
	return head;
}

CWORD_T* create(char *line)
{
	int i = 0;
	CWORD_T *word = (CWORD_T*)malloc(sizeof(CWORD_T));
	while (line[i] != '\0')
	{
		word->word[i] = line[i];
		i++;
	}
	word->word[i] = line[i];
	word->count = 0;
	word->left = NULL;
	word->right = NULL;
	return word;
}

CWORD_T* addBranch(CWORD_T* head, char *line)
{
	if (strcmp(head->word, line) > 0)
	{
		if (head->left == NULL)
			head->left = create(line);
		else
			addBranch(head->left, line);
	}
	else
	{
		if (head->right == NULL)
			head->right = create(line);
		else
			addBranch(head->right, line);
	}

}

void readFile(FILE *fp, CWORD_T * head)
{
	int flag = 0;
	char buf[20] = { 0 };
	char ch = 0;
	int i = 0;
	while (1)
	{
		if (fscanf(fp, "%c", &ch) == -1)
			break;
		if (ch >= 'a' && ch <= 'z' && flag == 0)
		{
			buf[i++] = ch;
			flag = 1;
		}
		else if (ch >= 'a' && ch <= 'z' && flag == 1)
		{
			buf[i++] = ch;
		}
		if ((ch < 'a' || ch > 'z') && flag == 1)
		{
			buf[i] = '\0';
			searchTree(buf, head);
			i = 0;
		}
	}
	if (i > 0)
	{
		buf[i] = '\0';
		searchTree(buf, head);
		i = 0;
	}
}

void searchTree(char *buf, CWORD_T* head)
{
	if (strcmp(head->word, buf) == 0)
	{
		head->count++;
		return;
	}
	if (head->left)
		searchTree(buf, head->left);
	if (head->right)
		searchTree(buf, head->right);
}
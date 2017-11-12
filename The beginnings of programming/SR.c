#include <stdio.h>
#include <conio.h>

typedef struct Elem
{
	int data;
	struct Elem *next;
}List;

FILE* f;

void InputFile(int);
void PrintFile();

void InputList(List **begin);
void PrintList(List *begin);
void SortList(List *begin);

int main()
{
	List *BegL = NULL;
	List *EndL = NULL;

	int n;
	printf(" Input n: ");
	scanf("%d", &n);

	printf("\n\n File: ");
	InputFile(n);
	PrintFile();

	printf("\n\n List: ");
	InputList(&BegL);
	PrintList(BegL);

	printf("\n\n Sorted List: ");
	SortList(BegL);
	PrintList(BegL);
	printf("\n\n");

	free(BegL);
	_getch();
	return 0;
}

void InputFile(int n)
{
	int i,c = 0;
	if ((f = fopen("file.txt", "w")) == 0)
	{
		perror("No such file or directory");
		exit(1);
	}
	for (i = 0; i < n; i++)
	{
		c = 5 + rand() % 92;
		fwrite(&c, sizeof(c), 1, f);
	}
	fclose(f);
}

void PrintFile()
{
	int c;
	f = fopen("file.txt", "r");
	while (fread(&c, sizeof(c), 1, f))
	{
		printf("%d ", c);
	}
	fclose(f);
}

void InputList(List **begin)
{
	int k;
	f = fopen("file.txt", "r");
	(*begin) = (List*)malloc(sizeof(List));
	fread(&k, sizeof(k), 1, f);
	(*begin)->data = k;
	(*begin)->next = NULL;
	List *tmp = (*begin);

	while (fread(&k, sizeof(k), 1, f))
	{
		tmp->next = (List*)malloc(sizeof(List));
		tmp = tmp->next;
		tmp->data = k;
		tmp->next = NULL;
	}
	fclose(f);
}

void PrintList(List *begin) {
	List *tmp = begin;
	while (tmp)
	{
		printf("%d -> ", tmp->data);
		tmp = tmp->next;
	}
	printf("NULL");
}

void SortList(List *begin)
{
	List * list = begin;
	List * p1, *p2;

	for (p1 = list; p1; p1 = p1->next)
		for (p2 = list; p2; p2 = p2->next)
			if (p1->data < p2->data)
			{
				int i = p1->data;
				p1->data = p2->data;
				p2->data = i;
			}
}

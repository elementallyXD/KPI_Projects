#include "main.h"
#include "write.h"

void writeRandom() 
{
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			A[i][j] = rand() % 9 - 2;
}

void writeKeyboard() 
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
}

void writeSorted()
{
	int temp = -4;
		for (short i = 0; i < n; i++)
			for (short j = 0; j < n; j++)
				A[i][j] = temp++;
}
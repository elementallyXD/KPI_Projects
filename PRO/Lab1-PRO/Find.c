#include "Main.h"
#include "find.h"

void find_debug() {
	int positive, negative, pos_p = -20, pos_n = -20;
		positive = A[0][0];
		negative = A[0][0];

	for (int i = 0; i < n; i++) 
	{
		if (A[i][i] < 0)
		{
			pos_n = i;
			negative = A[pos_n][pos_n];
		}

		if (A[n - i - 1][n - i - 1] >= 0)
		{
			pos_p = n - i - 1;
			positive = A[pos_p][pos_p];
		}
	}

	if ((pos_p != -20) && (pos_n != -20))
	{
		printf("\nFirst positive number = %d ; Position : [%d][%d]\n", positive, pos_p, pos_p);
		printf("Last negative number = %d ; Position : [%d][%d]\n", negative, pos_n, pos_n);
		
		A[pos_n][pos_n] = positive;
		A[pos_p][pos_p] = negative;

		printf("\t\nChanges: \n");
		printf("Positive = %d ; Position : [%d][%d] \n", positive, pos_n, pos_n);
		printf("Negative = %d ; Position : [%d][%d] \n", negative, pos_p, pos_p);
	}
	else
	{
		printf("\t\nError. Can't find numbers with this properties.\n");
	}
}

void find_release() {
	int positive, negative, pos_p = -20, pos_n = -20;
	positive = A[0][0];
	negative = A[0][0];

	for (int i = 0; i < n; i++)
	{
		if (A[i][i] < 0)
		{
			pos_n = i;
			negative = A[pos_n][pos_n];
		}

		if (A[n - i - 1][n - i - 1] >= 0)
		{
			pos_p = n - i - 1;
			positive = A[pos_p][pos_p];
		}
	}

	if ((pos_p != -20) && (pos_n != -20))
	{
		A[pos_n][pos_n] = positive;
		A[pos_p][pos_p] = negative;
	}
	else
	{
		printf("\t\nError. Can't find numbers with this properties.\n");
	}
}

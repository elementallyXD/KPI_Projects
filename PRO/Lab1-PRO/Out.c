#include "main.h"
#include "out.h"

void out()
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			printf("   %d   ", A[i][j]);
		}
		printf("\n");
	}
}

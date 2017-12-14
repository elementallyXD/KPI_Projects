#include "cArray.h"

int main(void)
{
	printf("Create A array\n");
	cArray a;			//create an integer array
	printf("Adding 2 elements in to A\n");
	a.Add(25);			// call Add
	a.Add(2);
	
	printf("\nA array:\n");
	a.PrintPrivate();
	a.PrintfCounts();	// print second integer array

	printf("\nCreate B array\n");
	cArray b;			//create second integer array
	printf("Change size B array to 3 and add 3 elements\n");
	b.SetSize(3);		 //call SetSize
	for (int i = 0; i < 3; i++)
	{
		b.Add(25 + i);
	}
	
	printf("\nB array:\n");
	b.PrintPrivate();
	b.PrintfCounts();	 // print second integer array
	
	if (!a.IsEmpty())	// call IsEmpty 
	{ 
		printf("\na.FreeExtra"); a.FreeExtra(); // call FreeExtra
		printf("\nA array private counts:\n");
		a.PrintPrivate();

		printf("\na.SetAt(125,3)\n");
		a.SetAt(125, 3); //call SetAt
		a.PrintfCounts();

		printf("\na.RemoveAll"); a.RemoveAll(); // call RemoveAll
		printf("\nA array private counts:\n");
		a.PrintPrivate();

		printf("\na.Copy(&b)");
		a.Copy(&b); //call Copy fucn
		printf("\nA array private counts:\n");
		a.PrintPrivate();
		a.PrintfCounts();

		printf("\na.InsertAt(128, 6)");
		printf("\nA array private counts:\n");
		a.InsertAt(128, 6); //call InsertAt fucn
		a.PrintPrivate();
		a.PrintfCounts();

		printf("\na.RemoveAt(6)"); 
		a.RemoveAt(6); //call RemoveAt fucn
		printf("\nA array private counts:\n");
		a.PrintPrivate();
		a.PrintfCounts();

		printf("\n\nOperator [7] = %d", a.operator[](7)); // call operator[]
	}
	_getch();
	return 0;
}
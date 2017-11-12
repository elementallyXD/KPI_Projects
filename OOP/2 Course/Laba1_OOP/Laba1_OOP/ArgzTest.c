/***********************************************************************
*file: argz_test.c
*These functions are declared in the include file "argz.h".
*related files: argz.c and argz.h
*author: Bidyak Mikhailo
*written: 26/09/2017
*last modified: 24/10/2017
************************************************************************/
#include "FunctionArgz.h"

/*
	CUSTOM CODE
*/
int main(void)
{
	//initial values
	char *argz, *ptr = NULL;
	size_t argz_len = 0;

	if (argz_create_sep("Func;Doing;Good", ';', &argz, &argz_len) == OK)   //call the SEP function
	{
			printf("Func started (argz_create_sep(\"Fucn;Doing;Good\", ';', &argz, &argz_len):\n");
			argz_print(argz, argz_len);						//call the print function
			printf("argz_len = %d\n\n", argz_len);          //print the length of the vector
		
			printf("Number of '\\0' calculated by argz_count(argz, argz_len) = %d\n\n", argz_count(argz, argz_len)); //call the COUNT function


		if (argz_add(&argz, &argz_len, "ADD") == OK)      //call the ADD function
		{
			printf("argz_add(&argz, &argz_len, \"ADD\"):\n");
			argz_print(argz, argz_len);							//call the print function
			printf("\nargz_len = %d\n\n", argz_len);           //print the length of the vector

			argz_delete(&argz, &argz_len, "Good");       //call the DELETE function
			printf("argz_delete(&argz, &argz_len, \"Good\")\n");
			argz_print(argz, argz_len);						//call the print function
			printf("argz_len = %d\n\n", argz_len);          //print the length of the vector
		}
		else exit(1);  // exit with code (1) if something wrong
	
		if (argz_insert(&argz, &argz_len, "ADD", "Working") == OK){   //call the INSERT function
			printf("argz_insert(&argz, &argz_len,\"ADD\", \"Working\"):\n");
			argz_print(argz, argz_len);						//call the print function
			printf("argz_len = %d\n\n", argz_len);          //print the length of the vector

			printf("argz_next(argz, argz_len, entry): \n");      //print symbols by the "NEXT" function
			for (ptr = argz; ptr; ptr = argz_next(argz, argz_len, ptr))
				printf("%s\n", ptr);
				printf("argz_len = %d\n\n", argz_len);
		}
		else exit(1); // exit with code (1) if something wrong

		if (argz_replace(&argz, &argz_len, "Doing", "DO") == OK){   //call the REPLACE function
			printf("argz_replace(&argz, &argz_len, \"Doing\", \"DO\"):\n");
			argz_print(argz, argz_len);						//call the print function
			printf("argz_len = %d\n\n", argz_len);          //print the length of the vector
		}
		else exit(1);// exit with code (1) if something wrong
	}
	else exit(1);   // exit with code (1) if something wrong

	_getch(); // wait for keyword 
	return 0;
}
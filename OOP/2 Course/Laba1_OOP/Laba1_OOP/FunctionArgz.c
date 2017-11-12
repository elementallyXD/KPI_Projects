/***********************************************************************
*file: argz.c
*synopsis: The argz functions use malloc/realloc to allocate/grow argz vectors,
*and so any argz vector creating using these functions may be freed by using
*free; conversely, any argz function that may grow a string expects that string
*to have been allocated *using malloc those argz functions that only examine
*their arguments or modify them in place *will work on any sort of memory). All *argz functions that do memory allocation have a return type of error_t, and
*return 0 for success, and ERROR if an allocation error occurs.
* These functions are declared in the include file "argz.h".
*related files: argz_test.c and argz.h
*author: Bidyak Mikhailo
*written: 26/09/2017
*last modified: 24/10/2017
************************************************************************/

#include "FunctionArgz.h"

/*
The argz_create_sep function converts the null-terminated string string into an
argz vector (returned in argz and argz len) by splitting it into elements at every
occurrence of the character sep.
*/
error_t argz_create_sep(const char *string, int sep, char **argz, size_t *argz_len)
{
	unsigned int i = 0;
	const unsigned int string_size = strlen(string); // legth our string
	*argz_len = string_size + 1; //change the length of the line
	
	if ((*argz = (char*)malloc(sizeof(char)*(string_size + 1))) == NULL) //allocates memory for a new array of elements
		exit(1); //end if memory allocation failed
								 /*
	check pointers. if some of them NULL -> end the program or send ERROR
	It's need for the correct program operation.
	*/
	if (*argz == NULL) { return ERROR; }
	if (*string == NULL) { return ERROR; }
	if ((sep < 0)&(sep>127)) { return ERROR; }

	for (i = 0; i < string_size; i++)
	{
		if (*(string + i) != sep)
			*(*argz + i) = *(string + i);
		else
			*(*argz + i) = '\0';
	}

	*(*argz + string_size) = '\0';
	return OK;
}

//Function returns the number of elements '/0' in the argz vector.
size_t argz_count(const char *argz, size_t argz_len)
{
	unsigned int i = 0, count = 0;

	if (*argz == NULL) { return 1; }
	
	for (i = 0; i < argz_len; i++)
		if (*(argz + i) == '\0') count++;
	return count;
}

//The argz_add function adds the string str to the end of the argz vector 
error_t argz_add(char **argz, size_t *argz_len, const char *str)
{
	unsigned int i = 0;
	const unsigned int str_size = strlen(str);
	
	char *tmp = (char*)malloc(sizeof(char)*(*argz_len + str_size + 1)); //allocates memory for a new array of elements
	if (*tmp == NULL) { return ERROR; } //end if memory allocation failed
	/*
	check pointers. if some of them NULL -> end the program.
	It's need for the correct program operation.
	*/
	if (*argz == NULL) { return ERROR; }
	if (*str == NULL) { return ERROR; }
	
	for (i = 0; i < *argz_len; i++)
		*(tmp + i) = *(*argz + i);

	for (i = 0; i < str_size; i++)
		*(tmp + i + (*argz_len)) = *(str + i);

	*argz_len += str_size + 1; //change the number of characters
	*(tmp + (*argz_len) - 1) = '\0';

	free(*argz); //remove the memory by the pointer
	*argz = tmp; //point to a new memory cell

	return OK;
}

/*If entry points to the beginning of one of the elements in the argz vector *argz,
the argz_delete function will remove this entry and reallocate *argz, modifying *argz and *argz_len accordingly.
Note that as destructive argz functions usually reallocate their argz argument,
pointers into argz vectors such as entry will then become invalid.
*/
void argz_delete(char **argz, size_t *argz_len, char *entry)
{
	unsigned int i = 0, k = 0;
	char *ptr = NULL;// pointer for pass through the fields
	const unsigned int entry_size = strlen(entry); //The length of the word which we need to delete
	
	char *tmp = (char*)malloc((*argz_len - entry_size) * sizeof(char)); //allocates memory for a new array of elements
	if (*tmp == NULL) { return; } //end if memory allocation failed
	/*
	check pointers. if some of them NULL -> end the program or send ERROR
	It's need for the correct program operation.
	*/
	if (entry == NULL) { exit(1); }
	if (*argz == NULL) { exit(1); }

	while (ptr = argz_next(*argz, *argz_len, ptr))  //check the "entry" str in our list of fields
		if (strcmp(entry, ptr) == 0) k++; //if we found str in fields, k>0
	if (k == 0) { exit(1);}

	while (ptr = argz_next(*argz, *argz_len, ptr)) {
		if (strcmp(ptr, entry) != 0) {
			strcpy(tmp + i, ptr);
			i += strlen(ptr) + 1;
		}
	}
	free(*argz); //remove the memory by the pointer
	*argz = tmp; //point to a new memory cell
	*argz_len = *argz_len - entry_size - 1; //change the number of characters
}

/*
The argz_next function provides a convenient way of iterating over the elements in the argz vector argz.
It returns a pointer to the next element in argz after the element entry, or 0 if there are no elements following entry.
If entry is 0, the first element of argz is returned.
*/
char *argz_next(char *argz, size_t argz_len, char *entry)
{
	char *ptr = NULL;
	
	if (argz == NULL) exit(1);
	if (entry == NULL) 	return argz;
	
	for (ptr = entry; ptr <= argz + argz_len; ptr++)
	{
		if (ptr == argz + argz_len - 1) return NULL;
		else if (*ptr == '\0')	return ptr + 1;
	}
	
	return NULL;
}

/*
The argz_insert function inserts the string entry into the argz vector *argz at a point just before the existing
element pointed to by before, reallocating *argz and updating *argz and *argz_len. If before is 0, entry is added
to the end instead (as if by argz_add). Since the first element is in fact the same as *argz, passing in *argz as
the value of before will result in entry being inserted at the beginning.
*/
error_t argz_insert(char **argz, size_t *argz_len, char *before, const char *entry) {
	unsigned int i = 0, k = 0;
	const unsigned int entry_size = strlen(entry); //The length of the word which we insert
	char *ptr = NULL; // pointer for pass through the fields
	
	char *tmp = (char*)malloc((*argz_len + entry_size + 1) * sizeof(char)); //allocates memory for a new array of elements
	if (tmp == NULL) { return ERROR; } //end if memory allocation failed
	/*
	check pointers. if some of them NULL -> end the program or return ERROR.
	It's need for the correct program operation.
	*/
	if (before == NULL) { return ERROR; }
	if (entry == NULL) { return ERROR; }
	if (*argz == NULL) { return ERROR; }
	
	while (ptr = argz_next(*argz, *argz_len, ptr))  //check the entry str in our list of fields
		if (strcmp(before, ptr) == 0) k++; //if we found str in fields, k>0 and we can continue the program. (we need to replace this field)
	if (k == 0) { return ERROR; }
	
	while (ptr = argz_next(*argz, *argz_len, ptr)) {
		if (strcmp(ptr, before) != 0) {
			strcpy(tmp + i, ptr);
			i += strlen(ptr) + 1;
		}
		else {
			strcpy(tmp + i, entry);
			i += strlen(entry);
			
			strcpy(tmp + i, "\0");
			i += 1;

			strcpy(tmp + i, ptr);
			i += strlen(ptr) + 1;
		}
	}
	free(*argz); //remove the memory by the pointer
	*argz = tmp; //point to a new memory cell
	*argz_len = *argz_len + entry_size + 1; //change the number of characters
	return OK;
}

error_t argz_replace(char **argz, size_t *argz_len, const char *str, const char *with) {
	unsigned int i = 0, k = 0; // variable for check the entry str in our list of fields
	const unsigned int str_size = strlen(str), with_size = strlen(with); //size of str which we have to replace & size of word which we have to insert
	char *ptr = NULL; // pointer for pass through the fields
	char *tmp = (char*)malloc(((*argz_len - str_size) + with_size) * sizeof(char)); //allocates memory for a new array of elements
	if (*tmp == NULL) { return ERROR; } //end if memory allocation failed
	
	if (str == NULL) { return ERROR; }      
	if (with == NULL) { return ERROR; }   //check poiters. if some of them NULL -> end the program or return ERROR.
	if (*argz == NULL) { return ERROR; } //It's need for the correct program operation.

	while (ptr = argz_next(*argz, *argz_len, ptr))  //check the entry str in our list of fields
		if (strcmp(str, ptr) == 0) k++; //if we found str in fields, k>0 and we can continue the program. (we need to replace this field)
	if (k == 0) { return ERROR; }

	while (ptr = argz_next(*argz, *argz_len, ptr)) {
		if (strcmp(ptr, str) != 0) {
			strcpy(tmp + i, ptr);
			i += strlen(ptr) + 1;
		}
		else {
			strcpy(tmp + i, with);
			i += with_size + 1;
			strcpy(tmp + i, ptr);
		}
	}
	
	free(*argz); //remove the memory by the pointer
	*argz = tmp; //point to a new memory cell
	*argz_len = *argz_len - str_size + with_size; //change the number of characters
	return OK;
}

/*
prints argz vector 
this function prints all elements in this lab
*/
void argz_print(const char *argz, size_t argz_len)
{
	unsigned int i = 0;
	for ( i = 0; i < argz_len; i++) //deriving element by element
	{
		if (argz[i] == '\0') printf("\\0\n"); // prints "\0"
		else printf("%c", argz[i]); // prints symbols
	}
}
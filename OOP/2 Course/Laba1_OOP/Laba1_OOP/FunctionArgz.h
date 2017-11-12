/************************************************************************
*file: argz.h
*synopsis: declarations for argz functions, types, constants
*author: Bidyak Mikhailo
*written: 26/09/2017
*last modified: 24/10/2017
************************************************************************/
#ifndef ARGZ_H  //checking the connection heder
#define ARGZ_H

/*
   Preprocessor directives that use the program. 
   Standard libraries and features.
*/
#pragma warning(disable: 4996);
#include <stdio.h>  // need for stantart functions (printf and etc..)
#include <string.h> //need for strlen, strcmp, strcpy and etc.
#include <conio.h>  // need for getch();
#include <stdlib.h> // need for malloc, calloc, realloc, exit, free and etc.

/*
	Special defined type. If "OK" (1) -> all OK and function work.
	If "ERROR" -> something wrong.
*/
typedef enum { OK, ERROR } error_t; 

//list of prototype functions
error_t argz_create_sep(const char *string, int sep, char **argz, size_t *argz_len);
size_t argz_count(const char *argz, size_t argz_len);
error_t argz_add(char **argz, size_t *argz_len, const char *str);
void argz_delete(char **argz, size_t *argz_len, char *entry);
error_t argz_insert(char **argz, size_t *argz_len, char *before, const char *entry);
char *argz_next(char *argz, size_t argz_len, char *entry);
error_t argz_replace(char **argz, size_t *argz_len, const char *str, const char *with);
void argz_print(const char *argz, size_t argz_len);

#endif /* ARGZ_H */


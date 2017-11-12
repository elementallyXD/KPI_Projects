/************************************************************************
*file: Scanner.h
*author: Bidyak Mikhailo
*written: 03/11/2017
*last modified: 03/11/2017
************************************************************************/

#ifndef SCANNER_H
#define SCANNER_H

//#include <io.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h> //strstr

typedef struct {
    int id;//унікальний ідентифікатор
	char manufacturer[128];// виготовлювач
	int year;	 // рік виготовлення
	char model[128];// найменування моделі
	float price;// ціна
	int x_size;// горизонтальний розмір області сканування
	int y_size;// вертикальний розмір області сканування
} SCAN_INFO;


void create_db(const char* csv, const char *db);
void print_db(const char*db);
int make_index(const char *db, const char *field_name);
void PrintIDX(const char *field_name);
/*FILE *CSV;
FILE *DB;*/

#endif /* SCANNER_H */

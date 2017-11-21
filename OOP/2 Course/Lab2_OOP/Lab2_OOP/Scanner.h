/************************************************************************
*file: Scanner.h
*author: Bidyak Mikhailo
*written: 03/11/2017
*last modified: 21/11/2017
************************************************************************/

#ifndef SCANNER_H
#define SCANNER_H

#include <io.h> //_chsize
#include <stdlib.h> //atof and etc.
#include <conio.h> //_getch
#include <stdio.h> //standart fucntion and etc.
#include <string.h> //strstr

#pragma warning( disable : 4244 34 ) 

typedef struct {
    int id;//унікальний ідентифікатор
	char manufacturer[128];// виготовлювач
	int year;	 // рік виготовлення
	char model[128];// найменування моделі
	float price;// ціна
	int x_size;// горизонтальний розмір області сканування
	int y_size;// вертикальний розмір області сканування
} SCAN_INFO;

typedef struct {
	int rec_nmb; //number of records
	SCAN_INFO *recs; //records 
}RECORD_SET;

void create_db(const char* csv, const char *db);
void print_db(const char*db);
int make_index(const char *db, const char *field_name);
void readIDX(const char *field_name);
int manufacturer(const void*x1, const void*x2);
RECORD_SET * get_recs_by_index(const char *dba, char *indx_field);
void reindex(const char *db);
int year_cmp(const void *val1, const void *val2);
int model_cmp(const void *val1, const void *val2);
int price_cmp(const void *val1, const void *val2);
int x_size_cmp(const void *val1, const void *val2);
int y_size_cmp(const void *val1, const void *val2);
void print_rec_set(RECORD_SET *rs);
RECORD_SET* select(const char *db, const char *field, const char *value);
void add_scanner(const char *db, const char* scanner_str);
void del_scanner(const char *db, int id);

#endif /* SCANNER_H */

/***********************************************************************
*file: Scanner.c
* These functions are declared in the include file "Scanner.h".
*related files: ScannerTest.c and Scanner.h
*author: Bidyak Mikhailo
*written: 03/11/2017
*last modified: 03/11/2017
************************************************************************/

#include "Scanner.h"

void create_db(const char* csv, const char *db)
{
	SCAN_INFO *csv_point, *db_point;
	unsigned short int copy_flag = 0;
	FILE *CSV, *DB;

	csv_point = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));
	db_point = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));

	if (csv_point == NULL) return 1;
	if (db_point == NULL) return 1;

	CSV = fopen(csv, "r+");
	if (CSV == NULL) exit(1);
	DB = fopen(db, "w+");
	if (DB == NULL) exit(1);

	while (!feof(CSV)) {
		fscanf(CSV, "%[A-z0-9];%[A-z0-9];%d;%f;%d;%d\n", (csv_point->manufacturer), (csv_point->model), &(csv_point->year), &(csv_point->price), &(csv_point->x_size), &(csv_point->y_size));
		printf("%s; %s; %d; %.2f; %d; %d \n", (csv_point->manufacturer), (csv_point->model), (csv_point->year), (csv_point->price), (csv_point->x_size), (csv_point->y_size));

		if (!feof(DB)) {
			rewind(DB);
			
			while (!feof(DB))
			{
				fread(db_point, sizeof(SCAN_INFO), 1, DB);
				if ((strstr(csv_point->manufacturer, db_point->manufacturer) != 0) && (strstr(csv_point->model, db_point->model) != 0) && (csv_point->year == db_point->year) && (csv_point->price == db_point->price)) 
				{
					copy_flag = 1;
					break;
				}
				else copy_flag = 0;
			}
				
				if (copy_flag == 0) 
				{
					fseek(DB, 0, SEEK_END);
					fwrite(csv_point, sizeof(SCAN_INFO), 1, DB);
					copy_flag = 1;
				}
		}
		else fwrite(csv_point, sizeof(SCAN_INFO), 1, DB);
	}
		fclose(DB);
		fclose(CSV);
		free(csv_point);
		free(db_point);
}

void print_db(const char* db)
{
	FILE *DB, *TXT;
	SCAN_INFO *db_point;

	db_point = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));
	if (db_point == NULL) return 1;
	
	DB = fopen(db, "r");
	if (DB == NULL) return 1;

	TXT = fopen("Scanners.txt", "w");
	if (TXT == NULL) return 1;

	while (fread(db_point, sizeof(SCAN_INFO), 1, DB)) 
	{
		fprintf(TXT, "%s; %s; %d; %.2f; %d; %d \n", (db_point->manufacturer), (db_point->model), (db_point->year), (db_point->price), (db_point->x_size), (db_point->y_size));
		printf("%s; %s; %d; %.2f; %d; %d \n", (db_point->manufacturer), (db_point->model), (db_point->year), (db_point->price), (db_point->x_size), (db_point->y_size));
	}
	
	fclose(DB);
	free(db_point);
}

int make_index(const char *db, const char *field_name)
{
	FILE *DB, *IDX;
	SCAN_INFO *db_point;
	short unsigned int i = 0;

	db_point = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));
	if (db_point == NULL) return 0;
	
	DB = fopen(db, "r");
	if (DB == NULL) return 0;
	
	IDX = fopen(field_name, "w");
	if (IDX == NULL) return 0;

	//rewind(DB);
	while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
	{
		(db_point->id) = i;
		fwrite(&(db_point->id), sizeof(int), 1, IDX);
		i++;
	}

	fclose(DB);
	fclose(IDX);
	free (db_point);

	return 1;
}

void PrintIDX(const char *field_name)
{
	FILE *IDX;
	
	IDX = fopen(field_name, "r");
	if (IDX == NULL) return 0;
	
	SCAN_INFO *db_point;
	db_point = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));
	if (db_point == NULL) return 0;
	//rewind(IDX);
	while (fread(&(db_point->id), sizeof(int), 1, IDX))
	{
		printf("id %d \n", (db_point->id));
	}
	//fclose(DB);
	fclose(IDX);
	free(db_point);
}
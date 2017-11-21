/***********************************************************************
*file: Scanner.c
* These functions are declared in the include file "Scanner.h".
*related files: ScannerTest.c and Scanner.h
*author: Bidyak Mikhailo
*written: 03/11/2017
*last modified: 21/11/2017
************************************************************************/

#include "Scanner.h"

void create_db(const char* csv, const char *db)
{
	FILE *CSV, *DB, *TrueDB;
	SCAN_INFO *csv_point, *db_point;
	unsigned int copy_flag = 0, numberOfStructs = 0;
	
	csv_point = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));
	db_point = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));

	if (csv_point == NULL) return;
	if (db_point == NULL) return;

	CSV = fopen(csv, "r");
	if (CSV == NULL) return;
	DB = fopen("tmp.bin", "w+");
	if (DB == NULL) return;
		
		while (!feof(CSV)) {
			fscanf(CSV, "%[A-z0-9];%[A-z0-9];%d;%f;%d;%d\n", (csv_point->manufacturer), (csv_point->model), &(csv_point->year), &(csv_point->price), &(csv_point->x_size), &(csv_point->y_size));
			printf("%s; %s; %d; %.2f; %d; %d \n", (csv_point->manufacturer), (csv_point->model), (csv_point->year), (csv_point->price), (csv_point->x_size), (csv_point->y_size));

			if (!feof(DB)) {
				rewind(DB);

				while (!feof(DB))
				{
					fread(db_point, sizeof(SCAN_INFO), 1, DB);
					if ((strstr(csv_point->manufacturer, db_point->manufacturer) != 0) && (strstr(csv_point->model, db_point->model) != 0) && (csv_point->year == db_point->year) && (csv_point->price == db_point->price) && (csv_point->x_size == db_point->x_size) && (csv_point->y_size == db_point->y_size))
					{
						copy_flag = 1;
						break;
					}
					else copy_flag = 0;
				}
				if (copy_flag == 0)
				{
					fseek(DB, 0, SEEK_END);
					fwrite(csv_point, (sizeof(SCAN_INFO)), 1, DB);
					numberOfStructs++;
					copy_flag = 1;
				}
			}
			else 
			{
				fwrite(csv_point, sizeof(SCAN_INFO), 1, DB);
				numberOfStructs++;
			}
		}

		fclose(DB);
		fclose(CSV);
		free(csv_point);
		
		DB = fopen("tmp.bin", "r");
		if (DB == NULL) return;

		TrueDB = fopen(db, "w");
		if (TrueDB == NULL) return;
		
		fwrite(&numberOfStructs, sizeof(int), 1, TrueDB);
		while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
		{
			fwrite(db_point, sizeof(SCAN_INFO), 1, TrueDB);
		}

		free(db_point);
		fclose(DB);
		fclose(TrueDB);
		remove("tmp.bin");
}

void print_db(const char* db)
{
	FILE *DB, *TXT;
	SCAN_INFO *db_point;
	int numbersOfStructs = 0;

	db_point = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));
	if (db_point == NULL) return ;
	
	DB = fopen(db, "r");
	if (DB == NULL) return ;

	TXT = fopen("Scanners.txt", "w");
	if (TXT == NULL) return ;
	
	fread(&numbersOfStructs, sizeof(int), 1, DB);
	if (numbersOfStructs == 0) return;

	printf("\tNumber of Structs = %d\n", numbersOfStructs);
	while (fread(db_point, sizeof(SCAN_INFO), 1, DB)) 
	{
		fprintf(TXT, "%s; %s; %d; %.2f; %d; %d \n",(db_point->manufacturer), (db_point->model), (db_point->year), (db_point->price), (db_point->x_size), (db_point->y_size));
		printf("%s; %s; %d; %.2f; %d; %d \n", (db_point->manufacturer), (db_point->model), (db_point->year), (db_point->price), (db_point->x_size), (db_point->y_size));
	}
	
	fclose(DB);
	free(db_point);
}

int make_index(const char *db, const char *field_name)
{
	FILE *DB, *IDX;
	SCAN_INFO *db_point, *vect;
	short unsigned int j = 0;
	int numbersOfStructs = 0;

	db_point = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));
	if (db_point == NULL) return -1;

	DB = fopen(db, "r");
	if (DB == NULL)
	{
		free(db_point);
		return -1;
	}

	IDX = fopen(field_name, "w+");
	if (IDX == NULL) 
	{
		free(db_point);
		fclose(DB);
		return -1;
	}

	fread(&numbersOfStructs,sizeof(int),1,DB);

	vect = (SCAN_INFO*)malloc(sizeof(SCAN_INFO)*numbersOfStructs);
	while (j < numbersOfStructs)
	{
		fread(&(vect[j]), sizeof(SCAN_INFO), 1, DB);
		(vect[j].id) = j;
		j++;
	}

	if ((strcmp(field_name, "manufacturer.idx")) == 0)
		qsort(vect, numbersOfStructs, sizeof(SCAN_INFO), manufacturer);
	else if ((strcmp(field_name, "year.idx")) == 0)
		qsort(vect, numbersOfStructs, sizeof(SCAN_INFO), year_cmp);
	else if ((strcmp(field_name, "model.idx")) == 0)
		qsort(vect, numbersOfStructs, sizeof(SCAN_INFO), model_cmp);
	else if ((strcmp(field_name, "price.idx")) == 0)
		qsort(vect, numbersOfStructs, sizeof(SCAN_INFO), price_cmp);
	else if ((strcmp(field_name, "x_size.idx")) == 0)
		qsort(vect, numbersOfStructs, sizeof(SCAN_INFO), x_size_cmp);
	else if ((strcmp(field_name, "y_size.idx")) == 0)
		qsort(vect, numbersOfStructs, sizeof(SCAN_INFO), y_size_cmp);

	j = 0;
	while (j < numbersOfStructs)
	{
		fwrite(&(vect[j]), sizeof(int), 1, IDX);
		j++;
	}

	free(vect);
	fclose(DB);
	fclose(IDX);
	free(db_point);

	return 1;
}

void readIDX(const char *field_name)
{
	FILE *IDX;
	int x = 0;

	IDX = fopen(field_name, "rb");
	if (IDX == NULL) return;

	while (fread(&x, sizeof(int), 1, IDX)) {
		printf(" %d ", x);
	}
	printf("\n\n");
	fclose(IDX);
}

int manufacturer (const void *x1, const void *x2)
{
	return strcmp(((SCAN_INFO*)x1)->manufacturer, ((SCAN_INFO*)x2)->manufacturer) >= 0;
		//&& strcmp(((SCAN_INFO*)x1)->model, ((SCAN_INFO*)x2)->model) >= 0;
}

int year_cmp(const void *val1, const void *val2)
{
	return ((SCAN_INFO*)val1)->year - ((SCAN_INFO*)val2)->year;
}

int model_cmp(const void *val1, const void *val2)
{
	return strcmp(((SCAN_INFO*)val1)->model, ((SCAN_INFO*)val2)->model);
}

int price_cmp(const void *val1, const void *val2)
{
	return ((SCAN_INFO*)val1)->price - ((SCAN_INFO*)val2)->price;
}

int x_size_cmp(const void *val1, const void *val2)
{
	return ((SCAN_INFO*)val1)->x_size - ((SCAN_INFO*)val2)->x_size;
}

int y_size_cmp(const void *val1, const void *val2)
{
	return ((SCAN_INFO*)val1)->y_size - ((SCAN_INFO*)val2)->y_size;
}

RECORD_SET *get_recs_by_index(const char *dba, char *indx_field)
{
	FILE *DB, *IDX;
	RECORD_SET *rec;
	int i, fieldID;
	
	if ((IDX = fopen(indx_field, "rb+")) == NULL)
	{
		return NULL;
	}

	if ((DB = fopen(dba, "rb")) == NULL)
	{
		fclose(IDX);
		return NULL;
	}

	if ((rec = (RECORD_SET*)malloc(sizeof(int) + sizeof(SCAN_INFO*))) == NULL)
	{
		fclose(IDX);
		fclose(DB);
		return NULL;
	}

	fread(&(rec->rec_nmb), sizeof(int), 1, DB);
	if ((rec->recs = (SCAN_INFO*)malloc((rec->rec_nmb)* (sizeof(SCAN_INFO)))) == NULL)
	{
		free(rec);
		fclose(IDX);
		fclose(DB);
		return NULL;
	}

	for (i = 0; i < rec->rec_nmb; i++)
	{
		fread(&fieldID, sizeof(int), 1, IDX);
		fseek(DB, fieldID * sizeof(SCAN_INFO) + sizeof(int), SEEK_SET);
		fread(&(rec->recs[i]), sizeof(SCAN_INFO), 1, DB);
	}
	fclose(DB);
	fclose(IDX);
	
	return rec;
}

RECORD_SET* select(const char *db, const char *field, const char *value)
{
	FILE *DB;
	RECORD_SET *rec;
	SCAN_INFO *db_point;
	int numbersOfStructs = 0, i = 0;
	float val;
	
	if ((DB = fopen(db, "rb")) == NULL)
	{
		return NULL;
	}

	if ((db_point = (SCAN_INFO*)malloc(sizeof(SCAN_INFO))) == NULL)
	{
		fclose(DB);
		return NULL;
	}

	if ((rec = (RECORD_SET*)malloc(sizeof(int) + sizeof(SCAN_INFO*))) == NULL)
	{
		free(db_point);
		fclose(DB);
		return NULL;
	}

	rec->rec_nmb = 0;
	fread(&numbersOfStructs, sizeof(int), 1, DB);

	if ((strcmp(field, "manufacturer")) == 0)
	{
		while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
			if ((strcmp(db_point->manufacturer, value)) == 0)
				rec->rec_nmb++;
		if ((rec->recs = (SCAN_INFO*)malloc((rec->rec_nmb)*(sizeof(SCAN_INFO)))) == NULL)
		{
			free(db_point);
			free(rec);
			fclose(DB);
			return NULL;
		}
		fseek(DB, sizeof(int), SEEK_SET);
		while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
			if ((strcmp(db_point->manufacturer, value)) == 0)
			{
				(rec->recs[i]) = *db_point;
				i++;
			}

		if (i <= 0)
		{
			printf("Fuction \"Select\" can't find this value");
			return NULL;
		}
	}

	else if ((strcmp(field, "model")) == 0)
	{
		while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
			if ((strcmp(db_point->model, value)) == 0)
				rec->rec_nmb++;
		if ((rec->recs = (SCAN_INFO*)malloc((rec->rec_nmb)* (sizeof(SCAN_INFO)))) == NULL)
		{
			free(db_point);
			free(rec);
			fclose(DB);
			return NULL;
		}
		fseek(DB, sizeof(int), SEEK_SET);
		while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
			if ((strcmp(db_point->model, value)) == 0)
			{
				(rec->recs[i]) = *db_point;
				i++;
			}

		if (i <= 0)
		{
			printf("Fuction \"Select\" can't find this value");
			return NULL;
		}
	}

	else if ((strcmp(field, "year")) == 0)
	{
		while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
			if (db_point->year == atoi(value))
				rec->rec_nmb++;
		if ((rec->recs = (SCAN_INFO*)malloc((rec->rec_nmb)* (sizeof(SCAN_INFO)))) == NULL)
		{
			free(db_point);
			free(rec);
			fclose(DB);
			return NULL;
		}
		fseek(DB, sizeof(int), SEEK_SET);
		while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
			if (db_point->year == atoi(value))
			{
				(rec->recs[i]) = *db_point;
				i++;
			}
			if( i <= 0)
			{
				printf("Fuction \"Select\" can't find this value");
				return NULL;
			}
	}

	else if ((strcmp(field, "price")) == 0)
	{
		val = atof(value);
		while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
			if (db_point->price == val)
				rec->rec_nmb++;
		if ((rec->recs = (SCAN_INFO*)malloc((rec->rec_nmb)* (sizeof(SCAN_INFO)))) == NULL)
		{
			free(db_point);
			free(rec);
			fclose(DB);
			return NULL;
		}
		fseek(DB, sizeof(int), SEEK_SET);
		while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
			if (db_point->price == val)
			{
				(rec->recs[i]) = *db_point;
				i++;
			}

		if (i <= 0)
		{
			printf("Fuction \"Select\" can't find this value");
			return NULL;
		}
	}

	else if ((strcmp(field, "x_size")) == 0)
	{
		while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
			if (db_point->x_size == atoi(value))
				rec->rec_nmb++;
		if ((rec->recs = (SCAN_INFO*)malloc((rec->rec_nmb)* (sizeof(SCAN_INFO)))) == NULL)
		{
			free(db_point);
			free(rec);
			fclose(DB);
			return NULL;
		}
		fseek(DB, sizeof(int), SEEK_SET);
		while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
			if (db_point->x_size == atoi(value))
			{
				(rec->recs[i]) = *db_point;
				i++;
			}

		if (i <= 0)
		{
			printf("Fuction \"Select\" can't find this value");
			return NULL;
		}
	}

	else if ((strcmp(field, "y_size")) == 0)
	{
		while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
			if (db_point->y_size == atoi(value))
				rec->rec_nmb++;
		if ((rec->recs = (SCAN_INFO*)malloc((rec->rec_nmb)* (sizeof(SCAN_INFO)))) == NULL)
		{
			free(db_point);
			free(rec);
			fclose(DB);
			return NULL;
		}
		fseek(DB, sizeof(int), SEEK_SET);
		while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
			if (db_point->y_size == atoi(value))
			{
				(rec->recs[i]) = *db_point;
				i++;
			}

		if (i <= 0)
		{
			printf("Fuction \"Select\" can't find this value");
			return NULL;
		}
	}
	fclose(DB);
	return rec;
}

void reindex(const char *db)
{
	make_index(db, "manufacturer.idx");
	make_index(db, "year.idx");
	make_index(db, "model.idx");
	make_index(db, "price.idx");
	make_index(db, "x_size.idx");
	make_index(db, "y_size.idx");
}

void print_rec_set(RECORD_SET *rs)
{
	int i;
	if (rs == NULL) return;
	for (i = 0; i < rs->rec_nmb; i++)
		printf("%s;%s;%d;%.2f;%d;%d\n", (rs->recs[i].manufacturer), (rs->recs[i].model), rs->recs[i].year, rs->recs[i].price, rs->recs[i].x_size, rs->recs[i].y_size);
}

void add_scanner(const char *db, const char* scanner_str)
{
	FILE *DB;
	SCAN_INFO *db_point;
	int numbersOfStructs;
	
	db_point = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));
	if (db_point == NULL) return;

	if ((DB = fopen(db, "rb+")) == NULL)
		exit(1);
	
	fread(&numbersOfStructs, sizeof(int), 1, DB);
	numbersOfStructs +=1;
	
	fseek(DB, 0, SEEK_SET);
	fwrite(&numbersOfStructs, sizeof(int), 1, DB);
	sscanf(scanner_str, "%[A-z0-9];%[A-z0-9];%d;%f;%d;%d", &(db_point->manufacturer), &(db_point->model), &(db_point->year), &(db_point->price), &(db_point->x_size), &(db_point->y_size));
	fseek(DB, 0, SEEK_END);
	fwrite(db_point, sizeof(SCAN_INFO), 1, DB);
	
	fclose(DB);
}

void del_scanner(const char *db, int id)
{
	FILE *DB;
	SCAN_INFO *db_point;
	int numbersOfStructs, offsetStructs = -2;

	DB = fopen(db, "rb+");
	if (DB == NULL) return;

	fread(&numbersOfStructs, sizeof(int), 1, DB);
	numbersOfStructs -= 1;
	fseek(DB, 0, SEEK_SET);
	fwrite(&numbersOfStructs, sizeof(int), 1, DB);
	
	db_point = (SCAN_INFO*)malloc(sizeof(SCAN_INFO));
	if (db_point == NULL) return;
	
	fseek(DB, (id + 1) * sizeof(SCAN_INFO) + sizeof(int), SEEK_SET);
	while (fread(db_point, sizeof(SCAN_INFO), 1, DB))
	{
		fseek(DB, offsetStructs * sizeof(SCAN_INFO), SEEK_CUR);
		fwrite(db_point, sizeof(SCAN_INFO), 1, DB);
		fseek(DB, sizeof(SCAN_INFO), SEEK_CUR);
	}
	_chsize(_fileno(DB), numbersOfStructs * sizeof(SCAN_INFO) + sizeof(int));
	
	free(db_point);
	fclose(DB);
}
/***********************************************************************
*file: ScannerTest.c
*These functions are declared in the include file "Scanner.h".
*author: Bidyak Mikhailo
*written: 03/11/2017
*last modified: 21/11/2017
************************************************************************/

#include "Scanner.h"

int main() 
{
	printf("\t\t\tDATA BASE LAB - 2\n\tFirst List of Scanners CSV FILE:\n");
	
	create_db("Scanners.csv", "db.bin");
	printf("\n\t First List of Scanners DB file:\n");
	print_db("db.bin");
	
	reindex("db.bin");
	
	printf("\nAdd scanner: \"ASUS;AS1055;2016;199.99;1210;1997\"\n");
	add_scanner("db.bin", "ASUS;AS1055;2016;199.99;1210;1997");
	print_db("db.bin");
	reindex("db.bin");
	
	printf("\nDell scanner with 5 id: \n");
	del_scanner("db.bin", 5);
	print_db("db.bin");
	reindex("db.bin");

	printf("\nFuction Select: \n");
	RECORD_SET* rs = select("db.bin", "year", "2016");
	print_rec_set(rs);
	
	printf("\n\tIDX file_name: \n");
	readIDX("manufacturer.idx");

	printf("\tFunction recs_by_index: \n");
	rs = get_recs_by_index("db.bin", "manufacturer.idx");
	print_rec_set(rs);
	
	_getch();
	return 0;
}


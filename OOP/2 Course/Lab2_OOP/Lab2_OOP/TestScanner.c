/***********************************************************************
*file: ScannerTest.c
*These functions are declared in the include file "Scanner.h".
*author: Bidyak Mikhailo
*written: 03/11/2017
*last modified: 03/11/2017
************************************************************************/

#include "Scanner.h"

int main() 
{
	printf("\t\t\tDATA BASE LAB - 2\n\tFirst List of Scanners:\n");
	create_db("Scanners.csv", "db.bin");
	printf("\n\t DB file:\n");
	print_db("db.bin");

	if (make_index("db.bin", "Index.idx") == 1) PrintIDX("Index.idx");
	else 
	{
		printf("Error");
		exit(1);
	}


	/*reindex("Scanners.db");

	add_scanner("Scanners.db", "Asus;AS1055;2009;99.99;210;297");
	print_db("Scanners.db");

	del_scanner("Scanners.db", 5);
	print_db("Scanners.db");

	RECORD_SET* rs = select("Scanners.db", "manufacturer", "Asus");
	print_rec_set(rs);

	rs = get_recs_by_index("Scanners.db", "manufacturer");
	print_rec_set(rs); */
	_getch();
	return 0;
}


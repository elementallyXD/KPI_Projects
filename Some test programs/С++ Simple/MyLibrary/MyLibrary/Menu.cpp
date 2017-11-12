#include "Library.h"
#include "Header.h"

using namespace std;
using namespace BL;

void menu1()
//функція меню
{
	char key;
	printf("|__________________________________________________________________|\n");
	rrand();
	printf("|__________________________________________________________________|");

	printf(" \n\n Do you need more rand? (y/n)");
	scanf_s("%d", &key);
	if (key = 'y') {
		key = ' ';
		menu1();
	}
	else printf("Program close");

}
#include "Main.h"
#include "Find.h"
#include "Write.h"
#include "Out.h"
#include "Menu.h"
#include <conio.h>

int main(void) 
{
	srand(time(NULL));
	printf("\t\tLab 1; Bidyak V-2 KV-61\n");

	Menu();

	printf("\nPress any key for exit");
	_getch(); // wait for keyword
	return 0;
}
#include "Menu.h"
#include "Main.h"

void Menu() 
{
	printf("\t\tMenu\n");

	printf("\tChoose the write mode:\n");
	printf("1 - Random Matrix\n2 - Write Matrix by Keyboard\n3 - Sorted Matrix\n");
	printf("Inpute WriteMode: ");
	scanf("%d", &WriteMode);

	switch (WriteMode) 
	{
		case 1:
			writeRandom();
			break;
		case 2:
			writeKeyboard();
			break;
		case 3:
			writeSorted();
			break;
		default:
			printf("Error");
			return 1;
	}

	printf("\nOur matrix:\n");
	out();
	printf("\n");

	printf("\tChoose the version mode:\n");
	printf("1 - Release version\n2 - Debug version\n");
	printf("Inpute version: ");
	scanf("%d", &VersionMode);

	switch (VersionMode) 
	{
		case 1:
			find_release();
			break;
		case 2:
			find_debug();
			break;
		default:
			printf("Error");
			break;
			return 1;
	}

	printf("\t\nDo you what to see final matrix? (1/0):");
	scanf("%d", &vision);
	switch (vision)
	{
	case 1:
		printf("\nFinal matrix:\n");
		out();
		break;
	case 0:
		break;
	default:
		printf("Error");
		break;
		return 1;
	}
}
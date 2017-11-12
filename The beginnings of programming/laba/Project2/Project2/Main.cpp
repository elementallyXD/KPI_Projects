#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "employee.h"

using namespace std;

int main (void)
{
	setlocale(LC_ALL, "Russian");
	cout << "\t\t  Класс службовець" << endl << endl;

	cout << "Cлужбовець №1:" << endl;
	employee obj1;

	cout << endl << "Службовець №2:" << endl;
	employee obj2("Fubar", 21, 4);
	obj2.GetName();
	obj2.GetAge();
	obj2.GetStage();

	cout << endl << endl << "Службовець №3:" << endl;
	employee obj3(obj2);

	employee *ob = new employee();
	delete ob;

	_getch();
	return 0;
}
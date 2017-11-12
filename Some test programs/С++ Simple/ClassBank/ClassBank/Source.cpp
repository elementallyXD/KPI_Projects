#include <iostream>
#include <conio.h>
#include "Accound.h"

using namespace std;

int main(void)
{
	cout << "\t\t:::::::::Class Accound::::::::::::" << endl;
	cout << "\tBnak Info panel" << endl;
	Accound a;
	
	a.SetID(188512369);
	cout << "ID" << a.GetID() << endl;

	a.SetName("Boiler Vasya");
	cout << "Name: " << a.GetName() << endl;

	a.SetBalance(8000054);
	cout << "Balance : " << a.GetBalance() << "$" << endl;

	_getch();
	return 0;
}
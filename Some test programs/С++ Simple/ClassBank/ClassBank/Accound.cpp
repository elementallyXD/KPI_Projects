#include "Accound.h"
#include <iostream>

Accound::Accound()
{
	ID = 0;
	Name = "";
	Balance = 0.0;
}

void Accound::SetID(int x)
{
	ID = x;
}

void Accound::SetName(char *NM)
{
	Name = NM;
}

int Accound::GetID()
{
	return ID;
}

char* Accound::GetName()
{
	return Name;
}

ui Accound::GetBalance()
{
	return Balance;
}

void Accound::SetBalance(ui Bal)
{
	Balance = Bal;
}

Accound::~Accound()
{
	printf("Des");
}

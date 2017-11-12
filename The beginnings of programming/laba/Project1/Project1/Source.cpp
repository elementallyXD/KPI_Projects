#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include <fstream>
#include <clocale>

using namespace std;
int b = 1;

struct students
{
	char name[30];
	char pr[30];
	char po[30];
	int SDA;
	int Prog;
	int Math;
	int Lin; 
	double sered;
	char zodiak[15];
};
students person[28];

void Zap()
{
	ifstream fin("text.txt");
	for (int i = 0; i<28; i++)
	{
		fin >> person[i].pr;
		cout << person[i].pr;
		fin >> person[i].name;
		cout <<person[i].name;
		fin >> person[i].po;
		fin >> person[i].SDA;
		fin >> person[i].Prog;
		fin >> person[i].Math;
		fin >> person[i].Lin;
		fin >> person[i].zodiak;
	}
	fin.close();
}
void ser()
{
	for (int i = 0; i<28; i++)
	{
		person[i].sered = (person[i].Lin + person[i].SDA + person[i].Math + person[i].Prog) / 4;
	}
}
void poisk()
{
	for (int i = 0; i<28; i++)
	{
		if ((person[i].sered >= 4) && (strcmp (person[i].zodiak,"Libra")==0))
			cout << person[i].pr << "\t" << person[i].name << "\t" << person[i].po;
	}
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "Ukr");
	Zap();
	ser();
	cout << "список студентів, знак зодіаку яких є «Терези», і при цьому їх середній бал перевищує 4.\n";
	poisk();
	_getch();
	return 0;
}
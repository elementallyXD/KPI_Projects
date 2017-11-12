#include<iostream>
#include<conio.h>
#include<iomanip>
#include <cstring>
#include<string.h>
#include <fstream>

using namespace std;qq

struct students
{
	char name[50];
	char pr[50];
	char po[50];
	int SDA;
	int Prog;
	int Math;
	int Lin;
	double sered;
	char zodiak[15];
};
students person[28];


    int size_()
    {
        char buff[255];
        ifstream fin("text.txt");
        int i=0;
        while(!fin.getline(buff, 255).eof())
        {
            i++;
        }
        fin.close();
    return i;}


void Zap(int r)
{
	ifstream fin("text.txt");
	for (int i = 0; i<r; i++)
	{
		fin >> person[i].pr;
		fin >> person[i].name;
		fin >> person[i].po;
		fin >> person[i].SDA;
		fin >> person[i].Prog;
		fin >> person[i].Math;
		fin >> person[i].Lin;
		fin >> person[i].zodiak;
	}
	fin.close();
}
void ser(int r)
{
	for (int i = 0; i<r; i++)
	{
		person[i].sered = (person[i].Lin + person[i].SDA + person[i].Math + person[i].Prog) / 4.0;
	}
}
void poisk(int r)
{
	for (int i = 0; i<r; i++)
	{
		if ((person[i].sered > 4.0) && (strcmp (person[i].zodiak,"Libra")==0))
			cout << person[i].pr << "  " << person[i].name << "  " << person[i].po<<"\n";
	}
	cout << endl;
}


int main()
{
	int k=size_()+1;
	Zap(k);
	ser(k);
	cout << "Students zodiak is \"Libra\", and serbal > 4.\n";
	poisk(k);
	_getch();
	return 0;
}

#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string.h>
using namespace std;
int b = 1;
struct students
{
	char name[30];
	char pr[30];
	char po[30];
	int SDA, Prog, Math, Lin;
	char zodiak[15];
}stud[100];
void Zap(int n)
{
	for (int i = 0; i<n; i++)
	{
		cout << "Student" << setw (3) << i + 1 << endl;

		cout << "\nEnter last name(прізвище)  ";
		cin.getline(stud[i].pr, 19, '\n');
		cout << "\nEnter name  ";
		cin >> stud[i].name;
		cout << "\nEnter surname ";
		cin >> stud[i].po;
		cout << "\nEnter SDA\n";
		cin >> stud[i].SDA;
		cout << "\nEnter Prog\n";
		cin >> stud[i].Prog;
		cout << "\nEnter math\n";
		cin >> stud[i].Math;
		cout << "\nEnter Lin\n";
		cin >> stud[i].Lin;
		cout << "\nEnter zodiak \n  Aries (Овен), Taurus (Телец), Gemini (Близнецы), Cancer (Рак), Leo (Лев),\n Virgo (Дева), Libra (Весы), Scorpio (Скорпион), Sagittarius (Стрелец),\n Capricorn (Козерог), Aquarius (Водолей), Pisces (Рыбы)\n ";
		cin >> stud[i].zodiak;

	}
}
void ser(float mas[], int n)
{
	for (int i = 0; i<3; i++)
	{
		mas[i] = (stud[i].Lin + stud[i].SDA + stud[i].Math + stud[i].Prog) / 4;
	}
}
void poisk(float mas[], int n, char S[])
{
	for (int i = 0; i<n; i++)
	{
		if ((mas[i] >= 4) && !(_stricmp(stud[i].zodiak, S)))
			cout << stud[i].pr << "\t" << stud[i].name << "\t" << stud[i].po;
	}
	cout << endl;
}


int main()
{
	int N;
	float sr[100];
	char s1[] = { "Libra" };
	setlocale(LC_ALL, "Ukr");
	cout << "Enter N: ";
	cin >> N;
	Zap(N);
	ser(sr, N);
	cout << "список студентів, знак зодіаку яких є «Терези», і при цьому їх середній бал перевищує 4.\n";
	poisk(sr, N, s1);
	_getch();
	return 0;
}
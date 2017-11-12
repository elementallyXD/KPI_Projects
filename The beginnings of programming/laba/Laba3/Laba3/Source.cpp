#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h>
const int n = 100;
using namespace std;
double mas[n][n];
double x[n];
double B[n][n];
void Zapovnennya(double );
void MatrixX(double );
void Sortuvannya(int);
void U (int);


int main()
{
	int k;
	cout << "Vveditb znachennya n=";
	cin >> k;
	Zapovnennya(k) ;
	cout << endl;
	MatrixX(k);
	cout << endl;
	Sortuvannya(k);
	cout << endl;
	U(k);


	_getch();
	return 0;
}

void Zapovnennya(double k)
{
	cout << setw(10) << "Matrix A" << endl;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			mas[i][j]=2*(j/2-3.1)*(i-3.9)-2.5*i*j;
			cout << setw(10) << mas[i][j] << " ";
		}
		cout << endl;
		}
}
	

void Sortuvannya(int k)
{
	cout <<setw (12)<< "Matrix 'A " << endl;
	int o = 0;
	int p = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (mas[i][j] > 0)
			{
				B[o][p] = mas[i][j];
				o++;
				p++;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (mas[i][j] < 0)
			{
				B[o][p] = mas[i][j];
				o++;
				p++;
			}
		}
	}
	for (int o = 0; o < k; o++) {
		for (int p = 0; p < k; p++) {
			cout << setw(10) << B[o][p] << " ";
		}
		cout << endl;
	}
}

void MatrixX(double k)
{
	cout << setw(10) << "Vector X" << endl;
	for (int i = 0; i < k; i++) {
		x[i] = mas[i][i];
		cout << setw(10) << x[i];
	}
}


void U(int k)
{
	cout << setw(14) << "Function g(x)" << endl;
	long double u = 1;
	for (int i = 1; i <= k; i++) {
		u =u* (x[i-1] + x[(k -1) - (i-1) + 1]);
	}
	cout << setw (7) << "U=" << u << endl;
}

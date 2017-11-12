#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h>
const int n = 10;
using namespace std;
double mas[n][n], x[n]; 
int l = -2;
void Zapovnennya(int);
void MatrixX(double*A,int);
void Sortuvannya(int);
void U(int);


int main()
{
	int k;
	cout << "Vveditb znachennya n=";
	cin >> k;
	Zapovnennya(k);
	cout << endl;
	Sortuvannya(k);
	cout << endl;
	MatrixX(x,k);
	cout << endl;
	U(k);


	_getch();
	return 0;
}

void Zapovnennya(int k)
{
	cout << setw(10) << "Matrix A" << endl;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			mas[i][j] = 2*(j/2-3.1)*(i-3.9)-2.5*i*j;
			cout << setw(10) << mas[i][j] << " ";
		}
		cout << endl;
	}
}


void Sortuvannya(int k)
{
	cout << setw(12) << "Matrix 'A " << endl;
	for (int i = 0; i<k; i++) {
		l = 0;
		for (int j = 0; j<k; j++) {
			if (mas[i][j] >= 0) {
				x[l] = mas[i][j];
				l++;
			}
		}
		for (int j = 0; j<k; j++) {
			if (mas[i][j]<0) {
				x[l] = mas[i][j];
				l++;
			}
		}
	
		for (int j = 0; j <k; j++) {
			mas[i][j] = x[j];
		}
	}
	for (int i = 0; i<k; i++) {
		for (int j = 0; j<k; j++) {
			cout << setw(10) << mas[i][j] << " ";
		}
		cout << endl;
	}
}

void MatrixX(double*A,int k)
{
	cout << setw(10) << "Vector X" << endl;
	for (int i = 0; i < k; i++) {
		A[i] = mas[i][i];
		cout << setw(11) << x[i];
	}
}


void U(int k)
{
	cout << setw(14) << "Function g(x)" << endl;
	long double u = 1;
	for (int i = 1; i <=k; i++) {
		u = u* (x[i] + x[k -i + 1]);
	}
	cout << setw(7) << "U=" << u << endl;
}

#include <iostream>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int n1 = 11, n2 = 9, n3 = 12;
int A[n1];
int B[n2];
int C[n3];
void Zapovnennya(int*A, int);
void Zcyv(double, int*A, int);
void Vuvod(int*A, int);


int main()
{
	int k = 6;
	Zapovnennya(A, n1);
	Zapovnennya(B, n2);
	Zapovnennya(C, n3);
	cout << endl;
	Zcyv(k, A, n1);
	Zcyv(k, B, n2);
	Zcyv(k, C, n3);
	cout << endl;
	Vuvod(A, n1);
	cout << endl;
	Vuvod(B, n2);
	cout << endl;
	Vuvod(C, n3);



	_getch();
	return 0;
}

void Zapovnennya(int*A, int n)
{
	srand(time(0));
	for (int i = 0; i<n; i++) {
		A[i] = rand() % n;
		cout << A[i] << " ";
	}
	cout << endl;
}

void Zcyv(double k, int*A, int n)
{
	double h;
	for (int j = 1; j < k; j++) {
		h = A[0];
		for (int i = 1; i < n; i++) {
			A[i - 1] = A[i];
		}
		A[n1 - 1] = h;
	}
}

void Vuvod(int*A, int n)
{
	for (int i = 0; i < n1; i++) {
		cout << A[i] << " ";
	}

}

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctime>

using namespace std;

int A[11], B[9], C[12];
const int k = 6;
int n;


void Zapovnennya (int*x, int ,char);
void Zcyv(int*x, int , int );
void Vuvod(int*x, int ,char );


int main()
{
	Zapovnennya (A,11,'A');
	Zapovnennya(B,9,'B');
	Zapovnennya(C,12,'C');
	cout << endl;
	Zcyv(A,k,11);
	Zcyv(B,k, 9);
	Zcyv(C,k, 12);
	cout << endl;
	Vuvod(A,11,'A');
	Vuvod(B,9,'B');
	Vuvod(C,12,'C');

	_getch();
	return 0;
}

void Zapovnennya(int*x,int n,char o)
{
	cout << "Vector " << o << endl;
	srand(time(0));
	for (int i = 0; i < n; i++) {
		x[i] = rand() % 100;
		cout << setw(5) << A[i] << " ";
	}
	cout << endl;
	cout << endl;
}
		

void Zcyv(int*x,int k,int n)
{	
	int h;
	for (int j = 1; j < k; j++) {
		h = x[0];
		for (int i = 1; i < n; i++) {
			x[i - 1] = x[i];
		}
		x[n - 1] = h;
		}
	}

void Vuvod(int*x,int n,char o )
{
	cout <<"Vector " << o << endl;
	for (int i = 0; i < n; i++) {
		cout << setw(5) << x[i] << " ";
	}
	cout << endl;
	cout << endl;
}

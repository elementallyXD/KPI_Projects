#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <conio.h> 
#include <iomanip>

using namespace std;

int main()
{
	cout << "\t\t Labaratorna #2 \n\n" << endl;
	cout.precision(4);

	const float a = 0, b = 3;
	int i, n = 7;
	double f1, f2, f3, h = (b - a) / n;

	cout << "|----------------------------------------------------------|" << endl;
	cout << "|" <<setw (33)<<"functions"<< setw (26)<<"|" <<endl;
	cout << "|    x     |   7e^x-4     |   2^-x/100    |    2^x-e^x/2   |" << endl;
	cout << "|----------------------------------------------------------|" << endl;

	for (i = 0; i <= n; i++) {
		double x = a + h*i;
		f1 = 7 * exp((x - 4) * log(M_E));
		f2 = exp((-x)*log(2)) / 100;
		f3 = exp(x*log(2)) - exp((x / 2)*log(M_E));
		
		cout << fixed << "|" << setw(8) << x << setw (3) << "|" << setw(9) << f1 << setw (6) << "|" << setw(9) << f2 << setw (7) <<  "|" << setw(10) << f3 << setw (7)<< "|" << endl;
		cout << "|----------------------------------------------------------|" << endl;
	}
	cout << "|"<< setw (59)<< "Bidyak M.A, KV-61|" << endl;
	cout << "|----------------------------------------------------------|" << endl;


	_getch();
	return 0;
}
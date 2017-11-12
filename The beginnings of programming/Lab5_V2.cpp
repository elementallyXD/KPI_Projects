// графік
#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	float x, a = -5;
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, 0, 90, NULL);
	LineTo(hDC, 200, 90);
	MoveToEx(hDC, 100, 0, NULL);
	LineTo(hDC, 100, 200);

	for (x = -10.0f; x <= 10.0f; x += 0.001f) // O(100,85) - center
	{
		double y = (4 * a*a*a) / (x*x + 4 * a*a);
		MoveToEx(hDC, 10 * x + 100, 10 * y + 90, NULL);//график
		LineTo(hDC, 10 * x + 100, 10 * y + 90);
	}

	_getch();
	SelectObject(hDC, Pen);   // Возвращаем старое перо
	SelectObject(hDC, Pen);   // Возвращаем старую кисть
	ReleaseDC(GetConsoleWindow(), hDC);  // Освобождаем контекст рисования
	DeleteObject(Pen);       // Удаляем созданное перо
	DeleteObject(Pen);// Удаляем созданную кисть

	COORD position;										// Объявление необходимой структуры
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// Получение дескриптора устройства стандартного вывода

	position.X = 80;				// Установка координаты X
	position.Y = 5;					// Установка координаты Y
	SetConsoleCursorPosition(hConsole, position);		// Перемещение каретки по заданным координатам
	cout << "Bidyak M.A\n";

	position.X = 45;									// Установка координаты X
	position.Y = 7;									// Установка координаты Y
	SetConsoleCursorPosition(hConsole, position);
	cout << "> X";

	position.X = 22;									// Установка координаты X
	position.Y = 0;									// Установка координаты Y
	SetConsoleCursorPosition(hConsole, position);
	cout << "^ Y";

	position.X = 40;									// Установка координаты X
	position.Y = 5;									// Установка координаты Y
	SetConsoleCursorPosition(hConsole, position);
	cout << "x^2*y=4a^2(2a-y)";

	_getch();
	return 0;
}

#include "Employee.h"

employee::employee()
{
	cout << "<< Спрацював конструктор без параметрiв >>" << endl;
}

employee::employee(char* Name, int age, int stage)
{
	cout << "<< Спрацював конструктор з параметрами >>" << endl << endl;
	SetName(Name);
	SetAge(age);
	SetStage(stage);
}

employee::employee(const employee &)
{
	cout << "<< Спрацював конструктор копiювання  >>" << endl;
}


//для установки параметрів обєкта
void employee::SetName(char* Name)
{
	strcpy_s(name, Name);
}

void employee::SetAge(int Age)
{
	age = Age;
}

void employee::SetStage(int Stage)
{
	stage = Stage;
}


//для вивода на екран обєкта
char* employee::GetName()
{
	cout << "Имя службовця: " << name;
	return  name;
}

int employee::GetAge()
{
	cout << endl << "Вiк: " << age;
	return age;
}

int employee::GetStage()
{
	cout << endl << "Стаж: " << stage;
	return stage;
}

//деструктор
employee::~employee()
{
	cout << endl << "Тут спрацював деструктор;" << endl;
}
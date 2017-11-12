#pragma once
#include <iostream>
using namespace std;

const int Lname = 20;

class employee
{
private:
	char name[Lname];
	int age;
	int stage;
public:
	employee();
	employee(char*, int, int);
	employee(const employee&);
	~employee();

	void SetName(char*);
	void SetAge(int);
	void SetStage(int);

	char* GetName();
	int GetAge();
	int GetStage();
};
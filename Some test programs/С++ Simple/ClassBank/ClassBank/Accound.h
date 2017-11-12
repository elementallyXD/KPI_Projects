#pragma once

typedef unsigned int ui;

class Accound
{
private:
	int ID;
	char *Name;
	ui Balance;
public:
	Accound();
	
	void SetID(int);
	void SetName(char*);
	void SetBalance(ui);

	int  GetID();
	char* GetName();
	ui  GetBalance();
	
	~Accound();
};


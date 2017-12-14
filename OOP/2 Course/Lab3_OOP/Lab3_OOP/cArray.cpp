#include "cArray.h"

//Сlass designer.Creates an array of integers, with "GROWBY" size.
cArray::cArray(void)
{
	RArray = new int[GROWBY];
	countsize = GROWBY;
	countelements = 0;
	upper = countsize - 1;
}

//destructor for class
cArray::~cArray(void)
{
	delete []RArray;
	countelements = 0;
}

//Gets the number of elements in this array.
int cArray::Getsize() const  
{
	return this->countsize;
}

//Gets the number of elements in this array.
int cArray::Getcount() const  
{
	return this->countelements;
}

//Returns the largest valid index.
int cArray::Getupperbound() const  
{
	return this->upper;
}

//Determines whether the array is empty.
bool cArray::IsEmpty() const  
{
	if (countelements >= 0)
	return false;
	else return true;
}

//Establishes the size of an empty or existing array; allocates memory if necessary.
void cArray::SetSize(int nnewsize)   
{
	tempArray = new int[nnewsize];
	if (nnewsize >= countsize) {
		memcpy(tempArray, RArray, countsize * sizeof(int));  
	}
	else
	{
		memcpy(tempArray, RArray, nnewsize * sizeof(int));
	}
	int *temp = RArray;
	RArray = tempArray;
	countsize = nnewsize;
	upper = nnewsize - 1;
	delete []temp;
}

//Adds an element to the end of the array; grows the array if necessary.
void cArray::Add(int n)  
{
	if (upper < 0) SetSize(this->countsize + GROWBY);
	RArray[upper] = n;
	countelements++;
	upper--;
}

//Removes all the elements from this array.
void cArray::RemoveAll()  
{
	delete []RArray;
	countelements = 0;
	RArray = new int[countsize];
	upper = countsize - 1;
}

//Frees all unused memory above the current upper bound.
void cArray::FreeExtra()
{
	unsigned int nnewsize = upper + 1;
	
	SetSize(nnewsize);
	countsize = nnewsize;
	countelements = 0;
	upper = nnewsize - 1;
}

//Returns the value at a given index.
int cArray::GetAt(int indx)
{
	if ((indx < this->countsize)&&(indx >= 0))
	return this->RArray[indx];
}

//Sets the value for a given index; array not allowed to grow.
void cArray::SetAt(int n, int indx)
{									
	if ((indx < countsize)&&(indx >= 0))
	RArray[indx] = n;				
	
	if(indx <= upper)
	countelements++;

	upper = indx - 1;
}

//Appends another array to the array; grows the array if necessary
void cArray::Append(cArray *ar)
{
	if (ar == NULL) return;
	for (int i = 0; i < ar->countelements; i++)
	{
		if (ar->countelements > this->countsize) SetSize(this->countsize + GROWBY);
		this->RArray[this->countsize-i-1] = ar->RArray[ar->countsize-i-1];	
	}
	this->countelements = ar->countelements;
	upper = countsize - countelements - 1;
}

//Copies another array to the array; grows the array if necessary.
void cArray::Copy(cArray * ar)
{
	if (ar == NULL) return;
	countelements = 0;
	countsize = 0;
	upper = 0;

	Append(ar);
}

//func for out in console value of massive
void cArray::PrintfCounts()
{
	for (int i = 0; i < this->countsize; i++)
	{
		printf("indx %d = %d\n", i ,this->GetAt(i));
	}
}

//func for out private counts
void cArray::PrintPrivate()
{
	printf("Sizeof cArray =  %d\n", this->Getsize());
	printf("Count Elements = %d\n", this->Getcount());
	printf("Getupperbound = %d\n\n", this->Getupperbound());
}

//Inserts an element at a specified index.
void cArray::InsertAt(int n, int indx)
{
	int tmp = countsize, delta = tmp - indx;
	for (int i = 0; i < delta; i++)
	{
		if ((indx >= countsize)||( (tmp >= countsize ))) SetSize(countsize + GROWBY);
		RArray[tmp - i] = RArray[tmp - i - 1]; //offset to the right for a new element
	}
	
	if ((countsize > indx)&&(indx >= 0))
	{
		if (RArray[indx] <= 0) countelements++;  
		RArray[indx] = n;
	}
	upper = countelements + 1;
}

//Sets or gets the element at the specified index.
int& cArray::operator[](int indx)
{
	if ((indx < countsize) && (indx >= 0))
	return this->RArray[indx];
}

//Removes an element at a specific index.
void cArray::RemoveAt(int indx)
{
	if ((indx >= 0) && (indx < countsize) && (RArray[indx] >= 0))
	{
		upper++;
		countelements--;
	}

	for (int i = 0; i < (countsize - indx); i++)
		RArray[indx + i] = RArray[indx + i + 1]; //shift to the left
}
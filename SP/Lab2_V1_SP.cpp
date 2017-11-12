#include "stdio.h"
#include <iostream>
#include "time.h"

int A[8];
int k;

int asm_func1()
{
	_asm
	{
		mov k, 1
		mov EAX, 0 // i = 0
		repeat:
		mov ECX, k
		shl ECX, 1
		mov EBX, k
		add EBX, EAX // j = i + k * 2
		cmp EBX, 11
		jbe SHORT if_not
		jmp if_end
		if_not:
		inc k
		if_end:
		mov ECX, k
		mov DWORD PTR A[EAX], ECX
		add EAX, 4
		cmp EAX, 8
		jb SHORT repeat
	}

	for (int i = 0; i < 8; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}

int asm_func2()
{
	int i, j;

	_asm
	{
		mov k, 1
		mov i, 0
		repeat:
		mov eax, k
		mov ecx, DWORD PTR i
		lea edx, DWORD PTR [ECX+eax*2]
		mov	DWORD PTR j, edx
		cmp DWORD PTR j, 11
		jle SHORT if_not
		mov EAX, DWORD PTR j
		mov ECX, DWORD PTR i
		mov DWORD PTR A[EAX*4], ECX
		jmp SHORT if_end
		if_not:
		mov EAX, DWORD PTR k
		add EAX, 1
		mov DWORD PTR k, EAX
		mov EAX, DWORD PTR i
		mov ECX, DWORD PTR k
		mov DWORD PTR A[EAX*4], ECX
		if_end:
		mov EAX, DWORD PTR i
		add EAX, 1
		mov DWORD PTR i, EAX
		cmp DWORD PTR i, 8
		jl SHORT repeat
	}

	for (int i = 0; i < 8; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}

int simple_func()
{
	int i, j;
	k = 1;
	i = 0;

	do
	{
		j = i + k * 2;
		if (j > 11)
			A[i] = j;
		else
		{
			k += 1;
			A[i] = k;
		}

		i++;
	} while (i < 8);

	for (i = 0; i < 8; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}

int main()
{
	int time = clock();
	simple_func();
	std::cout << "Time without asm: " << clock() - time << "ms \n \n";

	time = clock();
	asm_func2();
	std::cout << "Asm time: " << clock() - time << "ms \n \n";

	time = clock();
	asm_func1();
	std::cout << "Asm time(optimized): " << clock() - time << "ms \n \n";

	return 0;
}
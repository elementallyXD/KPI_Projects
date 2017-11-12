#include <stdio.h> 
#include <time.h>
#include <conio.h>

//our funtions:
clock_t SimpleCode();
clock_t AsmCode();
clock_t AsmOptCode();

int A[9];
int i,j; 

int main(void){ 
	/*
	call functions
	*/
	printf("Function Simple:\n");
	printf("\nSimpleCode time: %d\n\n", SimpleCode()); //function with C/C++ code
	
	printf("Function with ASM:\n"); 
	printf("\nAsmCode time : %d\n\n", AsmCode()); // function with no optimized asm code
	
	printf("Function with ASM_OPTIMIZED:\n");
	printf("\nAsmOptCode time: %d\n\n", AsmOptCode()); // function with optimized asm code
	
	_getch(); // getting eny key for end program
	/*
	end program
	*/
	return 0; 
}

clock_t SimpleCode()
{
	clock_t start, stop;
	i = 0;
	start = clock();
	
	while (i<9) {
		j = 2 * i;
		
		switch (i) {
		case 5: j += 10;
			break;
		case 6: j *= 2;
			break;
		case 7: j -= 4;
			break;
		case 8: j = 7;
			break;
		default: j++;
		}
		
		A[i] = j;
		i++;
	}
	
	stop = clock();
	
	for (i = 0; i<9; i++)
		printf("%d  ", A[i]);
	
	return stop-start;
}


clock_t AsmCode()
{
	clock_t start, stop;
	i = 0;
	start = clock();
	
	_asm {
		LN2:
		//while (i<9) {	
		cmp	 DWORD PTR i, 9; i
			jge	 end
			
		//j = 2 * i;
			mov	 eax, DWORD PTR i	; i
			shl	 eax, 1
			mov	 DWORD PTR j, eax	; j

		//switch (i) {
			mov eax, DWORD PTR i
			mov ebx, eax 
			cmp ebx, 5
			je SHORT LN9 
			cmp ebx, 6 
			je SHORT LN10
			cmp ebx, 7
			je SHORT LN11
			cmp ebx, 8
			je SHORT LN12
			jmp SHORT LN13
		
		LN9:
		//case 5: j += 10;
		mov	 eax, DWORD PTR j	; j
		add	 eax, 10
		mov	 DWORD PTR j, eax	; j
		jmp	 SHORT LN4
		
		//jmp	 SHORT $LN4@SimpleCode
		
		LN10:
		//case 6: j *= 2;
		mov	 eax, DWORD PTR j	; j
		shl	 eax, 1
		mov	 DWORD PTR j, eax	; j
		jmp	 SHORT LN4

		LN11:
		//case 7: j -= 4;
		mov	 eax, DWORD PTR j	; j
		sub  eax, 4
		mov	 DWORD PTR j, eax	; j
		jmp	 SHORT LN4

		LN12:
		//case 8: j = 7;
		mov	 DWORD PTR j, 7	; j
		jmp	 SHORT LN4
		
		LN13:
		//default: j++;
		mov	 eax, DWORD PTR j	; j
		add	 eax, 1
		mov	 DWORD PTR j, eax; j
		
		//}
		LN4:
		//A[i] = j;
		mov	 eax, DWORD PTR i	; i
		mov	 ecx, DWORD PTR j	; j
		mov	 DWORD PTR A[eax*4], ecx

		//i++;
		mov	 eax, DWORD PTR i; i
		add	 eax, 1
		mov	 DWORD PTR i, eax	; i

		//}
		jmp	 LN2

		//jmp	 SHORT _while
		end :
	}
	
	for (i = 0; i<9; i++)
		printf("%d  ", A[i]);

	stop = clock();
	return stop - start;
}

clock_t AsmOptCode() {
	clock_t start, stop;
	i = 0;
	start = clock();

	_asm {
	_while:
		//while (i<9) {	
		cmp	 i, 9
		jge	 end

		//j = 2 * i;
		mov	 eax, i
		imul eax, 2
		mov	 j, eax
		
		//switch (i) {
		cmp i, 5
		je SHORT LN9
		cmp i, 6
		je SHORT LN10
		cmp i, 7
		je SHORT LN11
		cmp i, 8
		je SHORT LN12
		jmp SHORT LN13

		LN9 :
		//case 5: j += 10;
		add	 j, 10
		jmp	 SHORT LN4

		LN10 :
		//case 6: j *= 2;
		shl	 j, 1
		jmp	 SHORT LN4

		LN11 :
		//case 7: j -= 4;
		sub  j, 4
		jmp	 SHORT LN4

		LN12 :
		//case 8: j = 7;
		mov	j, 7
		jmp	 SHORT LN4

		LN13 :
		//default: j++
		inc j
		
		LN4 :
		//A[i] = j;
		mov	 eax, i
		shl  eax, 2
		mov	 ecx,  j; 
		mov	 A[eax], ecx

		//i++;
		inc i

		jmp SHORT _while
		end:
	}
	stop = clock();

	for (i = 0; i<9; i++)
		printf("%d  ", A[i]);

	return stop - start;
}
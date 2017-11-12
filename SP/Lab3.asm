.386

Data1 segment para use16 
I1 dw ? ; має бути ДБ 
I2 dw ? 
I3 dw ?
A1 dw 6 dup (8 dup (7 dup (0)))
adress dd Code2Beg
Data1 ends 

CODE1 segment  ;пункт 1 
		assume	cs:CODE1, ds:Data1
	CODE1beg:
mov AX, Data1
mov DS, AX
mov I1, 0
mov I2, 0
mov I3, 0

 xor ax,ax
 xor bx,bx
 xor esi, esi  
 xor ecx, ecx
 xor dx,dx

imul I1,I3
imul I1,I2
mov AX,I1 ; добуто индексив

 _do:
imul BX, I1, 7*8*2
imul ECX, I2, 7*2
mov SI, I3
lea DI, [ECX+ESI*2]

mov A1[BX+DI], AX

		inc I3
		cmp I3, 6
		jl _do

	mov I3, 0
	inc I2
	cmp I2, 6
	jl _do

mov I2, 0
inc I1
cmp I1, 5
jl _do

jmp dword ptr adress
	CODE1 ends

Data2 segment para use16
	A2  dw 6 dup (8 dup (7 dup (0))) ;пункт 2 
Data2 ends

CODE2 segment use16
	assume CS:CODE2, DS:Data1, ES:Data2

CODE2Beg:
	mov AX, Data1
	mov DS, AX
	mov AX, Data2
	mov ES, AX
	
	lea DI, A2
	mov AX, 36
	mov CX, 6*8*7

	_repeat:
	repne scasw
	cmp A1[DI-2], 36 ; when CX == 0 порівняння
	jne _break
	mov A2[DI-2], DI
	cmp CX, 0
	jg _repeat
	_break:

mov	AX,	4c00h
int	21h

CODE2 ends
end CODE2Beg
end CODE1Beg
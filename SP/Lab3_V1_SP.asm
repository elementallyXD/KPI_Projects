.386

Data1 segment para use16
	I1 dw ?
	I2 dw ?
	I3 dw ?
	A1 dw 5 dup (6 dup (0fh,4 dup (0)))
	adress dd Code2Beg
Data1 ends

Code1 segment use16
	assume CS:Code1, DS:Data1
Code1Beg:
	mov AX, Data1
	mov DS, AX
	mov I1, 0
	mov I2, 0
	mov I3, 0
	
	_do:
			imul BX, I1, 6*5*2
			imul ECX, I2, 5*2
			mov SI, I3
			lea DI, [ECX+ESI*2]
			
			cmp A1[BX+DI], 0fh
			jnz short _continue
			mov AX, A1[BX+DI+2]
			add AX, A1[BX+DI+4]
			add AX, A1[BX+DI+6]
			add AX, A1[BX+DI+8]
			add AX, A1[BX+DI+10]
			mov A1[BX+DI], AX
			_continue:
			
			inc I3
			cmp I3, 5
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
Code1 ends

Data2 segment para use16
	A2 dw 5 dup (6 dup (0fh,4 dup (0)))
Data2 ends

Code2 segment use16
	assume CS:Code2, DS:Data1, ES:Data2
Code2Beg:
	mov AX, Data1
	mov DS, AX
	mov AX, Data2
	mov ES, AX
	
	lea DI, A2
	mov AX, 0fh
	mov CX, 5*6*5
	
	_repeat:
	repne scasw
	cmp A2[DI-2], 0fh ; when CX == 0
	jne _break
	mov BX, A2[DI]
	add BX, A2[DI+2]
	add BX, A2[DI+4]
	add BX, A2[DI+6]
	add BX, A2[DI+8]
	mov A2[DI-2], BX
	cmp CX, 0
	jg _repeat
	_break:
	
	mov CX, 5*6*5
	lea SI, A1
	lea DI, A2
	repe cmpsw
	je _equal
	mov AX, 0AAAh ; not equal
	_equal:
	
	mov	AX,	4c00h
	int	21h
Code2 ends
end Code1Beg
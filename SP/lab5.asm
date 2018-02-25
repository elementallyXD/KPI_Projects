.386
Data segment 
	_es dw 0b800h; сегментна адреса відеобуфера
	_data dw Data
	_color db ?
Data ends
Code segment 
	assume cs:Code, ds:Data
HookMouse proc far
	push ds    
	push es
	push		_es ; сегментна адреса відеобуфера
	pop 		es	
	push 		_data ; 
	pop ds
	add _color,00010000b
	mov bl,_color

	mov dh,1; задаємо перший рядок 
	mov dl,1; задаємо перший стовпчик
	mov al,0; атрибут символа (код аскі)
	mov cx,1; кількість сиволів , що виводиться
	_loop:
	mov dl,1

	_loop2:
	mov ah,02h ; переміщення курсору на нову позицію
	int 10h
	mov ah,09h; виведення символу
	int 10h
	
	add dl,2 ; переходимо до наступного непарного стовпчика
	cmp dl,80 ; перевірка кількості стовпців
	jbe _loop2
	
	
	add dh,2 ; переходимо до наступного непарного рядка
	cmp dh, 25 ; перевірка кількості рядків
	jbe _loop
	
	pop es
	pop ds

retf
HookMouse endp



Begin:
	 ; устанавливаем текстовый режим 80х25(16 цветов,4 видеостраницы)
	;mov ax, 13h
	;int 10h
	mov ax,0003h
int 10h
	
	
	; инициализируем мышь
	xor	ax,	ax
	int 33h
	
	; отображаем курсор
	mov ax, 01h
    int 33h
	
	
	
	
	; задаем пользовательский обработчик сообщений мыши
	mov ax, 0ch
	mov cx, 00001000b; отпускание правой и  кнопки
	push cs
	pop es
	lea dx, HookMouse; es:dx - адрес обработчика
	int 33h
	
	; ожидаем нажатия любой клавиши клавиатуры
	mov ah, 00h
	int 16h
	
	; отменяем обработчик сообщений мыши
	xor cx, cx
	mov ax, 0ch
	int 33h

	mov ax, 4c00h
	int 21h
Code ends
end Begin
code	segment			; 76543210	10011101
		assume	cs:code ; 30263314	11101101

begin:
	mov dl, 10011101b	; вносим входной операнд в регистр dl
	xor dh, dh

	; 7, 2
	mov ah, dl
	and ah, 00001000b
	mov cl, 4
	shl ah, cl
	or  dh, ah

	mov cl, 5
	shr ah, cl
	or  dh, ah

	; 6
	mov ah, dl
	and ah, 00000001b
	mov cl, 6
	shl ah, cl
	or  dh, ah

	; 5
	mov ah, dl
	and ah, 00000100b
	mov cl, 3
	shl ah, cl
	or  dh, ah

	; 4
	mov ah, dl
	and ah, 01000000b
	mov cl, 2
	shr ah, cl
	or  dh, ah

	; 0
	mov ah, dl
	and ah, 00010000b
	mov cl, 4
	shr ah, cl
	or  dh, ah

	nop

	mov ax, 4c00h
	int 21h
code ends
	 end begin


;Вариант 2 КВ-61
code    SEGMENT 		
		ASSUME   cs:code ; assume информирует ассемблер о СОДЕРЖИМОМ 
				         ; сегментных регистров
;76543210    10101101				         
;16710656    00101010
begin: 
	mov      dl,10101101b  ; загрузка регистра dl содержимым 
	xor      dh,dh         ; обнуляемо регистр dh
	                          
	mov      ah,dl
	and      ah,01000000b 
	;OR       dh,ah        ;число в 6 розряде
	mov      cl, 4
	SHR      ah, cl
	OR       dh,ah
	mov      cl, 2
	SHR      ah, cl
	OR       dh,ah

	mov ah,dl
	and ah,000000100b
	mov cl,4
	shl ah,cl
	or dh,ah

	mov      ah,dl         ;число в 1 розряде
	and      ah,00000010b
	mov      cl,3
	shl      ah,cl
	or       dh,ah
	shl      ah,cl
	or       dh,ah

	mov      ah,dl			;число в 0 розряде
	and      ah,00000001b
	mov      cl,3
	shl      ah,cl
	or       dh,ah

	mov      ah,dl		   ;число в 7 розряде
	and      ah,10000000b
	mov      cl,2
	shr      ah,cl
	or       dh,ah

	mov      ah,dl         ;число в 5 розряде
	and      ah,00100000b
	mov      cl,4
	shr      ah,cl
	or       dh,ah         ;результат помещен в dh

	nop                  ; команда "нет операции" 
						; место останова для отладчика 
	nop          
	mov      ax,4c00h   ; выход в MS-DOS 
	int      21h 
				 
	code          ENDS 
end      begin 


section '.data' data readable writeable align 16



	;struc File{
	;	.text			dq 0		;
	;}
	


	; Used with address offsets
	;virtual at 0
	;	Element Element
	;end virtual

	; ---- Structures
	;element Element


	fileAddr db 'C:\Users\Qualitest\Desktop\1100111b.txt',0
	fileHandleAddr dq 0
	fileValue db 'A',0
	bytesWritten dq 0
	valueSize dq 0
	;newElementMsg db 'New Element',0

section '.text' code readable writeable executable align 16

macro newFile fileNameAddr,handleAddr

	sub rsp, 8*8
	mov qword [rsp+6*8], 0					;hTemplateFile
	mov qword [rsp+5*8], 128 				;dwFlagsandAttributes
	mov qword [rsp+4*8], 000000100b 			;dwCreationDisposition
	mov r9, 0 						;lpSecurityAttributes
	mov r8, 000000010b 					;dwShareMode
	mov rdx, 10100000000000000000000100000101b		;dwDesiredAccess
	mov rcx, fileNameAddr
	call [CreateFile]
	add rsp, 8*8
	mov [handleAddr], rax

	mov rcx, [handleAddr]
	sub rsp, 8*4
	call [SetEndOfFile]
	add rsp, 8*4

end macro

macro writeFile handleAddr,entry,size,writtenAddr

	mov rcx, [handleAddr]
	sub rsp, 8*4
	call [SetEndOfFile]
	add rsp, 8*4
	

	sub rsp, 8*8
	mov qword [rsp+4*8], 0
	mov r9, writtenAddr
	mov r8, [size]
	mov rdx, entry
	mov rcx, [handleAddr]
	call [WriteFile]
	add rsp, 8*8


end macro


macro byteAsNumeric entry

	mov rbx, 111b
	and rbx, cl
	add bl, 48
	;mov byte [entry], bl

end macro
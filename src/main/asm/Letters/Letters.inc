
section '.data' data readable writeable

	
	letterTerminator db 0

		
section '.text' code readable writeable executable ;align 16




letters.numAsLetters:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*8);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label letters.numAsLetters.debugMsgSize qword at rbp-8 
	label letters.numAsLetters.heapAddress qword at rbp-16
	label letters.numAsLetters.linearAllocationSize qword at rbp-24
	label letters.numAsLetters.num qword at rbp-32
	label letters.numAsLetters.lettersLength qword at rbp-40
	label letters.numAsLetters.numberNegative qword at rbp-48
	label letters.numAsLetters.lettersBufferReverse qword at rbp-56
	label letters.numAsLetters.lettersBufferForward qword at rbp-64
	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [letters.numAsLetters.num], rcx


	and rsp, -32
	push rbx 
	push rbp 
	push rdi 
	push rsi
	push rsp 
	push r12 
	push r13 
	push r14 
	push r15
	sub rsp, 8



	sub rsp, 8*4
	call [GetProcessHeap]
	mov [letters.numAsLetters.heapAddress], rax
	add rsp, 8*4


	mov rcx, 0
	add rcx, ListItem.next
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, 200			; 200 bytes		
	mov rdx, 000001000b
	mov rcx, [letters.numAsLetters.heapAddress]
	call [ HeapAlloc] 
	mov [letters.numAsLetters.lettersBufferReverse], rax
	add rsp, 8*4

	sub rsp, 8*4
	mov r8, 200			; 200 bytes		
	mov rdx, 000001000b
	mov rcx, [letters.numAsLetters.heapAddress]
	call [ HeapAlloc] 
	mov [letters.numAsLetters.lettersBufferForward], rax
	add rsp, 8*4

	mov rax, 0
	mov [letters.numAsLetters.lettersLength], rax
	mov [letters.numAsLetters.numberNegative], rax

	mov rcx, [letters.numAsLetters.num]


	cmp rcx, rax
	jns letters.numAsLetters.notNegativeNum

	mov [letters.numAsLetters.numberNegative], 1
	mov rcx, [letters.numAsLetters.num]
	neg rcx
	mov [letters.numAsLetters.num], rcx

	letters.numAsLetters.notNegativeNum:


	mov rax, [letters.numAsLetters.num]
	mov rdx, 0
	mov rbx, 10
	
	mov r9, [letters.numAsLetters.lettersBufferReverse]
	mov rdi, r9
	cld


	letters.numAsLetters.divideDigit:


	idiv rbx

	cmp al, 0
	je letters.numAsLetters.terminateNumString

	add [letters.numAsLetters.lettersLength], 1
	
	mov rbx, rax

	add dl, 48
	mov rax, rdx
	mov rcx, 1
	db 10101010b	;db 0xaa	;stosb

	mov rax, rbx
	mov rdx, 0
	mov rbx, 10
	jmp letters.numAsLetters.divideDigit


	letters.numAsLetters.terminateNumString:
	
	add [letters.numAsLetters.lettersLength], 1

	add dl, 48
	mov rax, rdx
	mov rcx, 1
	db 10101010b	;db 0xaa	;stosb

	mov rax, 0
	mov rcx, 1
	db 10101010b	;db 0xaa	;stosb


	cmp [letters.numAsLetters.numberNegative], 1
	jne letters.numAsLetters.notNegativeLength

	add [letters.numAsLetters.lettersLength], 1

	letters.numAsLetters.notNegativeLength:

	mov rax, [letters.numAsLetters.lettersLength]


	mov r9, [letters.numAsLetters.lettersBufferReverse]
	mov r10, [letters.numAsLetters.lettersBufferForward]
	mov rsi, r9
	mov r8, r10
	add r8, rax
	mov rdi, r8



	mov rax, 0

	letters.numAsLetters.retrieveReverseNumString:

	std
	mov rcx, 1
	db 10101010b	;db 0xaa	;stosb

	mov rax, 0
	mov rcx, 1
	cld

	lodsb
	
	cmp rax, 0
	jne letters.numAsLetters.retrieveReverseNumString


	cmp [letters.numAsLetters.numberNegative], 1
	jne letters.numAsLetters.noSign
	
	mov rax, 0
	mov al, 150
	mov rcx, 1
	std
	db 10101010b	;db 0xaa	;stosb


	letters.numAsLetters.noSign:



	mov rax, [letters.numAsLetters.lettersBufferForward]

	


	add rsp, 8	
	pop r15 
	pop r14 
	pop r13 
	pop r12 
	pop rsp 
	pop rsi 
	pop rdi 
	pop rbp 
	pop rbx

	mov rsp, rbp
	pop rbp

	retn 0




letters.letterLength:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*4);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label letters.letterLength.letters qword at rbp-8 
	label letters.letterLength.lettersLength qword at rbp-16
	label letters.letterLength.linearAllocationSize qword at rbp-24
	label letters.letterLength.num qword at rbp-32
	;label letters.letterLength.lettersLength qword at rbp-40
	;label letters.letterLength.numberNegative qword at rbp-48
	;label letters.letterLength.lettersBufferReverse qword at rbp-56
	;label letters.letterLength.lettersBufferForward qword at rbp-64
	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [letters.letterLength.letters], rcx



	and rsp, -32
	push rbx 
	push rbp 
	push rdi 
	push rsi
	push rsp 
	push r12 
	push r13 
	push r14 
	push r15
	sub rsp, 8


	mov rdx, [letters.letterLength.letters]



	mov rax, 0
	mov rcx, 0
	not rcx
	cld
	mov rdi, rdx

	repne scasb

	
	not rcx
	dec rcx
	mov [letters.letterLength.lettersLength], rcx


	mov rax, [letters.letterLength.lettersLength]


	add rsp, 8	
	pop r15 
	pop r14 
	pop r13 
	pop r12 
	pop rsp 
	pop rsi 
	pop rdi 
	pop rbp 
	pop rbx

	mov rsp, rbp
	pop rbp

	retn 0


letters.appendLetters:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*7);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label letters.appendLetters.letters qword at rbp-8 
	label letters.appendLetters.lettersLength qword at rbp-16
	label letters.appendLetters.linearAllocationSize qword at rbp-24
	label letters.appendLetters.newLetters qword at rbp-32
	label letters.appendLetters.newLettersLength qword at rbp-40
	label letters.appendLetters.lettersLengthSum qword at rbp-48
	label letters.appendLetters.appendedLetters qword at rbp-56
	;label letters.appendLetters.lettersBufferForward qword at rbp-64
	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [letters.appendLetters.letters], rcx
	mov [letters.appendLetters.newLetters], rdx


	and rsp, -32
	push rbx 
	push rbp 
	push rdi 
	push rsi
	push rsp 
	push r12 
	push r13 
	push r14 
	push r15
	sub rsp, 8


	
	sub rsp, 8*8
	mov rcx, [letters.appendLetters.letters]	
	call letters.letterLength
	add rsp, 8*8
	mov [letters.appendLetters.lettersLength], rax

	sub rsp, 8*8
	mov rcx, [letters.appendLetters.newLetters]	
	call letters.letterLength
	add rsp, 8*8
	mov [letters.appendLetters.newLettersLength], rax

	mov rax, [letters.appendLetters.lettersLength]
	mov rcx, [letters.appendLetters.newLettersLength]

	add rax, rcx
	mov [letters.appendLetters.lettersLengthSum], rax

	mov rcx, [letters.appendLetters.lettersLengthSum]
	add rcx, 1b							; Trailing 0
	allocate rcx, letters.appendLetters.appendedLetters

	mov rsi, [letters.appendLetters.letters]
	mov rdi, [letters.appendLetters.appendedLetters]
	cld
	mov rcx, [letters.appendLetters.lettersLength]
	rep movsb

	mov rsi, [letters.appendLetters.newLetters]
	mov rdi, [letters.appendLetters.appendedLetters]
	add rdi, [letters.appendLetters.lettersLength]
	cld
	mov rcx, [letters.appendLetters.newLettersLength]
	rep movsb

	mov rsi, letterTerminator
	mov rdi, [letters.appendLetters.appendedLetters]
	add rdi, [letters.appendLetters.lettersLength]
	add rdi, [letters.appendLetters.newLettersLength]
	mov rcx, 1
	cld
	rep movsb


	mov rax, [letters.appendLetters.appendedLetters]

	add rsp, 8	
	pop r15 
	pop r14 
	pop r13 
	pop r12 
	pop rsp 
	pop rsi 
	pop rdi 
	pop rbp 
	pop rbx

	mov rsp, rbp
	pop rbp

	retn 0


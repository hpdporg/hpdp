
section '.data' data readable writeable

	struc HPDP
		label .
		.htmls dq 0
	end struc


	; Used with address offsets
	virtual at 0
		HPDP HPDP
	end virtual

	; ---- Structures
	;list List


	;newSVGMsg db 'New SVG',0
	
		
section '.text' code readable writeable executable ;align 16



hpdp:
.new:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label hpdp.new.heapAddress qword at rbp-8  
	label hpdp.new.handleAllocatedMemory qword at rbp-16
	;virtual at rbp-64
	;	.list List
	;end virtual	



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
	mov [hpdp.new.heapAddress], rax
	add rsp, 8*4
	

	mov rcx, 0
	add rcx, HPDP.htmls
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, rcx		
	mov rdx, 000001000b
	mov rcx, [hpdp.new.heapAddress]
	call [ HeapAlloc] 
	mov [hpdp.new.handleAllocatedMemory], rax
	add rsp, 8*4


	mov rbx, [hpdp.new.handleAllocatedMemory]
	add rbx, HPDP.htmls
	newList rbx
	

	;lea rax, [hpdp.new.list]
	;lea rcx, [hpdp.new.list.indexedItemIndex]

	;sub rcx, rax
	;add rcx, 1000b

	;cld

	;lea rsi, [hpdp.new.list]
	;mov rdi, [hpdp.new.handleAllocatedMemory]

	;rep movsb


	mov rax, [hpdp.new.handleAllocatedMemory]


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


hpdp.expose:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*5);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label hpdp.expose.heapAddress qword at rbp-8  
	label hpdp.expose.handleAllocatedMemory qword at rbp-16
	label hpdp.expose.hpdp qword at rbp-24 
	label hpdp.expose.htmls qword at rbp-32
	label hpdp.expose.html qword at rbp-40
	;label hpdp.expose.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [hpdp.expose.hpdp], rcx



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



	mov rbx, [hpdp.expose.hpdp]
	add rbx, HPDP.htmls
	mov rdx, [rbx]
	mov [hpdp.expose.htmls], rdx


	hpdp.expose.nextHTML:
	mov rbx, [hpdp.expose.htmls]
	mov rdx, rbx
	add rdx, List.index
	add rbx, List.itemsCount
	mov rcx, [rdx]
	mov r8, [rbx]
	cmp rcx, r8
	jnl hpdp.expose.endHTMLS

	sub rsp, 8*8
	mov rcx, [hpdp.expose.htmls]
	call list.getNextItem 
	add rsp, 8*8
	mov [hpdp.expose.html], rax

	sub rsp, 8*8
	mov rcx, [hpdp.expose.html]
	call html.expose
	add rsp, 8*8

	jmp hpdp.expose.nextHTML
	hpdp.expose.endHTMLS:

	sub rsp, 8*8
	mov rcx, [hpdp.expose.htmls]
	call list.resetIndex
	add rsp, 8*8


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


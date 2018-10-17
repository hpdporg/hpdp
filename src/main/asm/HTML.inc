
section '.data' data readable writeable

	struc HTML
		label .
		.layout dq 0
	end struc


	
	; Used with address offsets
	virtual at 0
		HTML HTML
	end virtual

	; ---- Structures
	;html HTML


	;newSVGMsg db 'New SVG',0
	
		
section '.text' code readable writeable executable ;align 16



html:
.new:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label html.new.heapAddress qword at rbp-8  
	label html.new.handleAllocatedMemory qword at rbp-16
	;virtual at rbp-64
	;	.html HTML
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
	mov [html.new.heapAddress], rax
	add rsp, 8*4
	

	mov rcx, 0
	add rcx, HTML.layout
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, rcx		
	mov rdx, 000001000b
	mov rcx, [html.new.heapAddress]
	call [ HeapAlloc] 
	mov [html.new.handleAllocatedMemory], rax
	add rsp, 8*4


	mov rbx, [html.new.handleAllocatedMemory]
	add rbx, HTML.layout
	sub rsp, 8*8
	call layout.new
	add rsp, 8*8
	mov [rbx], rax




	mov rax, [html.new.handleAllocatedMemory]


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



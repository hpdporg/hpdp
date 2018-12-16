
section '.data' data readable writeable

	struc HTML
		label .
		.layouts dq 0
		.text dq 0
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
	add rcx, HTML.text
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, rcx		
	mov rdx, 000001000b
	mov rcx, [html.new.heapAddress]
	call [ HeapAlloc] 
	mov [html.new.handleAllocatedMemory], rax
	add rsp, 8*4


	mov rbx, [html.new.handleAllocatedMemory]
	add rbx, HTML.layouts
	newList rbx
	mov rbx, [html.new.handleAllocatedMemory]
	add rbx, HTML.text
	mov rax, 0
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


html.expose:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*5);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label html.expose.heapAddress qword at rbp-8  
	label html.expose.handleAllocatedMemory qword at rbp-16
	label html.expose.html qword at rbp-24	
	label html.expose.layouts qword at rbp-32
	label html.expose.layout qword at rbp-40
	;label hpdp.expose.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.html HTML
	;end virtual	

	mov [html.expose.html], rcx

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



	mov rbx, [html.expose.html]
	add rbx, HTML.layouts
	mov rdx, [rbx]
	mov [html.expose.layouts], rdx


	html.expose.nextLayout:
	mov rbx, [html.expose.layouts]
	mov rdx, rbx
	add rdx, List.index
	add rbx, List.itemsCount
	mov rcx, [rdx]
	mov r8, [rbx]
	cmp rcx, r8
	jnl html.expose.endLayouts

	sub rsp, 8*8
	mov rcx, [html.expose.layouts]
	call list.getNextItem 
	add rsp, 8*8
	mov [html.expose.layout], rax

	sub rsp, 8*8
	mov rcx, [html.expose.layout]
	call layout.expose
	add rsp, 8*8

	jmp html.expose.nextLayout
	html.expose.endLayouts:

	sub rsp, 8*8
	mov rcx, [html.expose.layouts]
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



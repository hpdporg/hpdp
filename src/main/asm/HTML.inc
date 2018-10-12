section '.data' data readable writeable

	struc HTML{
		.text			dq 0		; Text of the HTML
	}
	


	; Used with address offsets
	virtual at 0
		HTML HTML
	end virtual

	; ---- Structures
	html HTML


	;newHTMLMsg db 'New HTML',0
	htmlStart db '<html>',0
	htmlEnd db '</html>',0

		
section '.text' code readable writeable executable ;align 16

newHTML:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2)+(8*1)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label .heapAddress qword at rbp-8  
	label .handleAllocatedMemory qword at rbp-16
	virtual at rbp-8
		.html HTML
	end virtual	


	and rsp, -32
	push rbx rbp rdi rsi rsp r12 r13 r14 r15
	sub rsp, 8

	sub rsp, 8*8
	mov rcx, newHTMLMsg
	call debugMsg2
	add rsp, 8*8


	sub rsp, 8*4
	call [GetProcessHeap]
	mov [newHTML.heapAddress], rax
	add rsp, 8*4
	

	lea rax, [newHTML.html]

	lea rcx, [newHTML.html.text]

	sub rcx, rax
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, rcx	
	mov rdx, 000001000b
	mov rcx, [newHTML.heapAddress]
	call [ HeapAlloc] 
	mov [newHTML.handleAllocatedMemory], rax
	add rsp, 8*4


	mov rax, 0
	mov [newHTML.html.text], rax
		

	lea rax, [newHTML.html]
	lea rcx, [newHTML.html.text]

	sub rcx, rax
	add rcx, 1000b

	cld

	lea rsi, [newHTML.html]
	mov rdi, [newHTML.handleAllocatedMemory]

	rep movsb

	mov rax, [newHTML.handleAllocatedMemory]

	add rsp, 8	
	pop r15 r14 r13 r12 rsp rsi rdi rbp rbx

	mov rsp, rbp
	pop rbp

	retn 0


html:
.writeTags:
	push rbp 
	mov rbp, rsp
	;mov r13, rsp
	;mov r10, [rsp+8*6]

	sub rsp, (8*14)+(8*0)
	
	;mov qword [rbp-16], r10


	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label .dispatch qword at rbp-8  
	label .ref qword at rbp-16
	label .smRef qword at rbp-24
	label .list qword at rbp-32
	label .modOrdering qword at rbp-40
	label .alloc qword at rbp-48
	label .prevIndex qword at rbp-56
	label .nextIndex qword at rbp-64
	label .allocSize qword at rbp-72
	label .metric qword at rbp-80
	label .chainStart qword at rbp-88
	label .comparisonChainStart qword at rbp-96
	label .modSize qword at rbp-104
	label .chainModSizesList qword at rbp-112


	and rsp, -32
	push rbx rbp rdi rsi rsp r12 r13 r14 r15
	sub rsp, 8

	mov [htmlFunc.html], rcx
	;mov [htmlFunc.chainStart], rdx
	;mov [htmlFunc.comparisonChainStart], r8


	mov rbx, [htmlFunc.html]
	



	add rsp, 8
	pop r15 r14 r13 r12 rsp rsi rdi rbp rbx

	mov rsp, rbp
	pop rbp

	retn 0

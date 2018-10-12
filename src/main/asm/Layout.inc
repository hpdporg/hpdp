section '.data' data readable writeable

	struc Layout{
		.text			dq 0		; Text of the Layout
	}
	


	; Used with address offsets
	virtual at 0
		Layout Layout
	end virtual

	; ---- Structures
	layout Layout


	;newLayoutMsg db 'New Layout',0
	

		
section '.text' code readable writeable executable ;align 16

newLayout:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2)+(8*7)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label .heapAddress qword at rbp-8  
	label .handleAllocatedMemory qword at rbp-16
	virtual at rbp-72
		.layout Layout
	end virtual	


	and rsp, -32
	push rbx rbp rdi rsi rsp r12 r13 r14 r15
	sub rsp, 8
	;align 16


	sub rsp, 8*8
	mov rcx, newLayoutMsg
	call debugMsg2
	add rsp, 8*8


	sub rsp, 8*4
	call [GetProcessHeap]
	mov [newLayout.heapAddress], rax
	add rsp, 8*4
	

	lea rax, [newLayout.layout]

	lea rcx, [newLayout.layout.modBuilderLayoutIndex]

	sub rcx, rax
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, rcx		;TensorRankOne size
	mov rdx, 000001000b
	mov rcx, [newLayout.heapAddress]
	call [ HeapAlloc] 
	mov [newLayout.handleAllocatedMemory], rax
	add rsp, 8*4


	mov rax, 0
	mov [newLayout.layout.modBuilder], rax
	mov rax, 0
	mov [newLayout.layout.mfLayoutRef], rax
	mov rax, 0
	mov [newLayout.layout.buildReadyFlag], rax			
	mov rax, 0
	mov [newLayout.layout.chainAllocIndex], rax
	mov rax, 0
	mov [newLayout.layout.chainAllocCount], rax
	mov rax, 0
	mov [newLayout.layout.modAllocCopyReadyFlag], rax			
	mov rax, 0
	mov [newLayout.layout.modBuilderLayoutIndex], rax			
		

	lea rax, [newLayout.layout]
	lea rcx, [newLayout.layout.modBuilderLayoutIndex]

	sub rcx, rax
	add rcx, 1000b

	cld

	lea rsi, [newLayout.layout]
	mov rdi, [newLayout.handleAllocatedMemory]

	rep movsb

	mov rax, [newLayout.handleAllocatedMemory]

	add rsp, 8	
	pop r15 r14 r13 r12 rsp rsi rdi rbp rbx

	mov rsp, rbp
	pop rbp

	retn 0


layoutFunc:
	push rbp 
	mov rbp, rsp
	;and rsp, -32					;32 alignment 
	;mov r13, rsp
	;mov r10, [rsp+8*6]

	sub rsp, (8*14)+(8*0);8*8;8*6
	;sub rsp, 8					;16 alignment (optionally even out; 9 pushes below are odd)

	;mov qword [rbp-16], r10

	mov rcx, rcx
	mov rdx, rdx
	mov r8, r8

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


	;label .deviceName qword at rbp-96
	;virtual at rbp-104;56
	;	.app APP
	;end virtual	


	and rsp, -32
	push rbx rbp rdi rsi rsp r12 r13 r14 r15
	sub rsp, 8

	mov [layoutFunc.dispatch], rcx
	mov [layoutFunc.chainStart], rdx
	mov [layoutFunc.comparisonChainStart], r8





	add rsp, 8
	pop r15 r14 r13 r12 rsp rsi rdi rbp rbx

	mov rsp, rbp
	pop rbp

	retn 0

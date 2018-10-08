section '.data' data readable writeable

	struc Element{
		.text			dq 0		; Text of the Element
	}
	


	; Used with address offsets
	virtual at 0
		Element Element
	end virtual

	; ---- Structures
	element Element


	;newElementMsg db 'New Element',0
	

		
section '.text' code readable writeable executable ;align 16


macro allocate heapAddress, size,allocationDestination
	sub rsp, 8*4
	call [GetProcessHeap]
	mov [heapAddress], rax
	add rsp, 8*4

	sub rsp, 8*4
	mov r8,  size
	mov rdx, 000001000b
	mov rcx, [heapAddress]
	call [ HeapAlloc]
	mov [allocationDestination], rax
	add rsp, 8*4
end macro


newElement:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2)+(8*7)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label .heapAddress qword at rbp-8  
	label .handleAllocatedMemory qword at rbp-16
	virtual at rbp-72
		.element Element
	end virtual	


	and rsp, -32
	push rbx rbp rdi rsi rsp r12 r13 r14 r15
	sub rsp, 8
	;align 16


	sub rsp, 8*8
	mov rcx, newElementMsg
	call debugMsg2
	add rsp, 8*8



	

	lea rax, [newElement.element]

	lea rcx, [newElement.element.modBuilderElementIndex]

	sub rcx, rax
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, rcx		;TensorRankOne size
	mov rdx, 000001000b
	mov rcx, [newElement.heapAddress]
	call [ HeapAlloc] 
	mov [newElement.handleAllocatedMemory], rax
	add rsp, 8*4


	mov rax, 0
	mov [newElement.element.modBuilder], rax
	mov rax, 0
	mov [newElement.element.mfElementRef], rax
	mov rax, 0
	mov [newElement.element.buildReadyFlag], rax			
	mov rax, 0
	mov [newElement.element.chainAllocIndex], rax
	mov rax, 0
	mov [newElement.element.chainAllocCount], rax
	mov rax, 0
	mov [newElement.element.modAllocCopyReadyFlag], rax			
	mov rax, 0
	mov [newElement.element.modBuilderElementIndex], rax			
		

	lea rax, [newElement.element]
	lea rcx, [newElement.element.modBuilderElementIndex]

	sub rcx, rax
	add rcx, 1000b

	cld

	lea rsi, [newElement.element]
	mov rdi, [newElement.handleAllocatedMemory]

	rep movsb

	mov rax, [newElement.handleAllocatedMemory]

	add rsp, 8	
	pop r15 r14 r13 r12 rsp rsi rdi rbp rbx

	mov rsp, rbp
	pop rbp

	retn 0


elementFunc:
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

	mov [elementFunc.dispatch], rcx
	mov [elementFunc.chainStart], rdx
	mov [elementFunc.comparisonChainStart], r8





	add rsp, 8
	pop r15 r14 r13 r12 rsp rsi rdi rbp rbx

	mov rsp, rbp
	pop rbp

	retn 0

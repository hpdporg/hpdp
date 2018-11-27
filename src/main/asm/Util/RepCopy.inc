
section '.data' data readable writeable


	struc RepCopy
		label .
		.offsetList dq 0
		.repeatList dq 0
	end struc


	; Used with address offsets
	virtual at 0
		RepCopy RepCopy
	end virtual


	; ---- Structures
	;list List


	;newSVGMsg db 'New SVG',0
	
		
section '.text' code readable writeable executable ;align 16


repCopy:

namespace repCopy
new:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label .heapAddress qword at rbp-8  
	label .handleAllocatedMemory qword at rbp-16
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
	mov [repCopy.new.heapAddress], rax
	add rsp, 8*4
	

	mov rcx, 0
	add rcx, RepCopy.repeatList
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, rcx		
	mov rdx, 000001000b
	mov rcx, [repCopy.new.heapAddress]
	call [ HeapAlloc] 
	mov [repCopy.new.handleAllocatedMemory], rax
	add rsp, 8*4



	sub rsp, 8*8
	call list.new
	add rsp, 8*8
	mov rbx, [repCopy.new.handleAllocatedMemory]
	add rbx, RepCopy.offsetList
	mov [rbx], rax	
	sub rsp, 8*8
	call list.new
	add rsp, 8*8
	mov rbx, [repCopy.new.handleAllocatedMemory]
	add rbx, RepCopy.repeatList
	mov [rbx], rax
	


	;lea rax, [list.new.list]
	;lea rcx, [list.new.list.indexedItemIndex]

	;sub rcx, rax
	;add rcx, 1000b

	;cld

	;lea rsi, [list.new.list]
	;mov rdi, [list.new.handleAllocatedMemory]

	;rep movsb


	mov rax, [repCopy.new.handleAllocatedMemory]


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
end namespace



namespace repCopy

; Copies 64-bit chunks only
copy:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*8);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label .heapAddress qword at rbp-8  
	label .handleAllocatedMemory qword at rbp-16
	label .repLoc qword at rbp-24 
	label .dest qword at rbp-32
	label .copyPattern qword at rbp-40
	label .repCopy qword at rbp-48
	label .repeatList qword at rbp-56
	label .offsetList qword at rbp-64
	label .offset qword at rbp-72
	label .repeat qword at rbp-80
	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [repCopy.copy.repLoc], rcx
	mov [repCopy.copy.dest], rdx
	mov [repCopy.copy.copyPattern], r8


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
	mov rcx, [repCopy.copy.copyPattern]
	call repCopy.parsePattern
	add rsp, 8*8
	mov [repCopy.copy.repCopy], rax
	mov rdx, rax
	add rdx, RepCopy.offsetList
	add rax, RepCopy.repeatList
	mov r8, [rdx]
	mov r9, [rax]
	mov [repCopy.copy.offsetList], r8
	mov [repCopy.copy.repeatList], r9
	

	.nextToken:
	mov rbx, [repCopy.copy.repeatList]
	mov rdx, rbx
	add rdx, List.index
	add rbx, List.itemsCount
	mov rcx, [rdx]
	mov r8, [rbx]
	cmp rcx, r8
	jnl repCopy.copy.endTokens

	sub rsp, 8*8
	mov rcx, [repCopy.copy.offsetList]
	call list.getNextItem
	sub rsp, 8*8
	mov [repCopy.copy.offset], rax

	sub rsp, 8*8
	mov rcx, [repCopy.copy.repeatList]
	call list.getNextItem
	sub rsp, 8*8
	mov [repCopy.copy.repeat], rax

	mov rbx, [repCopy.copy.repLoc]
	add rbx, [repCopy.copy.offset]

	mov rdx, [repCopy.copy.dest]
	add rdx, [repCopy.copy.offset]


	cld

	mov rcx, [repCopy.copy.repeat]
	mov rsi, rbx
	mov rdi, rdx
	rep movsb



	jmp repCopy.copy.nextToken
	.endTokens:
	
	
	
	
	mov rax,0

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

end namespace

namespace repCopy

parsePattern:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*11);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label .heapAddress qword at rbp-8
	label .handleAllocatedMemory qword at rbp-16
	label .repLoc qword at rbp-24
	label .tokenIndex qword at rbp-32
	label .tokenCount qword at rbp-40
	label .copyPattern qword at rbp-48
	label .offsetList qword at rbp-56
	label .repeatList qword at rbp-64
	label .offset qword at rbp-72
	label .repeat qword at rbp-80
	label .repCopy qword at rbp-88
	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [repCopy.parsePattern.copyPattern], rcx

	;11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111


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


	mov rcx, 0
	mov [repCopy.parsePattern.tokenIndex], rcx
	mov rdx, 1000b
	mov [repCopy.parsePattern.tokenCount], rdx
	

	sub rsp, 8*8
	call repCopy.new
	add rsp, 8*8
	mov [repCopy.parsePattern.repCopy], rax
	mov rdx, rax
	add rdx, RepCopy.offsetList
	add rax, RepCopy.repeatList
	mov r8, [rdx]
	mov r9, [rax]
	mov [repCopy.parsePattern.offsetList], r8
	mov [repCopy.parsePattern.repeatList], r9
	


	.nextToken:
	mov rcx, [repCopy.parsePattern.tokenIndex]
	mov rdx, [repCopy.parsePattern.tokenCount]
	cmp rcx, rdx
	jnl repCopy.parsePattern.endTokens


	mov rbx, [repCopy.parsePattern.copyPattern]
	add rbx, [repCopy.parsePattern.tokenIndex]
	mov rax, [rbx]

	mov r9, 0
	mov r10, 0

	mov r9b, al
	shr rax, 100b
	mov r10b, al


	mov rax, r10
	cmp rax, 0
	je repCopy.parsePattern.endTokens					; Blank. 0 offset is valid, but not 0 repeat count.

	mov rdx, 0
	mov rax, r9
	mov rcx, 1000b
	imul rcx									; Offset
	mov [repCopy.parsePattern.offset], rax

	mov rdx, 0
	mov rax, r10
	mov rcx, 1000b
	imul rcx									; Repeat
	mov [repCopy.parsePattern.repeat], rax

	sub rsp, 8*8
	mov rdx, [repCopy.parsePattern.offset]
	mov rcx, [repCopy.parsePattern.offsetList]
	call list.newLastItem
	add rsp, 8*8

	sub rsp, 8*8
	mov rdx, [repCopy.parsePattern.repeat]
	mov rcx, [repCopy.parsePattern.repeatList]
	call list.newLastItem
	add rsp, 8*8

	mov rcx, [repCopy.parsePattern.tokenIndex]
	add rcx, 1b
	mov [repCopy.parsePattern.tokenIndex], rcx

	jmp repCopy.parsePattern.nextToken
	.endTokens:
	



	mov rax, [repCopy.parsePattern.repCopy]

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

end namespace
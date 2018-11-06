
section '.data' data readable writeable

		
section '.text' code readable writeable executable ;align 16



namespace repCopy

copy:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*5);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label .heapAddress qword at rbp-8  
	label .handleAllocatedMemory qword at rbp-16
	label .repLoc qword at rbp-24 
	label .dest qword at rbp-32
	label .copyPattern qword at rbp-40
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





	mov rbx, [repCopy.copy.list]
	mov rdx, rbx
	add rdx, List.index
	mov rcx, 0
	mov [rdx], rcx
	mov rdx, rbx
	add rdx, List.indexedItemIndex
	mov rcx, 0
	mov [rdx], rcx
	mov rdx, rbx
	add rdx, List.firstItem
	mov rcx, 0
	mov r10, [rdx]
	mov r8, rbx
	add r8, List.indexItem
	mov [r8], r10
	



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
	sub rsp, (8*7);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label .heapAddress qword at rbp-8
	label .handleAllocatedMemory qword at rbp-16
	label .repLoc qword at rbp-24
	label .tokenIndex qword at rbp-32
	label .tokenCount qword at rbp-40
	label .copyPattern qword at rbp-48
	label .offsetList qword at rbp-56
	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [repCopy.copy.copyPattern], rcx

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
	mov [repCopy.copy.tokenIndex], rcx
	mov rdx, 1000b
	mov [repCopy.copy.tokenCount], rdx
	

	sub rsp, 8*8
	call list.new
	add rsp, 8*8
	mov [repCopy.copy.offsetList], rax


	.nextToken:
	mov rcx, [repCopy.copy.tokenIndex]
	mov rdx, [repCopy.copy.tokenCount]
	cmp rcx, rdx
	jnl repCopy.copy.endTokens


	mov rbx, [repCopy.copy.copyPattern]
	add rbx, [repCopy.copy.tokenIndex]
	mov rax, [rbx]

	mov r9, 0
	mov r10, 0

	mov r9b, al
	mov r10b, ah

	mov rdx, 0
	mov rax, r9
	mov rcx, 1000b
	imul rcx									; Offset


	mov rcx, [repCopy.copy.tokenIndex]
	add rcx, 1b
	mov [repCopy.copy.tokenIndex], rcx

	jmp repCopy.copy.nextToken
	.endTokens:
	



	mov rax, 0

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
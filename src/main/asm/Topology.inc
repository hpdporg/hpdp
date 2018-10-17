
section '.data' data readable writeable

	struc Topology
		label .
		.text dq 0
		.svgText dq 0
		.shape dq 0
		.offsetI dq 0
		.offsetJ dq 0
		.width dq 0
		.height dq 0
	end struc


	
	; Used with address offsets
	virtual at 0
		Topology Topology
	end virtual

	; ---- Structures
	;topology Topology


	topology.topologyShape:
	.letters dq 1b
	.rect dq 10b
	.ellipse dq 11b
	.line dq 100b
	.chart dq 101b
	.table dq 110b
	.arrow dq 111b

	

	;newSVGMsg db 'New SVG',0
	
		
section '.text' code readable writeable executable ;align 16



topology:
.new:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label topology.new.heapAddress qword at rbp-8  
	label topology.new.handleAllocatedMemory qword at rbp-16
	;virtual at rbp-64
	;	.topology Topology
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
	mov [topology.new.heapAddress], rax
	add rsp, 8*4
	

	mov rcx, 0
	add rcx,Topology.height
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, rcx		
	mov rdx, 000001000b
	mov rcx, [topology.new.heapAddress]
	call [ HeapAlloc] 
	mov [topology.new.handleAllocatedMemory], rax
	add rsp, 8*4



	mov rbx, [topology.new.handleAllocatedMemory]
	add rbx, Topology.text
	mov rax, 0
	mov [rbx], rax
	mov rbx, [topology.new.handleAllocatedMemory]
	add rbx, Topology.svgText
	mov rax, 0
	mov [rbx], rax
	mov rbx, [topology.new.handleAllocatedMemory]
	add rbx, Topology.shape
	mov rax, 0
	mov [rbx], rax
	mov rbx, [topology.new.handleAllocatedMemory]
	add rbx, Topology.offsetI
	mov rax, 0
	mov [rbx], rax
	mov rbx, [topology.new.handleAllocatedMemory]
	add rbx, Topology.offsetJ
	mov rax, 0
	mov [rbx], rax
	mov rbx, [topology.new.handleAllocatedMemory]
	add rbx, Topology.width
	mov rax, 0
	mov [rbx], rax
	mov rbx, [topology.new.handleAllocatedMemory]
	add rbx, Topology.height
	mov rax, 0
	mov [rbx], rax
	



	mov rax, [topology.new.handleAllocatedMemory]


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



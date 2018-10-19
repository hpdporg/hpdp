
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
	topology.topologyShape.letters dq 1b
	topology.topologyShape.rect dq 10b
	topology.topologyShape.ellipse dq 11b
	topology.topologyShape.line dq 100b
	topology.topologyShape.chart dq 101b
	topology.topologyShape.table dq 110b
	topology.topologyShape.arrow dq 111b
	topology.topologyShape.logo dq 1000b
	topology.topologyShape.region dq 1001b

	

	topologyEndTag db '/>',0
	textStartTag db '<text ',0	
	textEndTag db '</text>',0
	idStartTag db 'id="',0
	doubleQuote db '"',0
		
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

topology.getTopologyEndTag:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label topology.getTopologyEndTag.topology qword at rbp-8  
	label topology.getTopologyEndTag.shape qword at rbp-16
	;label topology.getTopologyEndTag.list qword at rbp-24 
	;label topology.getTopologyEndTag.item qword at rbp-32
	;label topology.getTopologyEndTag.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.list List
	;end virtual	

	mov [topology.getTopologyEndTag.topology], rcx




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


	mov rbx, [topology.getTopologyEndTag.topology]
	add rbx, Topology.shape
	mov rdx, [rbx]
	mov [topology.getTopologyEndTag.shape], rdx		; Cache shape

	mov rcx, [topology.getTopologyEndTag.shape]
	mov r8, [topology.topologyShape.letters]
	cmp rcx, r8
	jne topology.getTopologyEndTag.nonText

	mov rax, textEndTag
	jmp topology.getTopologyEndTag.end

	topology.getTopologyEndTag.nonText:	

	mov rax, topologyEndTag

	topology.getTopologyEndTag.end:

	

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

topology.newShape:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label topology.newShape.topology qword at rbp-8  
	label topology.newShape.shape qword at rbp-16
	;label topology.getTopologyEndTag.list qword at rbp-24 
	;label topology.getTopologyEndTag.item qword at rbp-32
	;label topology.getTopologyEndTag.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.list List
	;end virtual	

	mov [topology.newShape.topology], rcx
	mov [topology.newShape.shape], rdx

	

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


	mov rbx, [topology.newShape.topology]
	add rbx, Topology.shape
	mov rdx, [topology.newShape.shape]
	mov [rbx], rdx

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

topology.getTopologyStartTag:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label topology.getTopologyStartTag.topology qword at rbp-8  
	label topology.getTopologyStartTag.shape qword at rbp-16
	;label topology.getTopologyEndTag.list qword at rbp-24 
	;label topology.getTopologyEndTag.item qword at rbp-32
	;label topology.getTopologyEndTag.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.list List
	;end virtual	

	mov [topology.getTopologyStartTag.topology], rcx
	
	

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


	mov rbx, [topology.getTopologyStartTag.topology]
	add rbx, Topology.shape
	mov rdx, [rbx]
	mov [topology.getTopologyStartTag.shape], rdx		; Cache shape

	mov rcx, [topology.getTopologyStartTag.shape]
	mov r8, [topology.topologyShape.letters]
	cmp rcx, r8
	jne topology.getTopologyStartTag.rect

	mov rax, textStartTag
	jmp topology.getTopologyStartTag.end

	topology.getTopologyStartTag.rect:	

	topology.getTopologyStartTag.end:


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

topology.expose:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*3);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label topology.expose.heapAddress qword at rbp-8  
	label topology.expose.handleAllocatedMemory qword at rbp-16
	label topology.expose.topology qword at rbp-24	
	;label topology.expose.space qword at rbp-32
	;label topology.expose.topology qword at rbp-40
	;label hpdp.expose.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.html HTML
	;end virtual	

	mov [topology.expose.topology], rcx

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



	mov rbx, [topology.expose.topology]
	

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
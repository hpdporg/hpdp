
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
		.space dq 0	
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
	add rcx,Topology.space
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
	mov rbx, [topology.new.handleAllocatedMemory]
	add rbx, Topology.space
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
	
	mov r8, [topology.topologyShape.rect]
	cmp rcx, r8
	jne topology.getTopologyStartTag.ellipse

	mov rax, rectStartTag
	jmp topology.getTopologyStartTag.end

	topology.getTopologyStartTag.ellipse:

	mov r8, [topology.topologyShape.ellipse]
	cmp rcx, r8
	jne topology.getTopologyStartTag.line

	mov rax, ellipseStartTag
	jmp topology.getTopologyStartTag.end

	topology.getTopologyStartTag.line:

	mov r8, [topology.topologyShape.line]
	cmp rcx, r8
	jne topology.getTopologyStartTag.chart

	mov rax, lineStartTag
	jmp topology.getTopologyStartTag.end

	topology.getTopologyStartTag.chart:

	mov r8, [topology.topologyShape.chart]
	cmp rcx, r8
	jne topology.getTopologyStartTag.table

	;mov rax, chartStartTag
	jmp topology.getTopologyStartTag.end

	topology.getTopologyStartTag.table:

	mov r8, [topology.topologyShape.table]
	cmp rcx, r8
	jne topology.getTopologyStartTag.arrow

	;mov rax, tableStartTag
	jmp topology.getTopologyStartTag.end

	topology.getTopologyStartTag.arrow:

	mov r8, [topology.topologyShape.arrow]
	cmp rcx, r8
	jne topology.getTopologyStartTag.logo

	;mov rax, arrowStartTag
	jmp topology.getTopologyStartTag.end

	topology.getTopologyStartTag.logo:

	mov r8, [topology.topologyShape.logo]
	cmp rcx, r8
	jne topology.getTopologyStartTag.region

	;mov rax, logoStartTag
	jmp topology.getTopologyStartTag.end

	topology.getTopologyStartTag.region:

	mov r8, [topology.topologyShape.region]
	cmp rcx, r8
	jne topology.getTopologyStartTag.end

	;mov rax, regionStartTag
	jmp topology.getTopologyStartTag.end

	
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
	sub rsp, (8*4);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label topology.expose.heapAddress qword at rbp-8  
	label topology.expose.handleAllocatedMemory qword at rbp-16
	label topology.expose.topology qword at rbp-24	
	label topology.expose.region qword at rbp-32
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



	sub rsp, 8*8
	mov rcx, [topology.expose.topology]
	call topology.getTopologyRegion
	add rsp, 8*8
	mov [topology.expose.region], rax


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

topology.getTopologyRegion:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*7);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label topology.getTopologyRegion.heapAddress qword at rbp-8  
	label topology.getTopologyRegion.handleAllocatedMemory qword at rbp-16
	label topology.getTopologyRegion.topology qword at rbp-24	
	label topology.getTopologyRegion.region qword at rbp-32
	label topology.getTopologyRegion.space qword at rbp-40
	label topology.getTopologyRegion.nesting qword at rbp-48
	label topology.getTopologyRegion.itemMatch qword at rbp-56
	;label hpdp.expose.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.html HTML
	;end virtual	

	mov [topology.getTopologyRegion.topology], rcx

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



	mov rbx, [topology.getTopologyRegion.topology]
	add rbx, Topology.space
	mov rcx, [rbx]
	mov [topology.getTopologyRegion.space], rcx
	
	sub rsp, 8*8
	mov rcx, [topology.getTopologyRegion.space]
	call list.resetIndex
	add rsp, 8*8

	sub rsp, 8*8
	mov rdx, [topology.getTopologyRegion.topology]
	mov rcx, [topology.getTopologyRegion.space]
	call list.getNextItemMatch
	add rsp, 8*8

	
	mov rbx, [topology.getTopologyRegion.space]
	add rbx, List.itemMatch
	mov rdx, [rbx]
	mov [topology.getTopologyRegion.itemMatch], rdx
	add rdx, ItemMatch.nesting
	mov rcx, [rdx]
	mov [topology.getTopologyRegion.nesting], rcx
	

	sub rsp, 8*8
	mov rcx, [topology.getTopologyRegion.space]
	call list.getPriorItem					; Reverse once so Topology is not included in search
	add rsp, 8*8


	topology.getTopologyRegion.priorItem:
	mov rdx, [topology.getTopologyRegion.space]
	add rdx, List.index
	mov rcx, [rdx]
	cmp rcx, 0
	jl topology.getTopologyRegion.firstIndex


	sub rsp, 8*8
	mov rcx, [topology.getTopologyRegion.space]
	call list.getPriorItem
	add rsp, 8*8
	mov [topology.getTopologyRegion.region], rax

	mov [topology.getTopologyRegion.itemMatch], rdx
	add rdx, ItemMatch.nesting
	mov rcx, [rdx]
	add rcx, 1b
	mov r11, [topology.getTopologyRegion.nesting]
	cmp rcx, r11
	je topology.getTopologyRegion.firstIndex			; Found


	jmp topology.getTopologyRegion.priorItem
	topology.getTopologyRegion.firstIndex:






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
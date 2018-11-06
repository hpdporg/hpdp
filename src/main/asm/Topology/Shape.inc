
section '.data' data readable writeable

	struc Shape
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
		Shape Shape
	end virtual

	; ---- Structures
	;shape Shape


	shape.shapeShape:
	shape.shapeShape.letters dq 1b
	shape.shapeShape.rect dq 10b
	shape.shapeShape.ellipse dq 11b
	shape.shapeShape.line dq 100b
	shape.shapeShape.chart dq 101b
	shape.shapeShape.table dq 110b
	shape.shapeShape.arrow dq 111b
	shape.shapeShape.logo dq 1000b
	shape.shapeShape.region dq 1001b

	

	shapeEndTag db '/>',0	
	textEndTag db '</text>',0
	idStartTag db 'id="',0
	doubleQuote db '"',0
		
section '.text' code readable writeable executable ;align 16



shape:
.new:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label shape.new.heapAddress qword at rbp-8  
	label shape.new.handleAllocatedMemory qword at rbp-16
	;virtual at rbp-64
	;	.shape Shape
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
	mov [shape.new.heapAddress], rax
	add rsp, 8*4
	

	mov rcx, 0
	add rcx,Shape.space
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, rcx		
	mov rdx, 000001000b
	mov rcx, [shape.new.heapAddress]
	call [ HeapAlloc] 
	mov [shape.new.handleAllocatedMemory], rax
	add rsp, 8*4



	mov rbx, [shape.new.handleAllocatedMemory]
	add rbx, Shape.text
	mov rax, 0
	mov [rbx], rax
	mov rbx, [shape.new.handleAllocatedMemory]
	add rbx, Shape.svgText
	mov rax, 0
	mov [rbx], rax
	mov rbx, [shape.new.handleAllocatedMemory]
	add rbx, Shape.shape
	mov rax, 0
	mov [rbx], rax
	mov rbx, [shape.new.handleAllocatedMemory]
	add rbx, Shape.offsetI
	mov rax, 0
	mov [rbx], rax
	mov rbx, [shape.new.handleAllocatedMemory]
	add rbx, Shape.offsetJ
	mov rax, 0
	mov [rbx], rax
	mov rbx, [shape.new.handleAllocatedMemory]
	add rbx, Shape.width
	mov rax, 0
	mov [rbx], rax
	mov rbx, [shape.new.handleAllocatedMemory]
	add rbx, Shape.height
	mov rax, 0
	mov [rbx], rax
	mov rbx, [shape.new.handleAllocatedMemory]
	add rbx, Shape.space
	mov rax, 0
	mov [rbx], rax
	



	mov rax, [shape.new.handleAllocatedMemory]


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

shape.getShapeEndTag:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label shape.getShapeEndTag.shape qword at rbp-8  
	label shape.getShapeEndTag.shape qword at rbp-16
	;label shape.getShapeEndTag.list qword at rbp-24 
	;label shape.getShapeEndTag.item qword at rbp-32
	;label shape.getShapeEndTag.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.list List
	;end virtual	

	mov [shape.getShapeEndTag.shape], rcx




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


	mov rbx, [shape.getShapeEndTag.shape]
	add rbx, Shape.shape
	mov rdx, [rbx]
	mov [shape.getShapeEndTag.shape], rdx		; Cache shape

	mov rcx, [shape.getShapeEndTag.shape]
	mov r8, [shape.shapeShape.letters]
	cmp rcx, r8
	jne shape.getShapeEndTag.nonText

	mov rax, textEndTag
	jmp shape.getShapeEndTag.end

	shape.getShapeEndTag.nonText:	

	mov rax, shapeEndTag

	shape.getShapeEndTag.end:

	

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

shape.newShape:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label shape.newShape.shape qword at rbp-8  
	label shape.newShape.shape qword at rbp-16
	;label shape.getShapeEndTag.list qword at rbp-24 
	;label shape.getShapeEndTag.item qword at rbp-32
	;label shape.getShapeEndTag.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.list List
	;end virtual	

	mov [shape.newShape.shape], rcx
	mov [shape.newShape.shape], rdx

	

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


	mov rbx, [shape.newShape.shape]
	add rbx, Shape.shape
	mov rdx, [shape.newShape.shape]
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

shape.getShapeStartTag:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label shape.getShapeStartTag.shape qword at rbp-8  
	label shape.getShapeStartTag.shape qword at rbp-16
	;label shape.getShapeEndTag.list qword at rbp-24 
	;label shape.getShapeEndTag.item qword at rbp-32
	;label shape.getShapeEndTag.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.list List
	;end virtual	

	mov [shape.getShapeStartTag.shape], rcx
	
	

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


	mov rbx, [shape.getShapeStartTag.shape]
	add rbx, Shape.shape
	mov rdx, [rbx]
	mov [shape.getShapeStartTag.shape], rdx		; Cache shape

	mov rcx, [shape.getShapeStartTag.shape]
	mov r8, [shape.shapeShape.letters]
	cmp rcx, r8
	jne shape.getShapeStartTag.rect

	mov rax, textStartTag
	jmp shape.getShapeStartTag.end

	shape.getShapeStartTag.rect:	
	
	mov r8, [shape.shapeShape.rect]
	cmp rcx, r8
	jne shape.getShapeStartTag.ellipse

	mov rax, rectStartTag
	jmp shape.getShapeStartTag.end

	shape.getShapeStartTag.ellipse:

	mov r8, [shape.shapeShape.ellipse]
	cmp rcx, r8
	jne shape.getShapeStartTag.line

	mov rax, ellipseStartTag
	jmp shape.getShapeStartTag.end

	shape.getShapeStartTag.line:

	mov r8, [shape.shapeShape.line]
	cmp rcx, r8
	jne shape.getShapeStartTag.chart

	mov rax, lineStartTag
	jmp shape.getShapeStartTag.end

	shape.getShapeStartTag.chart:

	mov r8, [shape.shapeShape.chart]
	cmp rcx, r8
	jne shape.getShapeStartTag.table

	;mov rax, chartStartTag
	jmp shape.getShapeStartTag.end

	shape.getShapeStartTag.table:

	mov r8, [shape.shapeShape.table]
	cmp rcx, r8
	jne shape.getShapeStartTag.arrow

	;mov rax, tableStartTag
	jmp shape.getShapeStartTag.end

	shape.getShapeStartTag.arrow:

	mov r8, [shape.shapeShape.arrow]
	cmp rcx, r8
	jne shape.getShapeStartTag.logo

	;mov rax, arrowStartTag
	jmp shape.getShapeStartTag.end

	shape.getShapeStartTag.logo:

	mov r8, [shape.shapeShape.logo]
	cmp rcx, r8
	jne shape.getShapeStartTag.region

	;mov rax, logoStartTag
	jmp shape.getShapeStartTag.end

	shape.getShapeStartTag.region:

	mov r8, [shape.shapeShape.region]
	cmp rcx, r8
	jne shape.getShapeStartTag.end

	;mov rax, regionStartTag
	jmp shape.getShapeStartTag.end

	
	shape.getShapeStartTag.end:



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

shape.expose:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*4);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label shape.expose.heapAddress qword at rbp-8  
	label shape.expose.handleAllocatedMemory qword at rbp-16
	label shape.expose.shape qword at rbp-24	
	label shape.expose.region qword at rbp-32
	;label shape.expose.shape qword at rbp-40
	;label hpdp.expose.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.html HTML
	;end virtual	

	mov [shape.expose.shape], rcx

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
	mov rcx, [shape.expose.shape]
	call shape.getShapeRegion
	add rsp, 8*8
	mov [shape.expose.region], rax


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

shape.getShapeRegion:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*7);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label shape.getShapeRegion.heapAddress qword at rbp-8  
	label shape.getShapeRegion.handleAllocatedMemory qword at rbp-16
	label shape.getShapeRegion.shape qword at rbp-24	
	label shape.getShapeRegion.region qword at rbp-32
	label shape.getShapeRegion.space qword at rbp-40
	label shape.getShapeRegion.nesting qword at rbp-48
	label shape.getShapeRegion.itemMatch qword at rbp-56
	;label hpdp.expose.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.html HTML
	;end virtual	

	mov [shape.getShapeRegion.shape], rcx

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



	mov rbx, [shape.getShapeRegion.shape]
	add rbx, Shape.space
	mov rcx, [rbx]
	mov [shape.getShapeRegion.space], rcx
	
	sub rsp, 8*8
	mov rcx, [shape.getShapeRegion.space]
	call list.resetIndex
	add rsp, 8*8

	sub rsp, 8*8
	mov rdx, [shape.getShapeRegion.shape]
	mov rcx, [shape.getShapeRegion.space]
	call list.getNextItemMatch
	add rsp, 8*8

	
	mov rbx, [shape.getShapeRegion.space]
	add rbx, List.itemMatch
	mov rdx, [rbx]
	mov [shape.getShapeRegion.itemMatch], rdx
	add rdx, ItemMatch.nesting
	mov rcx, [rdx]
	mov [shape.getShapeRegion.nesting], rcx
	

	sub rsp, 8*8
	mov rcx, [shape.getShapeRegion.space]
	call list.getPriorItem					; Reverse once so Shape is not included in search
	add rsp, 8*8


	shape.getShapeRegion.priorItem:
	mov rdx, [shape.getShapeRegion.space]
	add rdx, List.index
	mov rcx, [rdx]
	cmp rcx, 0
	jl shape.getShapeRegion.firstIndex


	sub rsp, 8*8
	mov rcx, [shape.getShapeRegion.space]
	call list.getPriorItem
	add rsp, 8*8
	mov [shape.getShapeRegion.region], rax

	mov [shape.getShapeRegion.itemMatch], rdx
	add rdx, ItemMatch.nesting
	mov rcx, [rdx]
	add rcx, 1b
	mov r11, [shape.getShapeRegion.nesting]
	cmp rcx, r11
	je shape.getShapeRegion.firstIndex			; Found


	jmp shape.getShapeRegion.priorItem
	shape.getShapeRegion.firstIndex:






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
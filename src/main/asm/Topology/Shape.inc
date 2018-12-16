
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


	
	rectStartTag db '<rect ',0
	rectXTag db 'x="',0
	rectYTag db 'y="',0
	rectRXTag db 'rx="',0
	rectRYTag db 'ry="',0
	rectWidthTag db 'width="',0	
	rectHeightTag db 'height="',0
	rectStrokeTag db 'stroke="',0
	rectFillTag db 'fill="',0
	rectStrokeWidthTag db 'stroke-width="',0


	; Used with address offsets
	virtual at 0
		Shape Shape
	end virtual

	; ---- Structures
	;shape Shape



		
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


namespace shape

newShapesList:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label shape.newShapesList.shape qword at rbp-8  
	label shape.newShapesList.list qword at rbp-16
	;label shape.getShapeEndTag.list qword at rbp-24 
	;label shape.getShapeEndTag.item qword at rbp-32
	;label shape.getShapeEndTag.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.list List
	;end virtual	

	;mov [shape.newShapesList.shape], rcx




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
	call list.new
	add rsp, 8*8
	mov [shape.newShapesList.list], rax

	sub rsp, 8*8
	call shape.new
	add rsp, 8*8
	mov [shape.newShapesList.shape], rax

	sub rsp, 8*8
	mov r8, 00010001000000000000000000000000b
	mov rdx, [shape.newShapesList.shape]
	mov rcx, shape.rectShape
	call repCopy.copy
	add rsp, 8*8

	sub rsp, 8*8
	mov rdx, [shape.newShapesList.shape]
	mov rcx, [shape.newShapesList.list]
	call list.newLastItem
	add rsp, 8*8
	
	mov rax, [shape.newShapesList.list]
	

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

section '.data' data readable writeable

	struc Layout
		label .
		.space dq 0
	end struc


	
	; Used with address offsets
	virtual at 0
		Layout Layout
	end virtual

	; ---- Structures
	;layout Layout


	;newSVGMsg db 'New SVG',0

	svgStartTag db '<svg version="1.1" baseProfile="full" width="1000" height="200" xmlns="http://www.w3.org/2000/svg">',0
	svgEndTag db '</svg>',0
	scriptStartTag db '<script>',0
	scriptEndTag db '</script>',0
	
		
section '.text' code readable writeable executable ;align 16



layout:
.new:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label layout.new.heapAddress qword at rbp-8  
	label layout.new.handleAllocatedMemory qword at rbp-16
	;virtual at rbp-64
	;	.layout Layout
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
	mov [layout.new.heapAddress], rax
	add rsp, 8*4
	

	mov rcx, 0
	add rcx, Layout.space
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, rcx		
	mov rdx, 000001000b
	mov rcx, [layout.new.heapAddress]
	call [ HeapAlloc] 
	mov [layout.new.handleAllocatedMemory], rax
	add rsp, 8*4


	mov rbx, [layout.new.handleAllocatedMemory]
	add rbx, Layout.space
	newList rbx


	;lea rax, [layout.new.list]
	;lea rcx, [layout.new.list.indexedItemIndex]

	;sub rcx, rax
	;add rcx, 1000b

	;cld

	;lea rsi, [layout.new.list]
	;mov rdi, [layout.new.handleAllocatedMemory]

	;rep movsb


	mov rax, [layout.new.handleAllocatedMemory]




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

layout.getSVGStartTag:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*0);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	;label layout.getSVGStartTag.heapAddress qword at rbp-8  
	;label layout.getSVGStartTag.handleAllocatedMemory qword at rbp-16
	;label layout.getSVGStartTag.list qword at rbp-24 
	;label layout.getSVGStartTag.item qword at rbp-32
	;label layout.getSVGStartTag.prevItem qword at rbp-40
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



	mov rax, svgStartTag


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

layout.getSVGEndTag:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*0);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	;label layout.getSVGEndTag.heapAddress qword at rbp-8  
	;label layout.getSVGEndTag.handleAllocatedMemory qword at rbp-16
	;label layout.getSVGEndTag.list qword at rbp-24 
	;label layout.getSVGEndTag.item qword at rbp-32
	;label layout.getSVGEndTag.prevItem qword at rbp-40
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


	mov rax, svgEndTag

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


layout.getScriptStartTag:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*0);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	;label layout.getScriptStartTag.heapAddress qword at rbp-8  
	;label layout.getScriptStartTag.handleAllocatedMemory qword at rbp-16
	;label layout.getScriptStartTag.list qword at rbp-24 
	;label layout.getScriptStartTag.item qword at rbp-32
	;label layout.getScriptStartTag.prevItem qword at rbp-40
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



	mov rax, scriptStartTag


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

layout.getScriptEndTag:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*0);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	;label layout.getScriptEndTag.heapAddress qword at rbp-8  
	;label layout.getScriptEndTag.handleAllocatedMemory qword at rbp-16
	;label layout.getScriptEndTag.list qword at rbp-24 
	;label layout.getScriptEndTag.item qword at rbp-32
	;label layout.getScriptEndTag.prevItem qword at rbp-40
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


	mov rax, scriptEndTag

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

layout.expose:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*5);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label layout.expose.heapAddress qword at rbp-8  
	label layout.expose.handleAllocatedMemory qword at rbp-16
	label layout.expose.layout qword at rbp-24	
	label layout.expose.space qword at rbp-32
	label layout.expose.topology qword at rbp-40
	;label hpdp.expose.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.html HTML
	;end virtual	

	mov [layout.expose.layout], rcx

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



	mov rbx, [layout.expose.layout]
	add rbx, Layout.space
	mov rdx, [rbx]
	mov [layout.expose.space], rdx


	layout.expose.nextTopology:
	mov rbx, [layout.expose.space]
	mov rdx, rbx
	add rdx, List.index
	add rbx, List.itemsCount
	mov rcx, [rdx]
	mov r8, [rbx]
	cmp rcx, r8
	jnl layout.expose.endSpace

	sub rsp, 8*8
	mov rcx, [layout.expose.space]
	call list.getNextItem 
	add rsp, 8*8
	mov [layout.expose.topology], rax

	sub rsp, 8*8
	mov rcx, [layout.expose.topology]
	call topology.expose
	add rsp, 8*8

	jmp layout.expose.nextTopology
	layout.expose.endSpace:

	sub rsp, 8*8
	mov rcx, [layout.expose.space]
	call list.resetIndex
	add rsp, 8*8


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

layout.newSpaceTopology:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*5);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label layout.newSpaceTopology.heapAddress qword at rbp-8  
	label layout.newSpaceTopology.handleAllocatedMemory qword at rbp-16
	label layout.newSpaceTopology.layout qword at rbp-24	
	label layout.newSpaceTopology.space qword at rbp-32
	label layout.newSpaceTopology.topology qword at rbp-40
	;label hpdp.expose.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.html HTML
	;end virtual	

	mov [layout.newSpaceTopology.layout], rcx
	mov [layout.newSpaceTopology.space], rdx
	mov [layout.newSpaceTopology.topology], r8

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

	; region 0, otherwise last

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


	sub rsp, 8*8
	mov rdx, [topology.getTopologyRegion.topology]
	mov rcx, [topology.getTopologyRegion.space]
	call list.newNextItem
	add rsp, 8*8





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

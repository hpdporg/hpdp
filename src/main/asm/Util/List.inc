
section '.data' data readable writeable

	struc ListItem
		label .
		.item dq 0
		.previous dq 0
		.nesting dq 0
		.next dq 0
	end struc

	struc List
		label .
		.firstItem dq 0
		.listSize dq 0
		.itemsCount dq 0
		.index dq 0
		.indexItem dq 0 			; Address of item at current index for faster item retrieval
		.indexedItemIndex dq 0			; Used to determine if index was set manually or actually equals indexed Item address
	end struc	
	
	; Used with address offsets
	virtual at 0
		List List
	end virtual

	; Used with address offsets
	virtual at 0
		ListItem ListItem
	end virtual
	; ---- Structures
	;list List


	;newSVGMsg db 'New SVG',0
	
		
section '.text' code readable writeable executable ;align 16



list:
.new:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label list.new.heapAddress qword at rbp-8  
	label list.new.handleAllocatedMemory qword at rbp-16
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
	mov [list.new.heapAddress], rax
	add rsp, 8*4
	

	mov rcx, 0
	add rcx, List.indexedItemIndex
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, rcx		
	mov rdx, 000001000b
	mov rcx, [list.new.heapAddress]
	call [ HeapAlloc] 
	mov [list.new.handleAllocatedMemory], rax
	add rsp, 8*4


	mov rbx, [list.new.handleAllocatedMemory]
	add rbx, List.firstItem
	mov rax, 0
	mov [rbx], rax
	mov rbx, [list.new.handleAllocatedMemory]
	add rbx, List.listSize
	mov rax, 0
	mov [rbx], rax
	mov rbx, [list.new.handleAllocatedMemory]
	add rbx, List.itemsCount
	mov rax, 0
	mov [rbx], rax
	mov rbx, [list.new.handleAllocatedMemory]
	add rbx, List.index
	mov rax, 0
	mov [rbx], rax
	mov rbx, [list.new.handleAllocatedMemory]
	add rbx, List.indexItem
	mov rax, 0
	mov [rbx], rax
	mov rbx, [list.new.handleAllocatedMemory]
	add rbx, List.indexedItemIndex
	mov rax, 0
	mov [rbx], rax


	;lea rax, [list.new.list]
	;lea rcx, [list.new.list.indexedItemIndex]

	;sub rcx, rax
	;add rcx, 1000b

	;cld

	;lea rsi, [list.new.list]
	;mov rdi, [list.new.handleAllocatedMemory]

	;rep movsb


	mov rax, [list.new.handleAllocatedMemory]


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


list.newLastItem:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*5);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label list.newLastItem.heapAddress qword at rbp-8  
	label list.newLastItem.handleAllocatedMemory qword at rbp-16
	label list.newLastItem.list qword at rbp-24 
	label list.newLastItem.item qword at rbp-32
	label list.newLastItem.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [list.newLastItem.list], rcx
	mov [list.newLastItem.item], rdx


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
	mov [list.newLastItem.heapAddress], rax
	add rsp, 8*4


	mov rcx, 0
	add rcx, ListItem.next
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, rcx		
	mov rdx, 000001000b
	mov rcx, [list.newLastItem.heapAddress]
	call [ HeapAlloc] 
	mov [list.newLastItem.handleAllocatedMemory], rax
	add rsp, 8*4



	mov rbx, [list.newLastItem.handleAllocatedMemory]
	add rbx, ListItem.item
	mov rax, [list.newLastItem.item]
	mov [rbx], rax
	mov rbx, [list.newLastItem.handleAllocatedMemory]
	add rbx, ListItem.previous
	mov rax, 0
	mov [rbx], rax
	mov rbx, [list.newLastItem.handleAllocatedMemory]
	add rbx, ListItem.nesting
	mov rax, 0
	mov [rbx], rax
	mov rbx, [list.newLastItem.handleAllocatedMemory]
	add rbx, ListItem.next
	mov rax, 0
	mov [rbx], rax


	mov rbx, [list.newLastItem.list]
	add rbx, List.itemsCount
	mov rcx, [rbx]
	cmp rcx, 0
	jne list.newLastItem.firstItemExists
	
	mov rbx, [list.newLastItem.list]
	add rbx, List.firstItem
	mov rdx, [list.newLastItem.handleAllocatedMemory]
	mov [rbx], rdx

	mov rbx, [list.newLastItem.list]
	add rbx, List.indexItem
	mov rdx, [list.newLastItem.handleAllocatedMemory]
	mov [rbx], rdx

	
	jmp list.newLastItem.firstItem
	list.newLastItem.firstItemExists:



	mov rbx, [list.newLastItem.list]
	add rbx, List.indexItem
	mov rdx, [rbx]
	mov [list.newLastItem.prevItem], rdx


	mov rbx, [list.newLastItem.list]
	mov rdx, rbx
	add rbx, List.index
	mov r8, [rbx]
	add rdx, List.indexedItemIndex
	mov r9, [rdx]
	cmp r8, r9
	je list.newLastItem.firstItemExists.nextItem

	mov rbx, [list.newLastItem.list]			; Get first item when indexed is not cached and retrievable.
	add rbx, List.firstItem
	mov rdx, [rbx]
	mov [list.newLastItem.prevItem], rdx


	list.newLastItem.firstItemExists.nextItem:
	mov rbx, [list.newLastItem.list]
	mov rdx, rbx
	add rbx, List.index
	mov rcx, [rbx]
	add rdx, List.itemsCount
	mov r8, [rdx]
	cmp rcx, r8
	jnl list.newLastItem.lastItemReached


	mov r9, [list.newLastItem.prevItem]
	add r9, ListItem.next
	mov r10, [r9]
	cmp r10, 0
	je list.newLastItem.lastItemReached

	mov [list.newLastItem.prevItem], r10
	mov rbx, [list.newLastItem.list]
	add rbx, List.index
	mov r11, [rbx]
	add r11, 1b
	mov [rbx], r11

	jmp list.newLastItem.firstItemExists.nextItem
	list.newLastItem.lastItemReached:


	mov r9, [list.newLastItem.prevItem]
	add r9, ListItem.next
	mov rdx, [list.newLastItem.handleAllocatedMemory]
	mov [r9], rdx


	list.newLastItem.firstItem:

	mov rbx, [list.newLastItem.list]
	add rbx, List.itemsCount
	mov r11, [rbx]
	add r11, 1b
	mov [rbx], r11


	mov rax, [list.newLastItem.handleAllocatedMemory]


	list.newLastItem.end:


	mov rbx, [list.newLastItem.list]
	add rbx, List.itemsCount
	mov rax, [rbx]

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


list.getNextItem:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*6);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label list.getNextItem.heapAddress qword at rbp-8  
	label list.getNextItem.handleAllocatedMemory qword at rbp-16
	label list.getNextItem.list qword at rbp-24 
	label list.getNextItem.item qword at rbp-32
	label list.getNextItem.prevItem qword at rbp-40
	label list.getNextItem.prevItemIndex qword at rbp-48
	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [list.getNextItem.list], rcx



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
	mov [list.getNextItem.prevItemIndex], rcx		; Begin as 0

	mov rbx, [list.getNextItem.list]
	add rbx, List.indexItem
	mov rdx, [rbx]
	mov [list.getNextItem.prevItem], rdx


	mov rbx, [list.getNextItem.list]
	mov rdx, rbx
	add rbx, List.index
	mov r8, [rbx]
	add rdx, List.indexedItemIndex
	mov r9, [rdx]
	cmp r8, r9
	je list.getNextItem.atIndexedItem

	mov rbx, [list.getNextItem.list]			; Get first item when indexed is not cached and retrievable.
	add rbx, List.firstItem
	mov rdx, [rbx]
	mov [list.getNextItem.prevItem], rdx

	mov rbx, [list.getNextItem.list]
	add rbx, List.index
	mov rcx, [rbx]
	cmp rcx, 0
	jne list.getNextItem.nextItem

	list.getNextItem.atIndexedItem:

	mov rbx, [list.getNextItem.prevItem]
	mov [list.getNextItem.item], rbx		

	jmp list.getNextItem.lastItemReached

	list.getNextItem.nextItem:
	mov rbx, [list.getNextItem.list]
	add rbx, List.index
	mov rcx, [rbx]
	mov rdx, [list.getNextItem.prevItemIndex]
	cmp rcx, rdx
	jne list.getNextItem.lastItemReached


	mov r9, [list.getNextItem.prevItem]
	add r9, ListItem.next
	mov r10, [r9]
	mov [list.getNextItem.item], r10

	mov r11, [list.getNextItem.prevItemIndex]
	add r11, 1b
	mov [list.getNextItem.prevItemIndex], r11		; Increase prior item index
	
	jmp list.getNextItem.nextItem

	list.getNextItem.lastItemReached:


	mov rbx, [list.getNextItem.list]			; Advance List index
	add rbx, List.index
	mov r11, [rbx]
	add r11, 1b
	mov [rbx], r11

	mov rbx, [list.getNextItem.list]			; Advance index item, index item index
	mov rdx, rbx
	add rbx, List.indexItem
	mov r13, [list.getNextItem.item]
	mov [rbx], r13
	add rdx, List.indexedItemIndex
	mov [rdx], r11

	mov r12, [list.getNextItem.item]			; Get List Item's item
	add r12, ListItem.item
	mov rax, [r12]

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

list.getNextItemNesting:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*6);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label list.getNextItemNesting.heapAddress qword at rbp-8  
	label list.getNextItemNesting.handleAllocatedMemory qword at rbp-16
	label list.getNextItemNesting.list qword at rbp-24 
	label list.getNextItemNesting.item qword at rbp-32
	label list.getNextItemNesting.prevItem qword at rbp-40
	label list.getNextItemNesting.prevItemIndex qword at rbp-48
	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [list.getNextItemNesting.list], rcx



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
	mov [list.getNextItemNesting.prevItemIndex], rcx		; Begin as 0

	mov rbx, [list.getNextItemNesting.list]
	add rbx, List.indexItem
	mov rdx, [rbx]
	mov [list.getNextItemNesting.prevItem], rdx


	mov rbx, [list.getNextItemNesting.list]
	mov rdx, rbx
	add rbx, List.index
	mov r8, [rbx]
	add rdx, List.indexedItemIndex
	mov r9, [rdx]
	cmp r8, r9
	je list.getNextItemNesting.atIndexedItem

	mov rbx, [list.getNextItemNesting.list]			; Get first item when indexed is not cached and retrievable.
	add rbx, List.firstItem
	mov rdx, [rbx]
	mov [list.getNextItemNesting.prevItem], rdx

	mov rbx, [list.getNextItemNesting.list]
	add rbx, List.index
	mov rcx, [rbx]
	cmp rcx, 0
	jne list.getNextItemNesting.nextItem

	list.getNextItemNesting.atIndexedItem:

	mov rbx, [list.getNextItemNesting.prevItem]
	mov [list.getNextItemNesting.item], rbx		

	jmp list.getNextItemNesting.lastItemReached

	list.getNextItemNesting.nextItem:
	mov rbx, [list.getNextItemNesting.list]
	add rbx, List.index
	mov rcx, [rbx]
	mov rdx, [list.getNextItemNesting.prevItemIndex]
	cmp rcx, rdx
	jne list.getNextItemNesting.lastItemReached


	mov r9, [list.getNextItemNesting.prevItem]
	add r9, ListItem.next
	mov r10, [r9]
	mov [list.getNextItemNesting.item], r10

	mov r11, [list.getNextItemNesting.prevItemIndex]
	add r11, 1b
	mov [list.getNextItemNesting.prevItemIndex], r11		; Increase prior item index
	
	jmp list.getNextItemNesting.nextItem

	list.getNextItemNesting.lastItemReached:


	mov rbx, [list.getNextItemNesting.list]			; Advance List index
	add rbx, List.index
	mov r11, [rbx]
	add r11, 1b
	mov [rbx], r11

	mov rbx, [list.getNextItemNesting.list]			; Advance index item, index item index
	mov rdx, rbx
	add rbx, List.indexItem
	mov r13, [list.getNextItemNesting.item]
	mov [rbx], r13
	add rdx, List.indexedItemIndex
	mov [rdx], r11

	mov r12, [list.getNextItemNesting.item]			; Get List Item's nesting
	add r12, ListItem.nesting
	mov rax, [r12]

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

list.nextItemNesting:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*7);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label list.nextItemNesting.heapAddress qword at rbp-8  
	label list.nextItemNesting.handleAllocatedMemory qword at rbp-16
	label list.nextItemNesting.list qword at rbp-24 
	label list.nextItemNesting.item qword at rbp-32
	label list.nextItemNesting.prevItem qword at rbp-40
	label list.nextItemNesting.prevItemIndex qword at rbp-48
	label list.nextItemNesting.nesting qword at rbp-56
	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [list.nextItemNesting.list], rcx
	mov [list.nextItemNesting.nesting], rdx




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
	mov [list.nextItemNesting.prevItemIndex], rcx		; Begin as 0

	mov rbx, [list.nextItemNesting.list]
	add rbx, List.indexItem
	mov rdx, [rbx]
	mov [list.nextItemNesting.prevItem], rdx


	mov rbx, [list.nextItemNesting.list]
	mov rdx, rbx
	add rbx, List.index
	mov r8, [rbx]
	add rdx, List.indexedItemIndex
	mov r9, [rdx]
	cmp r8, r9
	je list.nextItemNesting.atIndexedItem

	mov rbx, [list.nextItemNesting.list]			; Get first item when indexed is not cached and retrievable.
	add rbx, List.firstItem
	mov rdx, [rbx]
	mov [list.nextItemNesting.prevItem], rdx

	mov rbx, [list.nextItemNesting.list]
	add rbx, List.index
	mov rcx, [rbx]
	cmp rcx, 0
	jne list.nextItemNesting.nextItem

	list.nextItemNesting.atIndexedItem:

	mov rbx, [list.nextItemNesting.prevItem]
	mov [list.nextItemNesting.item], rbx		

	jmp list.nextItemNesting.lastItemReached

	list.nextItemNesting.nextItem:
	mov rbx, [list.nextItemNesting.list]
	add rbx, List.index
	mov rcx, [rbx]
	mov rdx, [list.nextItemNesting.prevItemIndex]
	cmp rcx, rdx
	jne list.nextItemNesting.lastItemReached


	mov r9, [list.nextItemNesting.prevItem]
	add r9, ListItem.next
	mov r10, [r9]
	mov [list.nextItemNesting.item], r10

	mov r11, [list.nextItemNesting.prevItemIndex]
	add r11, 1b
	mov [list.nextItemNesting.prevItemIndex], r11		; Increase prior item index
	
	jmp list.nextItemNesting.nextItem

	list.nextItemNesting.lastItemReached:


	mov rbx, [list.nextItemNesting.list]			; Advance List index
	add rbx, List.index
	mov r11, [rbx]
	add r11, 1b
	mov [rbx], r11

	mov rbx, [list.nextItemNesting.list]			; Advance index item, index item index
	mov rdx, rbx
	add rbx, List.indexItem
	mov r13, [list.nextItemNesting.item]
	mov [rbx], r13
	add rdx, List.indexedItemIndex
	mov [rdx], r11

	mov r12, [list.nextItemNesting.item]			; List Item's nesting
	add r12, ListItem.nesting
	mov r13, [list.nextItemNesting.nesting]
	mov [r12], r13

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

list.resetIndex:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*5);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label list.resetIndex.heapAddress qword at rbp-8  
	label list.resetIndex.handleAllocatedMemory qword at rbp-16
	label list.resetIndex.list qword at rbp-24 
	label list.resetIndex.item qword at rbp-32
	label list.resetIndex.prevItem qword at rbp-40
	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [list.resetIndex.list], rcx



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





	mov rbx, [list.resetIndex.list]
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

macro newList listAddr

	sub rsp, 8*8
	call list.new
	add rsp, 8*8
	mov [listAddr], rax
end macro

macro getNextItem listAddr, itemAddr

	sub rsp, 8*8
	mov rcx, [listAddr]
	call list.getNextItem
	add rsp, 8*8
	mov [itemAddr], rax
end macro

macro newLastItem listAddr, itemAddr

	sub rsp, 8*8
	mov rdx, [itemAddr]
	mov rcx, [listAddr]
	call list.newLastItem
	add rsp, 8*8

end macro

macro resetIndex listAddr

	sub rsp, 8*8
	mov rcx, [listAddr]
	call list.resetIndex
	add rsp, 8*8

end macro
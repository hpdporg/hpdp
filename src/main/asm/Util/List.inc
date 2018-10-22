
section '.data' data readable writeable

	struc ListItem
		label .
		.item dq 0
		.previous dq 0
		.nesting dq 0
		.next dq 0
	end struc

	struc ItemMatch
		label .
		.item dq 0
		.index dq 0
		.nesting dq 0
	end struc

	struc List
		label .
		.firstItem dq 0
		.listSize dq 0
		.itemsCount dq 0
		.index dq 0
		.indexItem dq 0 			; Address of item at current index for faster item retrieval
		.indexedItemIndex dq 0			; Used to determine if index was set manually or actually equals indexed Item address
		.itemMatch dq 0				; Item matching
	end struc	
	


	; Used with address offsets
	virtual at 0
		ListItem ListItem
	end virtual

	; Used with address offsets
	virtual at 0
		ItemMatch ItemMatch
	end virtual


	; Used with address offsets
	virtual at 0
		List List
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
	add rcx, List.itemMatch
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
	mov rbx, [list.new.handleAllocatedMemory]
	add rbx, List.itemMatch
	sub rsp, 8*8
	call list.newItemMatch
	add rsp, 8*8
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

list.newItemMatch:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*2);+(8*0)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label list.newItemMatch.heapAddress qword at rbp-8  
	label list.newItemMatch.handleAllocatedMemory qword at rbp-16
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
	mov [list.newItemMatch.heapAddress], rax
	add rsp, 8*4
	

	mov rcx, 0
	add rcx, List.itemMatch
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, rcx		
	mov rdx, 000001000b
	mov rcx, [list.newItemMatch.heapAddress]
	call [ HeapAlloc] 
	mov [list.newItemMatch.handleAllocatedMemory], rax
	add rsp, 8*4


	mov rbx, [list.newItemMatch.handleAllocatedMemory]
	add rbx, ItemMatch.item
	mov rax, 0
	mov [rbx], rax
	mov rbx, [list.newItemMatch.handleAllocatedMemory]
	add rbx, ItemMatch.index
	mov rax, 0
	mov [rbx], rax
	mov rbx, [list.newItemMatch.handleAllocatedMemory]
	add rbx, ItemMatch.nesting
	mov rax, 0
	mov [rbx], rax


	;lea rax, [list.newItemMatch.list]
	;lea rcx, [list.newItemMatch.list.indexedItemIndex]

	;sub rcx, rax
	;add rcx, 1000b

	;cld

	;lea rsi, [list.newItemMatch.list]
	;mov rdi, [list.newItemMatch.handleAllocatedMemory]

	;rep movsb


	mov rax, [list.newItemMatch.handleAllocatedMemory]


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
	mov r8, r9
	add r9, ListItem.next
	mov rdx, [list.newLastItem.handleAllocatedMemory]
	mov [r9], rdx
	add rdx, ListItem.previous
	mov [rdx], r8


	list.newLastItem.firstItem:

	mov rbx, [list.newLastItem.list]
	add rbx, List.itemsCount
	mov r11, [rbx]
	add r11, 1b
	mov [rbx], r11


	mov rax, [list.newLastItem.handleAllocatedMemory]


	list.newLastItem.end:


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

list.newNextItem:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*9);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label list.newNextItem.heapAddress qword at rbp-8  
	label list.newNextItem.handleAllocatedMemory qword at rbp-16
	label list.newNextItem.list qword at rbp-24 
	label list.newNextItem.item qword at rbp-32
	label list.newNextItem.prevItem qword at rbp-40
	label list.newNextItem.prevItemIndex qword at rbp-48
	label list.newNextItem.newItem qword at rbp-56
	label list.newNextItem.prevItemNext qword at rbp-64
	label list.newNextItem.nextItemPrev qword at rbp-72
	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [list.newNextItem.list], rcx
	mov [list.newNextItem.newItem], rdx



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
	mov [list.newNextItem.prevItemIndex], rcx		; Begin as 0
	mov [list.newNextItem.prevItemNext], rcx


	sub rsp, 8*4
	call [GetProcessHeap]
	mov [list.newNextItem.heapAddress], rax
	add rsp, 8*4


	mov rcx, 0
	add rcx, ListItem.next
	add rcx, 1000b

	sub rsp, 8*4
	mov r8, rcx		
	mov rdx, 000001000b
	mov rcx, [list.newNextItem.heapAddress]
	call [ HeapAlloc] 
	mov [list.newNextItem.handleAllocatedMemory], rax
	add rsp, 8*4


	mov rbx, [list.newNextItem.list]
	add rbx, List.indexItem
	mov rdx, [rbx]
	mov [list.newNextItem.prevItem], rdx


	mov rbx, [list.newNextItem.list]
	mov rdx, rbx
	add rbx, List.index
	mov r8, [rbx]
	add rdx, List.indexedItemIndex
	mov r9, [rdx]
	cmp r8, r9
	je list.newNextItem.atIndexedItem

	mov rbx, [list.newNextItem.list]			; Get first item when indexed is not cached and retrievable.
	add rbx, List.firstItem
	mov rdx, [rbx]
	mov [list.newNextItem.prevItem], rdx

	mov rbx, [list.newNextItem.list]
	add rbx, List.index
	mov rcx, [rbx]
	cmp rcx, 0
	jne list.newNextItem.nextItem

	list.newNextItem.atIndexedItem:

	mov rbx, [list.newNextItem.prevItem]
	mov [list.newNextItem.item], rbx		

	jmp list.newNextItem.indexReached

	list.newNextItem.nextItem:
	mov rbx, [list.newNextItem.list]
	add rbx, List.index
	mov rcx, [rbx]
	mov rdx, [list.newNextItem.prevItemIndex]
	cmp rcx, rdx
	jne list.newNextItem.indexReached


	mov r9, [list.newNextItem.prevItem]
	add r9, ListItem.next
	mov r10, [r9]
	mov [list.newNextItem.item], r10

	mov r11, [list.newNextItem.prevItemIndex]
	add r11, 1b
	mov [list.newNextItem.prevItemIndex], r11		; Increase prior item index
	
	jmp list.newNextItem.nextItem

	list.newNextItem.indexReached:


	mov rbx, [list.newNextItem.item]
	add rbx, ListItem.next
	mov rdx, [rbx]
	cmp rdx, 0
	je list.newNextItem.noNextItem

	mov [list.newNextItem.prevItemNext], rdx	
	add rdx, ListItem.previous
	mov [list.newNextItem.nextItemPrev], rdx		; Cache index. May remove this.
	mov rax, [list.newNextItem.handleAllocatedMemory]
	mov [rdx], rax

	list.newNextItem.noNextItem:


	mov rbx, [list.newNextItem.list]			; Advance List index
	add rbx, List.index
	mov r11, [rbx]
	add r11, 1b
	mov [rbx], r11





	mov rbx, [list.newNextItem.handleAllocatedMemory]
	add rbx, ListItem.item
	mov rax, [list.newNextItem.newItem]
	mov [rbx], rax
	mov rbx, [list.newNextItem.handleAllocatedMemory]
	add rbx, ListItem.previous
	mov rax, [list.newNextItem.item]
	mov [rbx], rax
	mov rbx, [list.newNextItem.handleAllocatedMemory]
	add rbx, ListItem.nesting
	mov rax, 0
	mov [rbx], rax
	mov rbx, [list.newNextItem.handleAllocatedMemory]
	add rbx, ListItem.next
	mov rax, [list.newNextItem.prevItemNext]
	mov [rbx], rax





	mov rbx, [list.newNextItem.list]			; Increase items count
	add rbx, List.itemsCount
	mov r11, [rbx]
	add r11, 1b
	mov [rbx], r11


	mov rbx, [list.newNextItem.list]			; Advance index item, index item index
	mov rdx, rbx
	add rbx, List.indexItem
	mov r13, [list.newNextItem.handleAllocatedMemory]
	mov [rbx], r13
	add rdx, List.indexedItemIndex
	mov [rdx], r11


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

list.getPriorItem:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*7);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label list.getPriorItem.heapAddress qword at rbp-8  
	label list.getPriorItem.handleAllocatedMemory qword at rbp-16
	label list.getPriorItem.list qword at rbp-24 
	label list.getPriorItem.item qword at rbp-32
	label list.getPriorItem.prevItem qword at rbp-40
	label list.getPriorItem.prevItemIndex qword at rbp-48
	label list.getPriorItem.listItemMatch qword at rbp-56
	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [list.getPriorItem.list], rcx



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
	mov [list.getPriorItem.prevItemIndex], rcx		; Begin as 0

	mov rbx, [list.getPriorItem.list]
	add rbx, List.indexItem
	mov rdx, [rbx]
	mov [list.getPriorItem.prevItem], rdx


	mov rbx, [list.getPriorItem.list]
	mov rdx, rbx
	add rbx, List.index
	mov r8, [rbx]
	add rdx, List.indexedItemIndex
	mov r9, [rdx]
	cmp r8, r9
	je list.getPriorItem.atIndexedItem

	mov rbx, [list.getPriorItem.list]			; Get first item when indexed is not cached and retrievable.
	add rbx, List.firstItem
	mov rdx, [rbx]
	mov [list.getPriorItem.prevItem], rdx

	mov rbx, [list.getPriorItem.list]
	add rbx, List.index
	mov rcx, [rbx]
	cmp rcx, 0
	jne list.getPriorItem.nextItem

	list.getPriorItem.atIndexedItem:

	mov rbx, [list.getPriorItem.prevItem]
	mov [list.getPriorItem.item], rbx		

	jmp list.getPriorItem.lastItemReached

	list.getPriorItem.nextItem:
	mov rbx, [list.getPriorItem.list]
	add rbx, List.index
	mov rcx, [rbx]
	mov rdx, [list.getPriorItem.prevItemIndex]
	cmp rcx, rdx
	jne list.getPriorItem.lastItemReached


	mov r9, [list.getPriorItem.prevItem]
	add r9, ListItem.next
	mov r10, [r9]
	mov [list.getPriorItem.item], r10

	mov r11, [list.getPriorItem.prevItemIndex]
	add r11, 1b
	mov [list.getPriorItem.prevItemIndex], r11		; Increase prior item index
	
	jmp list.getPriorItem.nextItem

	list.getPriorItem.lastItemReached:

	mov r13, [list.getPriorItem.item]
	add r13, ListItem.previous
	mov rax, [r13]
	mov [list.getPriorItem.item], rax	
	cmp rax, 0
	je list.getPriorItem.end



	mov rbx, [list.getPriorItem.list]			; Decrease List index
	add rbx, List.index
	mov r11, [rbx]
	sub r11, 1b
	mov [rbx], r11

	mov rbx, [list.getPriorItem.list]			; Cache index item, index item index
	mov rdx, rbx
	add rbx, List.indexItem
	mov r13, [list.getPriorItem.item]
	mov [rbx], r13
	add rdx, List.indexedItemIndex
	mov [rdx], r11


	list.getPriorItem.end:

	mov r12, [list.getPriorItem.item]	
	cmp r12, 0
	je list.getPriorItem.noMatch

	mov rbx, [list.getPriorItem.list]
	mov rdx, rbx
	add rdx, List.itemMatch			
	mov rcx, [rdx]
	mov [list.getPriorItem.listItemMatch], rcx	
	mov r11, rcx
	add r11, ItemMatch.item
	mov r12, [list.getPriorItem.item]
	add r12, ListItem.item
	mov rax, [r12]
	mov [r11], rax
	mov rdx, rbx
	add rdx, List.index
	mov r11, rcx
	add r11, ItemMatch.index
	mov r13, [rdx]
	sub r13, 1b
	mov [r11], r13
	mov r11, rcx
	add r11, ItemMatch.nesting
	mov r12, [list.getPriorItem.item]	
	add r12, ListItem.nesting
	mov r13, [r12]
	mov [r11], r13

	mov r12, [list.getPriorItem.item]			; Get List Item's item
	add r12, ListItem.item
	mov rax, [r12]

	list.getPriorItem.noMatch:

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

list.getNextItemMatch:
	push rbp 
	mov rbp, rsp 
	sub rsp, (8*8);+(8*6)

	;mov rcx, [rbp+8] 
	;mov rdx, [rbp+12] 
	label list.getNextItemMatch.heapAddress qword at rbp-8  
	label list.getNextItemMatch.handleAllocatedMemory qword at rbp-16
	label list.getNextItemMatch.list qword at rbp-24 
	label list.getNextItemMatch.item qword at rbp-32
	label list.getNextItemMatch.prevItem qword at rbp-40
	label list.getNextItemMatch.prevItemIndex qword at rbp-48
	label list.getNextItemMatch.itemMatch qword at rbp-56
	label list.getNextItemMatch.listItemMatch qword at rbp-64

	;virtual at rbp-64
	;	.list List
	;end virtual	


	mov [list.getNextItemMatch.list], rcx
	mov [list.getNextItemMatch.itemMatch], rdx



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
	mov [list.getNextItemMatch.prevItemIndex], rcx		; Begin as 0

	mov rbx, [list.getNextItemMatch.list]
	add rbx, List.indexItem
	mov rdx, [rbx]
	mov [list.getNextItemMatch.prevItem], rdx


	mov rbx, [list.getNextItemMatch.list]
	mov rdx, rbx
	add rbx, List.index
	mov r8, [rbx]
	add rdx, List.indexedItemIndex
	mov r9, [rdx]
	cmp r8, r9
	je list.getNextItemMatch.atIndexedItem

	mov rbx, [list.getNextItemMatch.list]			; Get first item when indexed is not cached and retrievable.
	add rbx, List.firstItem
	mov rdx, [rbx]
	mov [list.getNextItemMatch.prevItem], rdx

	mov rbx, [list.getNextItemMatch.list]
	add rbx, List.index
	mov rcx, [rbx]
	cmp rcx, 0
	jne list.getNextItemMatch.nextItem

	list.getNextItemMatch.atIndexedItem:

	mov rbx, [list.getNextItemMatch.prevItem]
	mov [list.getNextItemMatch.item], rbx		

	jmp list.getNextItemMatch.lastItemReached

	list.getNextItemMatch.nextItem:
	mov rbx, [list.getNextItemMatch.list]
	add rbx, List.index
	mov rcx, [rbx]
	mov rdx, [list.getNextItemMatch.prevItemIndex]
	cmp rcx, rdx
	jne list.getNextItemMatch.lastItemReached


	mov r9, [list.getNextItemMatch.prevItem]
	add r9, ListItem.next
	mov r10, [r9]
	mov [list.getNextItemMatch.item], r10

	mov r11, [list.getNextItemMatch.prevItemIndex]
	add r11, 1b
	mov [list.getNextItemMatch.prevItemIndex], r11		; Increase prior item index
	
	jmp list.getNextItemMatch.nextItem

	list.getNextItemMatch.lastItemReached:


	mov rbx, [list.getNextItemMatch.list]			; Advance List index
	add rbx, List.index
	mov r11, [rbx]
	add r11, 1b
	mov [rbx], r11

	mov rbx, [list.getNextItemMatch.list]			; Advance index item, index item index
	mov rdx, rbx
	add rbx, List.indexItem
	mov r13, [list.getNextItemMatch.item]
	mov [rbx], r13
	add rdx, List.indexedItemIndex
	mov [rdx], r11

	mov r12, [list.getNextItemMatch.item]			; Get List Item's item
	add r12, ListItem.item
	mov rax, [r12]
	mov r13, [list.getNextItemMatch.itemMatch]
	cmp rax, r13
	jne list.getNextItemMatch.nextItem

	mov r12, [list.getNextItemMatch.item]	
	cmp r12, 0
	je list.getNextItemMatch.noMatch

	mov rbx, [list.getNextItemMatch.list]
	mov rdx, rbx
	add rdx, List.itemMatch			
	mov rcx, [rdx]
	mov [list.getNextItemMatch.listItemMatch], rcx	
	mov r11, rcx
	add r11, ItemMatch.item
	mov r13, [list.getNextItemMatch.itemMatch]
	mov [r11], r13
	mov rdx, rbx
	add rdx, List.index
	mov r11, rcx
	add r11, ItemMatch.index
	mov r13, [rdx]
	sub r13, 1b
	mov [r11], r13
	mov r11, rcx
	add r11, ItemMatch.nesting
	mov r12, [list.getNextItemMatch.item]	
	add r12, ListItem.nesting
	mov r13, [r12]
	mov [r11], r13



	list.getNextItemMatch.noMatch:

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
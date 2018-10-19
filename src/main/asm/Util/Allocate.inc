
section '.data' data readable writeable



section '.text' code readable writeable executable ;align 16


macro allocate size,allocationDestination
	sub rsp, 8*4
	call [GetProcessHeap]
	mov r11, rax
	add rsp, 8*4

	sub rsp, 8*4
	mov r8,  size
	mov rdx, 000001000b
	mov rcx, r11
	call [ HeapAlloc]
	mov [allocationDestination], rax
	add rsp, 8*4
end macro






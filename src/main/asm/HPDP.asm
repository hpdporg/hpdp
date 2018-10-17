include 'format/format.inc'

format MS64 COFF


include 'Include.inc'
include 'Exports.inc'







public start as 'start'

section '.data' data readable writeable align 16

	abcmsg db '0',0
	list1Addr dq 0
	item1 db '1',0
	item1Addr dq 0
	




section '.text' code readable writeable executable align 16





align 16
start:
       push rbp
       mov rbp, rsp
       and rsp, -32
       sub rsp, 8*12;8;7;8;9
       and rsp, -32


	mov qword [valueSize],1

	newFile fileAddr,[fileHandleAddr]
	writeFile [fileHandleAddr],fileValue,[valueSize],[bytesWritten]
	;mov rbx, item1Addr
	;mov rdx, item1
	;mov [rbx], rdx
	newList list1Addr
	;mov rcx, 4
	;mov [item1Addr], rcx
	newLastItem list1Addr, item1Addr
	mov rcx, rax
	byteAsNumeric fileValue 
	writeFile [fileHandleAddr],fileValue,[valueSize],[bytesWritten]
	

	;resetIndex list1Addr

	;getNextItem list1Addr, item1Addr
	;mov rdx, [item1Addr]
	;writeFile fileHandleAddr,fileValue,valueSize,bytesWritten
exit:

	;pop r15 r14 r13 r12 rsp rsi rdi rbp rbx

	;mov rsp, rbp
	;pop rbp

	;mov rax, 0
	 mov rcx, 0
	 sub rsp, 8*4
	 call [ExitProcess]
	 add rsp, 8*4
       ; retn 0




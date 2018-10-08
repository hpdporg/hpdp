include 'format/format.inc'
format MS64 COFF


include 'Include.inc'
include 'Exports.inc'




public start as 'start'




;section '.data' data readable writeable align 16



section '.text' code readable writeable executable align 16


align 16
start:
       push rbp
       mov rbp, rsp
       and rsp, -32
       sub rsp, 8*12;8;7;8;9
       and rsp, -32



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
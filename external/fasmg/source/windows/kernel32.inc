
struct FILETIME
  dwLowDateTime  dd ?
  dwHighDateTime dd ?
ends

struct SYSTEMTIME
  wYear 	dw ?
  wMonth	dw ?
  wDayOfWeek	dw ?
  wDay		dw ?
  wHour 	dw ?
  wMinute	dw ?
  wSecond	dw ?
  wMilliseconds dw ?
ends

; Heap allocation flags

HEAP_NO_SERIALIZE	 = 1
HEAP_GENERATE_EXCEPTIONS = 4
HEAP_ZERO_MEMORY	 = 8

; Device handles

INVALID_HANDLE_VALUE = -1
STD_INPUT_HANDLE     = -10
STD_OUTPUT_HANDLE    = -11
STD_ERROR_HANDLE     = -12

; Access rights

DELETE_RIGHT		  = 00010000h
READ_CONTROL		  = 00020000h
WRITE_DAC		  = 00040000h
WRITE_OWNER		  = 00080000h
SYNCHRONIZE		  = 00100000h
STANDARD_RIGHTS_READ	  = READ_CONTROL
STANDARD_RIGHTS_WRITE	  = READ_CONTROL
STANDARD_RIGHTS_EXECUTE   = READ_CONTROL
STANDARD_RIGHTS_REQUIRED  = 000F0000h
STANDARD_RIGHTS_ALL	  = 001F0000h
SPECIFIC_RIGHTS_ALL	  = 0000FFFFh
ACCESS_SYSTEM_SECURITY	  = 01000000h
MAXIMUM_ALLOWED 	  = 02000000h
GENERIC_READ		  = 80000000h
GENERIC_WRITE		  = 40000000h
GENERIC_EXECUTE 	  = 20000000h
GENERIC_ALL		  = 10000000h
PROCESS_TERMINATE	  = 00000001h
PROCESS_CREATE_THREAD	  = 00000002h
PROCESS_VM_OPERATION	  = 00000008h
PROCESS_VM_READ 	  = 00000010h
PROCESS_VM_WRITE	  = 00000020h
PROCESS_DUP_HANDLE	  = 00000040h
PROCESS_CREATE_PROCESS	  = 00000080h
PROCESS_SET_QUOTA	  = 00000100h
PROCESS_SET_INFORMATION   = 00000200h
PROCESS_QUERY_INFORMATION = 00000400h
PROCESS_ALL_ACCESS	  = STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 0FFFh
FILE_SHARE_READ 	  = 00000001h
FILE_SHARE_WRITE	  = 00000002h
FILE_SHARE_DELETE	  = 00000004h

; CreateFile actions

CREATE_NEW	  = 1
CREATE_ALWAYS	  = 2
OPEN_EXISTING	  = 3
OPEN_ALWAYS	  = 4
TRUNCATE_EXISTING = 5
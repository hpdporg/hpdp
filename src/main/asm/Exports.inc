

;include 'Exports/Title.inc'
;include 'Exports/Element.inc'
;include 'Exports/HTML.inc'

include 'Exports/Storage.inc'

extrn '__imp_ExitProcess' as ExitProcess:qword
extrn '__imp_GetProcessHeap' as GetProcessHeap:qword
extrn '__imp_HeapAlloc' as HeapAlloc:qword
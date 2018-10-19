

;include 'Exports/Title.inc'
include 'Exports/HPDP.inc'
include 'Exports/HTML.inc'
include 'Exports/Layout.inc'
include 'Exports/Topology.inc'

include 'Exports/Storage.inc'
include 'Exports/List.inc'
include 'Exports/Letters.inc'

extrn '__imp_ExitProcess' as ExitProcess:qword
extrn '__imp_GetProcessHeap' as GetProcessHeap:qword
extrn '__imp_HeapAlloc' as HeapAlloc:qword
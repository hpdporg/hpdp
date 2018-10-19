
section '.data' data readable writeable

	

	lineStartTag db '<line ',0
	lineX1Tag db 'x1="',0
	lineX2Tag db 'x2="',0
	lineY1Tag db 'y1="',0
	lineY2Tag db 'y2="',0	
	lineStrokeTag db 'stroke="',0	
	lineStrokeWidthTag db 'stroke-width="',0	
	
section '.text' code readable writeable executable ;align 16



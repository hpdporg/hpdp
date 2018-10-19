
section '.data' data readable writeable

	

	ellipseStartTag db '<ellipse ',0
	ellipseCXTag db 'cx="',0
	ellipseCYTag db 'cy="',0
	ellipseRXTag db 'rx="',0
	ellipseRYTag db 'ry="',0
	ellipseStrokeTag db 'stroke="',0
	ellipseFillTag db 'fill="',0
	ellipseStrokeWidthTag db 'stroke-width="',0	
		
section '.text' code readable writeable executable ;align 16



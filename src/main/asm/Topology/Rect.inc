
section '.data' data readable writeable

	

	rectStartTag db '<rect ',0
	rectXTag db 'x="',0
	rectYTag db 'y="',0
	rectRXTag db 'rx="',0
	rectRYTag db 'ry="',0
	rectWidthTag db 'width="',0	
	rectHeightTag db 'height="',0
	rectStrokeTag db 'stroke="',0
	rectFillTag db 'fill="',0
	rectStrokeWidthTag db 'stroke-width="',0
		
section '.text' code readable writeable executable ;align 16



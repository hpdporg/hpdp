
section '.data' data readable writeable

	

	textStartTag db '<text ',0
	textXTag db 'x="',0
	textYTag db 'y="',0
	textFontSizeTag db 'font-size="',0
	textAnchorTag db 'text-anchor="',0
	textFillTag db 'fill="',0

		
section '.text' code readable writeable executable ;align 16



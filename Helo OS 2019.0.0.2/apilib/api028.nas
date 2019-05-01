[FORMAT "WCOFF"]
[INSTRSET "i486p"]
[BITS 32]
[FILE "api028.nas"]

		GLOBAL	_api_rtc

[SECTION .text]

_api_rtc:		; int api_rtc(int option);
		MOV		EDX,28
		MOV		EAX, [ESP+4]
		INT		0x40
		RET

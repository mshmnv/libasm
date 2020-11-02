section .text
global _ft_write
extern ___error

_ft_write:
	mov rax, 0
	mov rax, 0x02000004
	syscall
	jc _error
	ret

_error:
	push	rax			; save rax in stack
	call	___error
	pop		r10			; код ошибки
	mov		[rax], r10
	mov		rax, -1
	ret

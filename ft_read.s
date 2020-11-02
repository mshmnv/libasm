section .text
global _ft_read
extern ___error

_ft_read:
	mov	rax, 0
	mov	rax, 0x02000003
	syscall
	jc	_error
	ret

_error:
	push rax
	call ___error
	pop r10
	mov [rax], r10
	mov rax, -1
	ret
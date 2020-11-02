section .text
global _ft_strdup
extern _ft_strlen
extern _ft_strcpy
extern _malloc

_ft_strdup:
	mov		rax, 0
	push	rdi
	call	_ft_strlen
	mov		rdi, rax		; rax (from strlen) bytes to malloc
	call	_malloc
	cmp		rax, 0
	je		_end
	mov		rdi, rax
	pop		rsi
	call	_ft_strcpy
	ret

_end:
	ret
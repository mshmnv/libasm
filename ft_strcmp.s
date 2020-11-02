section .text
global _ft_strcmp

;rdi - s1 - al
;rsi - s2 - bl

_ft_strcmp:
	mov rcx, -1
	mov rax, 0

_cmp:
	inc rcx
	mov bl, byte[rsi + rcx]
	mov al, byte[rdi + rcx]
	cmp al, 0
	je _end
	cmp bl, 0
	je _end
	cmp al, bl
	jne _end
	jmp _cmp

_end:
	sub rax, rbx
	ret
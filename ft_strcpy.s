section .text
global _ft_strcpy

;rdi - dst
;rsi - src

_ft_strcpy:
	xor rax, rax
    mov rcx, 0
    
_cpy:
	cmp byte[rsi + rcx], 0
	je _end
    mov dl, byte[rsi + rcx]     
    mov byte[rdi + rcx], dl
	inc rcx
	jmp _cpy
	
_end:
	mov rax, rdi
	ret

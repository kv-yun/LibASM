global	_ft_strdup

section .text

;char	*ft_strdup(const char *str)

extern	malloc
extern _ft_strcpy

_ft_strdup:
	push rbp
	mov rbp, rsp

	push rdi					;save rdi
	
	mov rcx, 0					;init rcx
	.size:	cmp byte [rdi + rcx], 0x0
		jle	.next
		inc rcx
		jmp .size
	.next:
		mov rdi, rcx
		imul rdi, 8
		call malloc
		test rax, rax
		jz .end
		pop rdi
		mov rsi, rdi
		mov rdi, rax
		call _ft_strcpy
	.end:
		mov rsp, rbp
		pop rbp
		ret

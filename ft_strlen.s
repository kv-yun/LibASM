global _ft_strlen					;fct ft_strlen

section .text

extern __errno_location					;errno

;size_t		ft_strlen(const char *str);

_ft_strlen:
	push rbp;
	mov rbp, rsp
	mov rax, 0					;inital return to 0

	mov dl, byte [rdi + 0]				;inital dl value with byte str[0]
	.while:	cmp dl, 0x0				;compar if dl = 0
		jle .endwhile
		inc rax					;increase rax (return value)
		mov dl, byte [rdi + rax]		;dl = next str element
		jmp .while				;continue while
	.endwhile:
		mov rsp, rbp
		pop rbp
		ret						;return

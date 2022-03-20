global _ft_strcpy

section .text

;void	ft_strcpy(char *dest, const char *src)

_ft_strcpy:
	push rbp;
	mov rbp, rsp;

	.while:	cmp byte [rsi], 0x0
		jle .endwhile 
		mov rdx, [rsi]			;stock rsi[0] in rdx
		mov [rdi], rdx			;stock rdc in rdi[0]
		inc rsi				;rsi++
		inc rdi				;rdi++
		jmp .while
	.endwhile:
		mov rsp, rbp
		pop rbp
		ret

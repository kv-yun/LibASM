global	_ft_strcmp				;ft_strcmp fonction

section .text

;int	ft_strcmp(const char *s1, const char *s2);

_ft_strcmp:
	push rbp;
	mov rbp, rsp
	mov rax, 0				;initialise return value 0

	mov al, byte [rdi]			;al = byte rsi[0]
	mov dl, byte [rsi]			;dl = byte rdi[0]

	mov rcx, 0				;init rcx 0

	.while:	cmp al, 0x0
		jle .endwhile
		cmp dl, 0x0
		jle .endwhile
		sub al, dl			;al = al - dl
		cmp al, 0x0			;al == 0 ?
		jne .end
		inc rcx				;increase rcx
		mov al, byte [rdi + rcx]	;al = rdi[rcx]
		mov dl, byte [rsi + rcx]	;dl = rsi[rcs]
		jmp .while
	.endwhile:
		sub al, dl
		jmp .end
	.end:
		movsx rax, al			;return value = al - dl
		mov rsp, rbp
		pop rbp
		ret				;return
	

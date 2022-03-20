global _ft_write				;fct ft_write

section .text

extern __errno_location

;ssize_t	ft_write(int fd, const void *buf, size_t size)

_ft_write:					;fct ft_write
	push rbp;				;rdi rsi rds
	mov rbp, rsp				;
	mov rax, 1				;SYS_Write

	syscall					;call write

	if:	cmp rax,0			;if !sys_write
		jl else				;if sys_write < 0 go else
		mov rsp, rbp
		pop rbp
		ret				;return res sys_write
	else:
		push rax			;push error
		call __errno_location		;appel errno
		pop qword [rax]			;settings value error bumber
		neg qword [rax]			;negativ error to positiv error
		mov rax, -1			;return -1
		mov rsp, rbp
		pop rbp
		ret				;return

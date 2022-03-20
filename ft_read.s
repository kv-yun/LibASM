global _ft_read				;fct ft_read

section .text

extern __errno_location			;errno

;ssize_t ft_read(int fd, void *buf, size_t size)

_ft_read:				;fct ft_read
	push rbp;			;rdi rsi rds
	mov rbp, rsp			;
	mov rax, 0			;SYS_READ

	syscall				;call read

	if:	cmp rax, 0
		jl else			;if !sys_read go else
		mov rsp, rbp
		pop rbp
		ret			;return
	else:
		push rax		;push error
		call __errno_location	;push errno
		pop qword [rax]			;setting value error number
		neg qword [rax]			;negativ error to positiv error
		mov rax, -1			;return -1;
		mov rsp, rbp
		pop rbp
		ret				;return

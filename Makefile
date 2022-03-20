NAME = libasm.a
CC = nasm

SRCS = ft_write.s	\
       ft_read.s	\
       ft_strlen.s	\
       ft_strcmp.s	\
       ft_strcpy.s	\
       ft_strdup.s	\

OBJS = $(SRCS:.s=.o)

alL : $(NAME)

%.o : %.s
	nasm -f elf64 $< -o $@

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

compil :
	clang -Wall -Wextra -Werror main.c $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	rm -f a.out
re : fclean $(NAME)

.PHONY:	all bonus clean fclean re compil

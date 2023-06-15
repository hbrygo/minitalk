SRCS    =	server.c


OBJ    = ${SRCS:.c=.o}
INCS    = includes
NAME    = minitalk
CC        = gcc
RM        = rm -rf
LIBFTDIR	= libft
PRINTFDIR	= printf
PRINTF		= ${PRINTFDIR}/printf.a
LIBFT		= ${LIBFTDIR}/libft.a
CFLAGS    = -Wall -Wextra -Werror -fsanitize=address -g

.c.o:
	$(CC) ${CFLAGS} -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFTDIR)
	make -C${PRINTFDIR}
	$(CC) $(OBJ) ${CFLAGS} ${LIBFT} ${PRINTF} -o $(NAME)

all: ${NAME}

clean:
	make clean -C $(LIBFTDIR) 
	make clean -C${PRINTFDIR}
	${RM} ${OBJ}

fclean: clean
	make fclean -C $(LIBFTDIR) 
	make fclean -C${PRINTFDIR}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
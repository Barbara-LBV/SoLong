SRCS	= ft_putnbr.c \
	  ft_putnbr_base.c \
	  ft_putstr.c \
	  ft_printf.c \
	  ft_strlen.c \
	  ft_print_str.c \
	  ft_print_char.c \
	  ft_print_hex.c \
	  ft_print_p.c \
	  ft_print_u.c \
	  ft_print_dec.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

RM	= rm -rf

all:	${NAME}

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean re fclean

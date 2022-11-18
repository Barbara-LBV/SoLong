# compiler
CC			= gcc

# flags
CFLAGS		= -g #-Wall -Wextra -Werror

# artifacts
NAME		= so_long

# source files
SRCS	= get_next_line.c \
		get_next_line_utils.c \
		so_long.c

# object files
OBJS	= ${SRCS:.c=.o}

# Printf library
PRINTF_NAME	= libftprintf.a

PRINTF_PATH	= ./Printf

PRINTF		= -L${PRINTF_PATH} -l${PRINFT_NAME}

# Libft library
LIBFT_NAME	= libft.h

LIBFT_PATH	= ./Libft

LIBFT		= -L${LIBFT_PATH} -l${LIBFT_NAME}

# mlx library
MLX_NAME	= -lmlx_Linux

MLX_PATH	= ./mlx-linux

MLX_FLAGS   = -lXext -lX11 -lmlx -lm

MLX			= -L${MLX_PATH} ${MLX_NAME} ${MLX_FLAGS}

# so long library
INC			= so_long.h

# rules
all: ${NAME}

${NAME}		: ${OBJS} ${INC}
			@${MAKE} -sC ${PRINTF_PATH}
			@${MAKE} -sC ${LIBFT_PATH}
			${CC} ${CFLAGS} ${OBJS} ${INC} ${MLX} -o $(NAME)

%.o 		: %.c
			${CC} ${CFLAGS} -c $< -o $@ 

clean		:
			rm -rf ${OBJS}

fclean		: clean
			@${MAKE} fclean -C ${PRINTF_PATH}
			@${MAKE} fclean -C ${LIBFT_PATH}
			rm -rf ${NAME}

re			: fclean all

val			:${NAME}
			valgrind \
			--leak-check=full --tool=memcheck \
			--show-reachable=yes \
			--track-fds=yes \
			--errors-for-leak-kinds=all \
			--show-leak-kinds=all ./${NAME}

norme		:
			norminette ${SRCS} ${INC}

.PHONY: all clean fclean re
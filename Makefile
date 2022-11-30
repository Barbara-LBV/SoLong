# compiler
CC			= gcc

# flags
CFLAGS		= -g -Wall -Wextra -Werror

# artifacts
NAME		= so_long

# source files
SRCS	= get_next_line.c \
		get_next_line_utils.c \
		so_long.c \
		parsing.c \
		parsing_utils.c \
		parsing_utils.c \
		backtracking.c \
		initialization.c \
		events.c

# object files
OBJS	= ${SRCS:.c=.o}

# Printf library
PRINTF_NAME	= -lftprintf
PRINTF_PATH	= ./Printf
PRINTF		= -L${PRINTF_PATH} ${PRINTF_NAME}

# Libft library
LIBFT_NAME	= -lft
LIBFT_PATH	= ./Libft
LIBFT		= -L${LIBFT_PATH} ${LIBFT_NAME}

# mlx library
MLX_NAME	= -lmlx_Linux
MLX_PATH	= ./mlx-linux
MLX_FLAGS   = -lXext -lX11 -lmlx -lm
MLX			= -L${MLX_PATH} ${MLX_NAME} ${MLX_FLAGS}

# so long library
LIBSOLONG_NAME	= -lso_long
LIBSOLONG_PATH	= ./Libsolong
SOLONG		= -L${LIBSOLONG_PATH} ${LIBSOLONG_NAME}

# files 
INC			= ./visuals

# rules
all: ${NAME}

${NAME}		: ${OBJS} ${SOLONG}
			@${MAKE} -sC ${PRINTF_PATH}
			@${MAKE} -sC ${LIBFT_PATH}
			${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${PRINTF} ${SOLONG} ${MLX} ${INC} -o $(NAME) 

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
			norminette ${SRCS} ${SOLONG}

.PHONY: all clean fclean re
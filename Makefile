CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -rf

NAME = push_swap
CHECK = checker

SRCS = src/main.c src/push.c src/radix.c src/reverserotate.c src/rotate.c src/simple.c src/swap.c \
       utils/check_args.c utils/index.c utils/t_list.c utils/utils.c

BONUS_SRCS = bonus/checker.c bonus/instraction0.c bonus/instraction1.c \
             src/push.c src/reverserotate.c src/rotate.c src/swap.c \
             utils/check_args.c utils/index.c utils/t_list.c utils/utils.c

OBJS = $(SRCS:.c=.o)
BOBJ = $(BONUS_SRCS:.c=.o)

all: ${NAME} ${CHECK}

${NAME}: ${OBJS} libft/libft.a
	@${CC} ${CFLAGS} -o $@ $^

${CHECK}: ${BOBJ} libft/libft.a
	@${CC} ${CFLAGS} -o $@ $^

libft/libft.a:
	@${MAKE} -C ./libft

clean:
	@${MAKE} -C ./libft clean
	@${RM} ${OBJS} ${BOBJ}

fclean: clean
	@${MAKE} -C ./libft fclean
	@${RM} ${NAME} ${CHECK}

re: fclean all

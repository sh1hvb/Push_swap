NAME = push_swap
CHECK = checker

SRC = src
UTLS = utils
BDIR = bonus

SRCS = $(SRC)/main.c $(SRC)/push.c $(SRC)/radix.c $(SRC)/reverserotate.c $(SRC)/rotate.c $(SRC)/simple.c $(SRC)/swap.c $(SRC)/sortThree.c \
$(UTLS)/check_args.c $(UTLS)/index.c $(UTLS)/t_list.c $(UTLS)/utils.c

BONUS_SRCS = $(BDIR)/checker.c $(BDIR)/instraction0.c $(BDIR)/instraction1.c \
$(SRC)/push.c $(SRC)/reverserotate.c $(SRC)/rotate.c $(SRC)/swap.c \
$(UTLS)/check_args.c $(UTLS)/index.c $(UTLS)/t_list.c $(UTLS)/utils.c


OBJS = $(SRCS:.c=.o)
BOBJ = $(BONUS_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME} ${CHECK}

${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

${CHECK}: ${BOBJ}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${BOBJ} ./libft/libft.a -o ${CHECK}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

bonus: ${CHECK}

clean:
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS} ${BOBJ}

fclean: clean
	@${RM} ${NAME} ${CHECK}

re: fclean all

.PHONY: all clean fclean re bonus

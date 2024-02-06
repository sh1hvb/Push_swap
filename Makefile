NAME = push_swap
CHECK = checker

SRC_DIR = src
UTILS_DIR = utils
BONUS_DIR = bonus

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/push.c $(SRC_DIR)/radix.c $(SRC_DIR)/reverserotate.c $(SRC_DIR)/rotate.c $(SRC_DIR)/simple.c $(SRC_DIR)/swap.c \
$(UTILS_DIR)/check_args.c $(UTILS_DIR)/index.c $(UTILS_DIR)/t_list.c $(UTILS_DIR)/utils.c
BONUS_SRCS = $(BONUS_DIR)/checker.c \
 $(SRC_DIR)/push.c $(SRC_DIR)/reverserotate.c $(SRC_DIR)/rotate.c $(SRC_DIR)/swap.c \
$(UTILS_DIR)/check_args.c $(UTILS_DIR)/index.c $(UTILS_DIR)/t_list.c $(UTILS_DIR)/utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME} ${CHECK}

${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

${CHECK}: ${BONUS_OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${BONUS_OBJS} ./libft/libft.a -o ${CHECK}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

bonus: ${CHECK}

clean:
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	@${RM} ${NAME} ${CHECK}

re: fclean all

.PHONY: all clean fclean re bonus

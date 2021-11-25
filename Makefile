NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
SOURCES=main.c \
		parse.c \
		conversions1.c

OBJECTS=$(SOURCES:.c=.o)

BONUS_OBJECTS=$(BONUS:.c=.o)

HEADER=ft_printf.h

LIBFT=libft/libft.a

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT) ${OBJECTS} $(if $(findstring bonus, $(MAKECMDGOALS)), $(BONUS_OBJECTS))
	ar rcs $(NAME) $?

%.o: %.c ${HEADER}
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(LIBFT):
	make -C libft bonus
	cp $(LIBFT) $(NAME)

clean:
	make -C libft clean
	rm -rf ${OBJECTS} ${BONUS_OBJECTS}

fclean: clean
	make -C libft fclean
	rm -rf ${NAME}

re: fclean all

.PHONY : all clean fclean re bonus

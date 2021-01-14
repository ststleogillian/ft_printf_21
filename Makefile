NAME = ft_printf.a
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
SOURCES =		ft_printf.c\
				ft_parse.c\
				ft_print_1.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $@ $^
	ranlib $@

%.o: %.c 
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean

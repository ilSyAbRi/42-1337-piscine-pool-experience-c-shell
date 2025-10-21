
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
INC = -I includes
OBJ = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o

all: libft.a

libft.a: $(OBJ)
	ar rcs libft.a $(OBJ)

srcs/ft_putchar.o: srcs/ft_putchar.c
	$(CC) $(CFLAGS) $(INC) -c srcs/ft_putchar.c -o srcs/ft_putchar.o

srcs/ft_swap.o: srcs/ft_swap.c
	$(CC) $(CFLAGS) $(INC) -c srcs/ft_swap.c -o srcs/ft_swap.o

srcs/ft_putstr.o: srcs/ft_putstr.c
	$(CC) $(CFLAGS) $(INC) -c srcs/ft_putstr.c -o srcs/ft_putstr.o

srcs/ft_strlen.o: srcs/ft_strlen.c
	$(CC) $(CFLAGS) $(INC) -c srcs/ft_strlen.c -o srcs/ft_strlen.o

srcs/ft_strcmp.o: srcs/ft_strcmp.c
	$(CC) $(CFLAGS) $(INC) -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o

clean:
	rm -f $(OBJ)
fclean: clean
	rm libft.a
re: fclean all

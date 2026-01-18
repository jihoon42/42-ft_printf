NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC_DIR = .
AR = ar rcs
RM = rm -f

SRC = ft_printf.c
SRC_UTILS = $(addprefix utils/, ft_putchar.c ft_putnbr.c ft_putunbr.c ft_putptr.c ft_puthex.c ft_putbase_ull.c)
SRC_PRINTERS = $(addprefix printers/, ft_print_c.c ft_print_s.c ft_print_d.c ft_print_u.c ft_print_p.c ft_print_x.c)

SRCS = $(SRC) $(SRC_UTILS) $(SRC_PRINTERS)
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = ar rcs
SRCS = ft_printf.c ft_putnbr_base.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(ARFLAGS) $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re

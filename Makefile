NAME	=	libftprintf.a

all : $(NAME)

SRC = ft_printf.c\
		ft_libft1.c\
		ft_libft2.c\

HEADER = ft_printf.h

OBJ = $(patsubst %.c, %.o, ${SRC})
COMPILER = cc
FLAGS = -Wall -Wextra -Werror -I$(HEADER)

.PHONY : all clean fclean re

$(NAME) : $(OBJ) $(HEADER)
		ar rcs $(NAME) $?

%.o :	%.c $(HEADER)
		$(COMPILER) $(FLAGS) -c $< -o $@

clean :
		@rm -f $(OBJ)

fclean :	clean
		@rm -f $(NAME)

re : fclean all

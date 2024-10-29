# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 13:17:59 by yrio              #+#    #+#              #
#    Updated: 2023/11/30 11:40:54 by yrio             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS =  -c -Wall -Wextra -Werror

SRCS = ft_printf.c ft_print_ptr.c ft_utils.c

ALL_SRCS = $(SRCS)
OBJ = $(ALL_SRCS:.c=.o)
OBJS = $(addprefix objs/, $(OBJ))
INC = ./ft_printf.h

all: $(NAME)

$(NAME): objs $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	echo "                 compilation de libftprintf.a OK"

objs:
	mkdir -p objs

objs/%.o: %.c
	echo "\n<------------------LIBFT------------------>\n"
	cc $(FLAGS) -I $(INC) -o $@ -c $<
	echo "                 compilation des .c en .o OK"

norme:
	echo "\n<------------------Norminette------------------>\n"
	norminette $(SRCS)
	norminette -R CheckDefine $(INC)
	echo "\n               NORMINETTE OK"

clean:
	rm -rf ./objs
	echo "\n<------------------Folder Clean------------------>\n"
	echo "                 Fichiers objets SUPPRIME"

fclean: clean
	rm -f $(NAME)
	echo "                 $(NAME) SUPPRIME"

re: fclean all

.PHONY: clean fclean re all bonus

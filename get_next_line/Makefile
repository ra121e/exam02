# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 08:24:11 by athonda           #+#    #+#              #
#    Updated: 2024/09/19 08:45:15 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	gnl

LIB		=	libgnl.a

MAIN	=	main.c

HEAD	=	get_next_line.h

SRC		=	get_next_line.c

OBJ		=	$(patsubst %.c, %.o, $(SRC));

FLAGS	=	-D BUFFER_SIZE=5 -g3

all: $(NAME)

$(NAME): $(MAIN) $(LIB)
		cc $(FLAGS) $(MAIN) $(LIB) -o $(NAME)

$(LIB): $(OBJ)
		ar rcs $@ $?

%.o: %.c $(HEAD)
		cc -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(LIB) $(NAME)

re: fclean all

.PHONY: all clean fclean re
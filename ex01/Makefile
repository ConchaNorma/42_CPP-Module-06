# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 07:57:16 by cnorma            #+#    #+#              #
#    Updated: 2022/06/15 21:38:04 by cnorma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	data

SRC			=	main.cpp

SRC_RIR 	=	./

OBJ_DIR		=	./obj/

OBJ			=	$(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.cpp=.o))

#HEADER		=	./Converter.hpp

CC			=	c++

FLAGS		=	-Wall -Wextra -Werror -g -std=c++98 -O2


all:			$(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o:	%.cpp
				$(CC) $(FLAGS) -c $< -o $@

$(NAME):		$(OBJ)
				$(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR):
				@mkdir -p $@

clean:
				@rm -rf $(OBJ) $(OBJ_DIR)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all

.PHONY:			all re clean fclean

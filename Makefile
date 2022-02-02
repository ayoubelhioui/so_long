# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 11:39:54 by ael-hiou          #+#    #+#              #
#    Updated: 2021/12/18 15:45:50 by ael-hiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = so_long
RM = rm -f
CFLAGS = -Wextra -Werror -Wall -lmlx -framework OpenGl -framework Appkit -g
SRC = so_long.c ./includes/get_next_line.c ./includes/get_next_line_utils.c  ./src/ft_helper.c ./src/ft_helper1.c ./src/ft_helper2.c ./src/ft_helper3.c ./src/ft_helper4.c ./src/ft_helper5.c ./src/ft_helper6.c

all : $(NAME)
$(NAME) :
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean:
	$(RM) $(OBJECTFILE)
fclean : clean
	$(RM) $(NAME)
re : fclean all
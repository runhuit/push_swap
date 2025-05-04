# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 07:18:42 by rabouzer          #+#    #+#              #
#    Updated: 2025/01/31 02:56:34 by rabouzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libftprintf.a
CFLAG = -Wall -Wextra -Werror -g
OBJ = $(SRC:.c=.o)
SRC = ft_printf.c \
		print_alphanumeric.c \
		ft_putnbr_base_p.c

.c.o :
	$(CC) $(CFLAG) -I includes -c $< -o $(<:.c=.o)
  
all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re

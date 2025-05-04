# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabouzer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 07:57:02 by rabouzer          #+#    #+#              #
#    Updated: 2024/10/29 07:57:06 by rabouzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libft.a
CFLAG = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)
SRC = ft_isalpha.c \
        ft_isdigit.c \
        ft_isalnum.c \
        ft_isprint.c \
        ft_memset.c \
        ft_strlen.c \
        ft_toupper.c \
        ft_tolower.c \
        ft_memcpy.c \
        ft_atoi.c \
        ft_bzero.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_memchr.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strlcat.c \
		ft_strdup.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_isascii.c \
		ft_putchar_fd.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_split.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_substr.c \

SRCBONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

.c.o :
	$(CC) $(CFLAG) -I includes -c $< -o $(<:.c=.o)
  
$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

all : $(NAME)

bonus : $(OBJ) $(OBJBONUS)
	ar rc $(NAME) $(OBJBONUS)

clean :
	rm -rf $(OBJ) $(OBJBONUS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re

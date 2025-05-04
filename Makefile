CC		:= cc
NAME	:= push_swap
CFLAGS	:= -Wextra -Wall -Werror
LIBFT_DIR	:= libft
LIBFT	:= libft/libft.a
PRINTF_DIR		:= ft_printf
PRINTF		:= ft_printf/libftprintf.a
SRCS	:= ft_printf/ft_printf.c \
		ft_printf/ft_putnbr_base_p.c \
		ft_printf/print_alphanumeric.c \
		libft/ft_isalpha.c \
		libft/ft_isdigit.c \
		libft/ft_isalnum.c \
		libft/ft_isascii.c \
		libft/ft_isprint.c \
		libft/ft_bzero.c \
		libft/ft_strlen.c \
		libft/ft_toupper.c \
		libft/ft_tolower.c \
		libft/ft_strlcpy.c \
		libft/ft_strncmp.c \
		libft/ft_strrchr.c \
		libft/ft_strchr.c \
		libft/ft_atoi.c \
		libft/ft_memchr.c \
		libft/ft_strdup.c \
		libft/ft_strlcat.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_memcmp.c \
		libft/ft_calloc.c \
		libft/ft_strnstr.c \
		libft/ft_substr.c \
		libft/ft_strjoin.c \
		libft/ft_strtrim.c \
		libft/ft_split.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_striteri.c \
		libft/ft_itoa.c \
		libft/ft_strmapi.c \
		libft/ft_lstadd_front.c \
		libft/ft_lstnew.c \
		libft/ft_lstlast.c \
		libft/ft_lstsize.c \
		libft/ft_lstadd_back.c \
		libft/ft_lstdelone.c \
		libft/ft_lstclear.c \
		libft/ft_lstiter.c \
		libft/ft_lstmap.c \
		src/algo.c \
		src/checks.c \
		src/main.c \
		src/moves.c \
		src/utils.c \
		src/utils_check.c \

OBJS	:= ${SRCS:.c=.o}

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	make -s -C $(LIBFT_DIR)
$(PRINTF):
	make -s -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c -g $^ 

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(PRINTF)
	rm -rf $(LIBFT)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re

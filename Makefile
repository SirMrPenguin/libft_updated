# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joabotel <joabotel@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 18:15:47 by joabotel          #+#    #+#              #
#    Updated: 2025/10/17 16:47:19 by joabotel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = 	ft_atoi.c \
		ft_calloc.c \
		ft_atol.c \
		ft_isalnum.c \
		ft_bzero.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memset.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_split.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strlcpy.c \
		ft_strtrim.c \
		ft_strlcat.c \
		ft_strjoin.c \
		ft_striteri.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_printchr.c \
		ft_printstr.c \
		ft_printptr.c \
		ft_printunit.c \
		ft_printnum.c \
		ft_printhex.c \
		ft_printf.c

OBJS = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all

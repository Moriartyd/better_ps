# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 14:33:12 by cpollich          #+#    #+#              #
#    Updated: 2019/09/20 20:56:38 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRC = 	ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strcmp.c ft_strncmp.c \
		ft_strcpy.c ft_strncpy.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strstr.c ft_strnstr.c \
		ft_atoi.c \
		ft_strcat.c ft_strncat.c \
		ft_strlcat.c\
		ft_strchr.c ft_strrchr.c\
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_iswhitespace.c\
		ft_isascii.c ft_isprint.c\
		ft_toupper.c ft_tolower.c\
		ft_putchar.c ft_putchar_fd.c \
		ft_putstr.c ft_putstr_fd.c \
		ft_putendl.c ft_putendl_fd.c \
		ft_putnbr.c ft_putnbr_fd.c \
		ft_itoa.c \
		ft_strclr.c \
		ft_memalloc.c ft_memdel.c\
		ft_striter.c ft_striteri.c\
		ft_strnew.c ft_strdel.c\
		ft_strequ.c ft_strnequ.c\
		ft_strmap.c ft_strmapi.c\
		ft_strsub.c ft_strjoin.c\
		ft_strtrim.c ft_strsplit.c\
		ft_strtrimchr.c\
		ft_lstnew.c	ft_lstdelone.c\
		ft_lstdel.c	ft_lstadd.c\
		ft_lstiter.c ft_lstmap.c\
		ft_realloc.c ft_lstsize.c\
		ft_intpower.c ft_abs.c\
		ft_strchr_safe.c ft_strdup_safe.c\
		ft_strshift.c get_next_line.c\
		ft_wordcount.c ft_lstclr.c ft_copyuntil.c\
		ft_doublestrdel.c\
		ft_swap.c

SRCO = $(SRC:.c=.o)
	
F = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCO) $(HEADER)
	@ar rc $(NAME) $(SRCO)
	@ranlib $(NAME)
	@echo "\033[1;32mlibft.a was built\033[0m"

$(SRCO): $(SRC)
	@gcc $F -c $(SRC)

clean:
	@rm -f $(SRCO)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette

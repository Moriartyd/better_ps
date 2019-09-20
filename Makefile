# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/25 19:23:03 by cpollich          #+#    #+#              #
#    Updated: 2019/09/20 20:56:49 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
NAME_PS			=	push_swap
NAME_CHECKER	=	checker

LIBFT_DIR	=	./libft
SRC_DIR		=	./src
INC_DIR		=	./inc
OBJ_DIR		=	./obj

F	=	-Wall -Wextra -Werror

PS_H	=	$(INC_DIR)/push_swap.h

SRC	=	stacks.c\
		push_swap_op.c revrot_op.c rot_op.c\
		parse_input.c\
		exec_com.c\
		ft_quicksort.c sort.c deep_sort.c\
		sort_small.c cmd_lst.c push_optimize.c\
		sort_help.c

SRC_T		=	$(addprefix $(SRC_DIR)/,$(SRC))

CHECKER		=	checker_main.c
PUSH_SWAP	=	ps_main.c

OBJS			=	$(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
PUSH_SWAP_OBJ	=	$(OBJ_DIR)/ps_main.o
CHECKER_OBJ		=	$(OBJ_DIR)/checker_main.o
LIBFT			=	$(LIBFT_DIR)/libft.a

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS) $(PUSH_SWAP_OBJ) $(CHECKER_OBJ) $(PS_H)
	@echo "\033[35mCompiling ./push_swap\033[0m"
	@gcc $(LIBFT) $F $(OBJS) $(PUSH_SWAP_OBJ) -o $(NAME_PS)
	@echo "\033[35mCompiling ./checker\033[0m"
	@gcc $(LIBFT) $F $(OBJS) $(CHECKER_OBJ) -o $(NAME_CHECKER)
	@echo "\033[1;32mProject was built\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(FLAGS) -c $< -I$(INC_DIR) -I$(LIBFT_DIR) -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME_PS)
	@rm -rf $(NAME_CHECKER)
	@make -C libft fclean
	@echo "\033[3;36mProject fully cleaned\033[0m"

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/25 19:23:03 by cpollich          #+#    #+#              #
#    Updated: 2019/09/20 18:37:09 by cpollich         ###   ########.fr        #
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

SRC	=	stacks.c\
		push_swap_op.c revrot_op.c rot_op.c\
		parse_input.c\
		exec_com.c\
		ft_quicksort.c sort.c deep_sort.c\
		sort_small.c cmd_lst.c push_optimize.c\
		rotrevrota_optimize.c sort_help.c

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

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS) $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)
	@echo "Compiling ./push_swap"
	@gcc $(LIBFT) $F -g $(OBJS) $(PUSH_SWAP_OBJ) -o $(NAME_PS)
	@echo "Compiling ./checker"
	@gcc $(LIBFT) $F -g $(OBJS) $(CHECKER_OBJ) -o $(NAME_CHECKER)
	@echo "Project was built"

$(NAME_CHECKER):
	@echo "This will only do ./checker!"
	@make $(LIBFT) $(OBJ_DIR) $(OBJS) $(CHECKER_OBJ)
	@gcc $(LIBFT) $F $(OBJS) $(CHECKER_OBJ) -o $(NAME_CHECKER)
	@echo "Checker was built"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(FLAGS) -g -c $< -I$(INC_DIR) -I$(LIBFT_DIR) -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME_PS)
	@rm -rf $(NAME_CHECKER)
	@make -C libft fclean
	@echo "Project fully cleaned"

re: fclean all

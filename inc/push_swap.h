/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 20:06:37 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/20 18:35:22 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define TO_PRINT 1
# define F_SMALL 2

/*
**	pa = 1
**	pb = 2
**	sa = 3
**	sb = 4
**	ss = 5
**	ra = 6
**	rb = 7
**	rr = 8
**	rra = 9
**	rrb = 10
**	rrr = 11
*/

typedef struct			s_cmdlist
{
	int					cmd;
	struct s_cmdlist	*next;
}						t_cmdlist;

/*
**	Size - num of last element in array[size]
**	size = -1	--> 0 elements in array
**	size = 0	--> 1 element
**	size = 1	--> 2 elements
*/

typedef struct			s_stack
{
	int					*a;
	int					siza;
	int					*b;
	int					sizb;
	int					f;
	t_cmdlist			*lst;
}						t_stack;

/*
**	PUSH_SWAP operations
*/

void					swap_a(t_stack *stack);
void					swap_b(t_stack *stack);
void					swap_ab(t_stack *stack);

void					revrot_a(t_stack *stack);
void					revrot_b(t_stack *stack);
void					revrot_ab(t_stack *stack);

void					push_a(t_stack *stack);
void					push_b(t_stack *stack);

void					rot_a(t_stack *stack);
void					rot_b(t_stack *stack);
void					rot_ab(t_stack *stack);

/*
**	STACK OPERATIONS
*/

void					print_stacks(t_stack *stack);
t_stack					*create_stack(int size);
t_stack					*delete_stack(t_stack *stack);
int						sorted(t_stack *stack);
int						*rev_arr(int *arr, int len);

/*
**	PARSING
*/

t_stack					*parse_input(int ac, char **av);
void					commands(t_stack *s);

/*
**	QSort & Sorting
*/

void					quick_sort(int *arr, int low, int high);
int						get_median(int *arr, int len);
int						divide_a(t_stack *s);
void					sort_small(t_stack *s, int len);
void					sort_a(t_stack *s, int elnum);
void					sort_b(t_stack *s, int elnum);
int						get_pos(int a, int b, int c);
void					sort_3(t_stack *s, int c);
void					deep_sort_3(t_stack *s, int c);
void					sort_2(t_stack *s, int c);
int						check_meda(t_stack *s, int med);
int						check_medb(t_stack *s, int med);

/*
**	Command optimization
*/

void		add_cmd(t_cmdlist *head, int cmd);
void		print_cmd(t_cmdlist **lst);
void		cmd_optimize(t_cmdlist *head);
void		optimize_push(t_cmdlist **lst);
void			optimize_rorevrota(t_cmdlist **lst);

#endif

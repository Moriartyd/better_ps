/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:56:23 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/20 15:50:43 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stacks(t_stack *stack)
{
	int	i;

	ft_putstr("1 stack: ");
	i = stack->siza + 1;
	while (--i >= 0)
	{
		ft_putnbr(stack->a[i]);
		if (i != 0)
			ft_putstr("->");
	}
	ft_putstr("\n");
	ft_putstr("2 stack: ");
	i = stack->sizb + 1;
	while (--i >= 0)
	{
		ft_putnbr(stack->b[i]);
		if (i != 0)
			ft_putstr("->");
	}
	if (stack->sizb == -1)
		ft_putstr("empty");
	ft_putstr("\n\n");
}

t_stack		*create_stack(int size)
{
	t_stack	*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		exit(-1);
	stack->a = (int *)malloc(sizeof(int) * size);
	stack->b = (int *)malloc(sizeof(int) * size);
	stack->lst = (t_cmdlist *)malloc(sizeof(t_cmdlist));
	if (!stack->a || !stack->b || !stack->lst)
		exit(-1);
	stack->lst->next = NULL;
	stack->lst->cmd = 0;
	stack->siza = size - 1;
	stack->sizb = -1;
	stack->f = 0;
	return (stack);
}

t_stack		*delete_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
	return (NULL);
}

int			sorted(t_stack *stack)
{
	int	i;

	if (!stack || stack->sizb != -1)
		return (0);
	i = 0;
	while (i < stack->siza)
	{
		if (stack->a[i] < stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

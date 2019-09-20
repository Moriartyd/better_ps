/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:10:27 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/20 15:22:56 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_a(t_stack *stack)
{
	int i;
	int tmp;

	if (!stack)
		return ;
	if (stack->siza > 0)
	{
		i = stack->siza;
		tmp = stack->a[i];
		while (i >= 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = tmp;
		if ((stack->f & TO_PRINT) == TO_PRINT)
			add_cmd(stack->lst, 6);
	}
}

void	rot_b(t_stack *stack)
{
	int	i;
	int	tmp;

	if (!stack)
		return ;
	if (stack->sizb > 0)
	{
		i = stack->sizb;
		tmp = stack->b[i];
		while (i >= 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = tmp;
		if ((stack->f & TO_PRINT) == TO_PRINT)
			add_cmd(stack->lst, 7);
	}
}

void	rot_ab(t_stack *stack)
{
	int	i;
	int	tmp;

	if (!stack)
		return ;
	if (stack->siza > 0 && stack->sizb > 0)
	{
		rot_a(stack);
		rot_b(stack);
		((stack->f & TO_PRINT) == TO_PRINT) ? write(1, "rr\n", 3) : (0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:13:01 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/20 15:22:05 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrot_a(t_stack *stack)
{
	int	i;
	int	tmp;

	if (!stack)
		return ;
	if (stack->siza > 0)
	{
		i = 0;
		tmp = stack->a[0];
		while (i < stack->siza)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[stack->siza] = tmp;
		if ((stack->f & TO_PRINT) == TO_PRINT)
			add_cmd(stack->lst, 9);
	}
}

void	revrot_b(t_stack *stack)
{
	int	i;
	int	tmp;

	if (!stack)
		return ;
	if (stack->sizb > 0)
	{
		i = 0;
		tmp = stack->b[0];
		while (i < stack->sizb)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[stack->sizb] = tmp;
		if ((stack->f & TO_PRINT) == TO_PRINT)
			add_cmd(stack->lst, 10);
	}
}

void	revrot_ab(t_stack *stack)
{
	int	i;
	int	tmp;

	if (!stack)
		return ;
	if (stack->siza > 0 & stack->sizb > 0)
	{
		i = 0;
		tmp = stack->a[0];
		while (i < stack->siza)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[stack->siza] = tmp;
		tmp = stack->b[0];
		i = 0;
		while (i < stack->sizb)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[stack->sizb] = tmp;
		((stack->f & TO_PRINT) == TO_PRINT) ? add_cmd(stack->lst, 11) : (0);
	}
}

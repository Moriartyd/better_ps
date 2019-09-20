/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:07:59 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/20 16:04:03 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_a(t_stack *stack)
{
	if (!stack || stack->sizb < 0)
		return ;
	stack->a[stack->siza + 1] = stack->b[stack->sizb];
	stack->siza++;
	stack->sizb--;
	if ((stack->f & TO_PRINT) == TO_PRINT)
		add_cmd(stack->lst, 1);
}

void		push_b(t_stack *stack)
{
	if (!stack || stack->siza < 0)
		return ;
	stack->b[stack->sizb + 1] = stack->a[stack->siza];
	stack->sizb++;
	stack->siza--;
	if ((stack->f & TO_PRINT) == TO_PRINT)
		add_cmd(stack->lst, 2);
}

void	swap_a(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return ;
	if (stack->siza > 0)
	{
		tmp = stack->a[stack->siza];
		stack->a[stack->siza] = stack->a[stack->siza - 1];
		stack->a[stack->siza - 1] = tmp;
		if ((stack->f & TO_PRINT) == TO_PRINT)
			add_cmd(stack->lst, 3);
	}
}

void	swap_b(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return ;
	if (stack->sizb > 0)
	{
		tmp = stack->b[stack->sizb];
		stack->b[stack->sizb] = stack->b[stack->sizb - 1];
		stack->b[stack->sizb - 1] = tmp;
		if ((stack->f & TO_PRINT) == TO_PRINT)
			add_cmd(stack->lst, 4);
	}
}

void	swap_ab(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return ;
	if (stack->siza > 0)
	{
		tmp = stack->a[stack->siza];
		stack->a[stack->siza] = stack->a[stack->siza - 1];
		stack->a[stack->siza - 1] = tmp;
	}
	if (stack->sizb > 0)
	{
		tmp = stack->b[stack->sizb];
		stack->b[stack->sizb] = stack->b[stack->sizb - 1];
		stack->b[stack->sizb - 1] = tmp;
	}
	if ((stack->f & TO_PRINT) == TO_PRINT)
		add_cmd(stack->lst, 4);
}

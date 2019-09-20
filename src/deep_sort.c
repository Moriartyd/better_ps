/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:17:19 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/05 23:01:34 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_pos(int a, int b, int c)
{
	if (a < b && b < c)
		return (0);
	if (a < c && c < b)
		return (1);
	if (b < a && a < c)
		return (2);
	if (a < b && c < a)
		return (3);
	if (b < c && c < a)
		return (4);
	if (c < b && b < a)
		return (5);
	return (-1);
}

static void	dsort_3b(t_stack *s, int pos)
{
	if (pos == 0 || pos == 1 || pos == 3)
		swap_b(s);
	if (pos == 0 || pos == 1 || pos == 2 || pos == 4)
	{
		push_a(s);
		swap_b(s);
		push_b(s);
	}
	if (pos == 0 || pos == 2)
		swap_b(s);
}

static void	dsort_3a(t_stack *s, int pos)
{
	if (pos == 2 || pos == 4 || pos == 5)
		swap_a(s);
	if (pos == 1 || pos == 3 || pos == 4 || pos == 5)
	{
		push_b(s);
		swap_a(s);
		push_a(s);
	}
	if (pos == 3 || pos == 5)
		swap_a(s);
}

void		deep_sort_3(t_stack *s, int c)
{
	if (c == 'a')
		dsort_3a(s, get_pos(s->a[s->siza],
		s->a[s->siza - 1], s->a[s->siza - 2]));
	else if (c == 'b')
		dsort_3b(s, get_pos(s->b[s->sizb],
		s->b[s->sizb - 1], s->b[s->sizb - 2]));
}

void		sort_2(t_stack *s, int c)
{
	if (c == 'a' && s->a[s->siza] > s->a[s->siza - 1])
		swap_a(s);
	else if (c == 'b' && s->b[s->sizb] < s->b[s->sizb - 1])
		swap_b(s);
}

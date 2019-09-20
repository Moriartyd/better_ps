/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 21:08:35 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/20 18:36:26 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				divide_a(t_stack *s)
{
	int	med;
	int	res;
	int	rot;

	res = 0;
	med = get_median(s->a, s->siza + 1);
	rot = 0;
	while (check_meda(s, med))
	{
		if (s->a[s->siza] < med)
		{
			push_b(s);
			res++;
		}
		else if (s->a[s->siza] >= med)
		{
			rot++;
			rot_a(s);
		}
	}
	while (rot-- > 0 && (s->f & F_SMALL) != F_SMALL)
		revrot_a(s);
	return (res);
}

static int		divide_b(t_stack *s)
{
	int	med;
	int	res;
	int	rot;

	res = 0;
	med = get_median(s->b, s->sizb + 1);
	rot = 0;
	while (check_medb(s, med))
	{
		if (s->b[s->sizb] >= med)
		{
			push_a(s);
			res++;
		}
		else if (s->b[s->sizb] < med)
		{
			rot++;
			rot_b(s);
		}
	}
	while (rot-- > 0)
		revrot_b(s);
	return (res);
}

void			sort_a(t_stack *s, int elnum)
{
	int p;
	int	tmp;
	int	*t;

	if (elnum == 1)
		sort_2(s, 'a');
	else if (elnum == 2)
		deep_sort_3(s, 'a');
	else if (elnum > 2)
	{
		p = divide_a(s);
		sort_a(s, s->siza);
		t = s->b;
		tmp = s->sizb;
		s->b = t + (tmp - p + 1);
		s->sizb = p - 1;
		sort_b(s, p - 1);
		s->b = t;
		s->sizb = tmp;
		while (--p >= 0)
			push_a(s);
	}
}

void			sort_b(t_stack *s, int elnum)
{
	int p;
	int	tmp;
	int	*t;

	if (elnum == 1)
		sort_2(s, 'b');
	else if (elnum == 2)
		deep_sort_3(s, 'b');
	else if (elnum > 2)
	{
		p = divide_b(s);
		sort_b(s, s->sizb);
		t = s->a;
		tmp = s->siza;
		s->a = t + (tmp - p + 1);
		s->siza = p - 1;
		sort_a(s, p - 1);
		s->a = t;
		s->siza = tmp;
		while (--p >= 0)
			push_b(s);
	}
}

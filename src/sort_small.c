/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:58:17 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/11 19:41:43 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_a(t_stack *s, int c)
{
	int	pos;

	pos = get_pos(s->a[s->siza],
		s->a[s->siza - 1], s->a[s->siza - 2]);
	if (pos == 1 || pos == 3)
		revrot_a(s);
	if (pos == 4 || pos == 5)
		rot_a(s);
	if (pos == 2 || pos == 1 || pos == 5)
		swap_a(s);
}

void	sort_3_b(t_stack *s, int c)
{
	int	pos;

	pos = get_pos(s->a[s->siza],
		s->a[s->siza - 1], s->a[s->siza - 2]);
	if (pos == 4 || pos == 2)
		revrot_b(s);
	if (pos == 1 || pos == 0)
		rot_b(s);
	if (pos == 3 || pos == 4 || pos == 0)
		swap_b(s);
}

void	sort_small(t_stack *s, int len)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	s->f = s->f | F_SMALL;
	if (len > 2)
		i = divide_a(s);
	if (s->siza == 1)
		sort_2(s, 'a');
	if (s->sizb == 1)
		sort_2(s, 'b');
	if (s->siza == 2)
		sort_3_a(s, get_pos(s->a[s->siza],
		s->a[s->siza - 1], s->a[s->siza - 2]));
	if (s->sizb == 2)
		sort_3_b(s, get_pos(s->b[s->siza],
		s->b[s->sizb - 1], s->b[s->sizb - 2]));
	while (--i >= 0)
		push_a(s);
}

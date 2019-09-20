/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:16:57 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/20 20:11:47 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *s;

	if (ac > 1)
	{
		if (!(s = parse_input(ac - 1, av + 1)))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		s->f = TO_PRINT;
		if (!sorted(s))
			s->siza < 5 ? sort_small(s, s->siza) : sort_a(s, s->siza);
		cmd_optimize(s->lst);
		delete_stack(s);
	}
	return (0);
}

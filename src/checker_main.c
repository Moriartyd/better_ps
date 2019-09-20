/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 20:08:18 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/04 23:23:38 by cpollich         ###   ########.fr       */
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
		commands(s);
		delete_stack(s);
	}
	return (0);
}

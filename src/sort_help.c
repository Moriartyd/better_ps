/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:34:18 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/20 18:34:49 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_meda(t_stack *s, int med)
{
	int	i;

	i = 0;
	while (i <= s->siza)
	{
		if (s->a[i] < med)
			return (1);
		i++;
	}
	return (0);
}

int		check_medb(t_stack *s, int med)
{
	int	i;

	i = 0;
	while (i <= s->sizb)
	{
		if (s->b[i] >= med)
			return (1);
		i++;
	}
	return (0);
}

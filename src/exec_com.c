/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:55:49 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/11 18:49:18 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exe_com(char *str, t_stack *s)
{
	if (!ft_strcmp(str, "sa"))
		swap_a(s);
	else if (!ft_strcmp(str, "sb"))
		swap_b(s);
	else if (!ft_strcmp(str, "ss"))
		swap_ab(s);
	else if (!ft_strcmp(str, "pa"))
		push_a(s);
	else if (!ft_strcmp(str, "pb"))
		push_b(s);
	else if (!ft_strcmp(str, "ra"))
		rot_a(s);
	else if (!ft_strcmp(str, "rb"))
		rot_b(s);
	else if (!ft_strcmp(str, "rr"))
		rot_ab(s);
	else if (!ft_strcmp(str, "rra"))
		revrot_a(s);
	else if (!ft_strcmp(str, "rrb"))
		revrot_b(s);
	else if (!ft_strcmp(str, "rrr"))
		revrot_ab(s);
	else
		return (0);
	return (1);
}

void		commands(t_stack *s)
{
	char	*line;
	int		stat;

	while ((stat = ft_gnl(0, &line)) > 0)
	{
		if (!(exe_com(line, s)))
		{
			stat = -1;
			break ;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (stat == -1)
		write(2, "Error\n", 6);
	else if (sorted(s))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

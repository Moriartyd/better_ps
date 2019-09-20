/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotrevrota_optimize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:21:58 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/20 18:26:26 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_howsame_rrra(t_cmdlist **lst)
{
	size_t		res;
	int			cmd;

	if (!*lst)
		return (0);
	cmd = (*lst)->cmd;
	if (cmd != 6 && cmd != 9)
		return (0);
	res = 0;
	while (*lst)
	{
		if ((*lst)->cmd == cmd)
		{
			res++;
			*lst = (*lst)->next;
		}
		else
			break ;
	}
	return (res == 1 ? (0) : (res));
}

static int		same(t_cmdlist *lst)
{
	t_cmdlist	*t;

	t = lst;
	if (t->next && (t->cmd == 6 || t->cmd == 9)
			&& (t->next->cmd = 6 || t->next->cmd == 9))
		return (1);
	else
		return (0);
}

void			optimize_rorevrota(t_cmdlist **lst)
{
	int			i;
	int			j;
	t_cmdlist	*t;
	int			res;
	int			k;

	t = *lst;
	if (same(*lst))
	{
		i = get_howsame_rrra(&t);
		j = get_howsame_rrra(&t);
		if (!j || !i)
			return ;
		res = i < j ? i : j;
		k = -1;
		while (++k < res && res <= i && i && j)
			*lst = (*lst)->next;
		while (++k <= i && i && j)
			print_cmd(lst);
		k = -1;
		while (++k < res && res <= j && i && j)
			*lst = (*lst)->next;
		while (++k <= j && i && j)
			print_cmd(lst);
	}
}

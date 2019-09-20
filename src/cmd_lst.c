/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:00:03 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/20 18:30:51 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmd(t_cmdlist **lst)
{
	if (!*lst)
		return ;
	if ((*lst)->cmd == 1)
		write(1, "pa\n", 3);
	else if ((*lst)->cmd == 2)
		write(1, "pb\n", 3);
	else if ((*lst)->cmd == 3)
		write(1, "sa\n", 3);
	else if ((*lst)->cmd == 4)
		write(1, "sb\n", 3);
	else if ((*lst)->cmd == 6)
		write(1, "ra\n", 3);
	else if ((*lst)->cmd == 7)
		write(1, "rb\n", 3);
	else if ((*lst)->cmd == 9)
		write(1, "rra\n", 4);
	else if ((*lst)->cmd == 10)
		write(1, "rrb\n", 4);
	*lst = (*lst)->next;
}

void	add_cmd(t_cmdlist *head, int cmd)
{
	size_t		i;
	t_cmdlist	*tmp;

	tmp = head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = (t_cmdlist *)malloc(sizeof(t_cmdlist));
	if (!tmp->next)
		exit(-1);
	tmp = tmp->next;
	tmp->next = NULL;
	tmp->cmd = cmd;
}

void	cmd_optimize(t_cmdlist *head)
{
	t_cmdlist	*tmp;

	tmp = head;
	while (tmp)
	{
		optimize_push(&tmp);
		// optimize_rorevrota(&tmp);
		print_cmd(&tmp);
	}
}

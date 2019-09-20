/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:00:03 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/20 15:53:51 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int			check_ss(t_cmdlist **lst)
{
	int res;

	res = 0;
	if ((*lst)->cmd == 3 && (*lst)->next->cmd == 4)
		res = 5;
	if ((*lst)->cmd == 4 && (*lst)->next->cmd == 3)
		res = 5;
	if (res)
		*lst = (*lst)->next;
	return (res);
}

int			check_rr(t_cmdlist **lst)
{
	int res;

	res = 0;
	if ((*lst)->cmd == 6 && (*lst)->next->cmd == 7)
		res = 8;
	if ((*lst)->cmd == 7 && (*lst)->next->cmd == 6)
		res = 8;
	if (res)
		*lst = (*lst)->next;
	return (res);
}

int			check_rrr(t_cmdlist **lst)
{
	int res;

	res = 0;
	if ((*lst)->cmd == 9 && (*lst)->next->cmd == 10)
		return (11);
	if ((*lst)->cmd == 10 && (*lst)->next->cmd == 9)
		return (11);
	if (res)
		*lst = (*lst)->next;
	return (res);
}

static void	print_cmd(t_cmdlist **lst)
{
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

void		cmd_optimize(t_cmdlist *head)
{
	t_cmdlist	*tmp;

	tmp = head;
	// while (tmp)
	// {
	// 	if (tmp->cmd < 3)
	// 		print_cmd(&tmp);
	// 	else if (tmp->cmd == 3 || tmp->cmd == 4)
	// 		check_ss(&tmp) == 5 ? write(1, "ss\n", 3) : print_cmd(&tmp);
	// 	else if (tmp->cmd == 6 || tmp->cmd == 7)
	// 		check_rr(&tmp) == 8 ? write(1, "rr\n", 3) : print_cmd(&tmp);
	// 	else if (tmp->cmd == 9 || tmp->cmd == 10)
	// 		(check_rrr(&tmp) == 11) ? write(1, "rrr\n", 4) : print_cmd(&tmp);
	// 	// if (tmp && tmp->next)
	// 	// 	tmp = tmp->next;
	// }
	while (tmp)
		print_cmd(&tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:54:20 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/20 18:44:53 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				*rev_arr(int *arr, int len)
{
	int	i;
	int	tmp;

	i = 0;
	while (i <= len / 2)
	{
		tmp = arr[i];
		arr[i] = arr[len - i];
		arr[len - i] = tmp;
		i++;
	}
	return (arr);
}

static int		check_dubble(int *arr, int n)
{
	int	a[n];
	int	i;

	ft_memcpy(a, arr, n * sizeof(int));
	quick_sort(a, 0, n - 1);
	i = 0;
	while (++i < n)
		if (a[i - 1] == a[i])
			return (0);
	return (1);
}

static t_stack	*f_arg(char *str)
{
	char	**arr;
	t_stack	*s;
	int		i;

	if (!(arr = ft_strsplit(str, ' ')))
		return (NULL);
	i = 0;
	while (arr[i])
		i++;
	if (!i)
		return (ft_doublestrdel(&arr) + NULL);
	s = create_stack(i);
	i = -1;
	while (++i <= s->siza)
	{
		s->a[i] = ft_atoi(arr[i]);
		if (s->a[i] == 0 && arr[i][0] != '0')
			return (ft_doublestrdel(&arr) + delete_stack(s));
	}
	if (!check_dubble(s->a, s->siza + 1))
		return (ft_doublestrdel(&arr) + delete_stack(s));
	s->a = rev_arr(s->a, s->siza);
	ft_doublestrdel(&arr);
	return (s);
}

t_stack			*parse_input(int ac, char **av)
{
	t_stack	*res;
	int		i;

	if (!av || !(*av))
		return (NULL);
	if (ac == 1)
		return (f_arg(av[0]));
	res = create_stack(ac);
	i = -1;
	while (++i <= res->siza)
	{
		res->a[i] = ft_atoi(av[i]);
		if (res->a[i] == 0 && av[i][0] != '0')
			return (delete_stack(res));
	}
	if (!check_dubble(res->a, res->siza + 1))
		return (delete_stack(res));
	res->a = rev_arr(res->a, res->siza);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:14:26 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/04 20:30:22 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low - 1;
	while (++j <= high - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swap(&arr[j], &arr[i]);
		}
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void		quick_sort(int *arr, int low, int high)
{
	int	p;

	if (low < high)
	{
		p = partition(arr, low, high);
		quick_sort(arr, low, p - 1);
		quick_sort(arr, p + 1, high);
	}
}

int			get_median(int *arr, int n)
{
	int	a[n];

	ft_memcpy(a, arr, n * sizeof(int));
	quick_sort(a, 0, n - 1);
	return (a[n / 2]);
}

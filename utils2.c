/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:45:53 by aimalasi          #+#    #+#             */
/*   Updated: 2026/06/25 15:55:35 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(t_stack *a, int size)
{
	int	i;
	int	j;

	if (size == 1)
		return (0);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (a->arr[i] == a->arr[j])
				return (1);
			j++;
		}
		i++;
		if (i == size - 1)
			break ;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->arr[i] < a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_strncpy(char *dst, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

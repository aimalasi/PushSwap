/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:22:45 by aimalasi          #+#    #+#             */
/*   Updated: 2026/05/05 19:32:51 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

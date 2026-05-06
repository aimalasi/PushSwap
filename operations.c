/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:56:41 by aimalasi          #+#    #+#             */
/*   Updated: 2026/05/05 19:37:43 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	push(t_stack *dst, t_stack *src, char *name)
{
	if (src->top < 0)
		return ;
	dst->arr[++(dst->top)] = src->arr[(src->top)--];
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
}

void	swap(t_stack *s, char *name)
{
	int	tmp;

	if (s->top < 1)
		return ;
	tmp = s->arr[s->top];
	s->arr[s->top] = s->arr[s->top - 1];
	s->arr[s->top -1] = tmp;
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
}

void	rotate(t_stack *s, char *name)
{
	int	tmp;
	int	i;

	if (s->top < 1)
		return ;
	tmp = s->arr[s->top];
	i = s->top;
	while (i > 0)
	{
		s->arr[i] = s->arr[i - 1];
		i--;
	}
	s->arr[0] = tmp;
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
}

void	reverse_rotate(t_stack *s, char *name)
{
	int	tmp;
	int	i;

	if (s->top < 1)
		return ;
	tmp = s->arr[0];
	i = 0;
	while (i < s->top)
	{
		s->arr[i] = s->arr[i + 1];
		i++;
	}
	s->arr[s->top] = tmp;
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:59:47 by aimalasi          #+#    #+#             */
/*   Updated: 2026/03/24 16:28:58 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*arr;
	int	top;
	int	size;
} 	t_stack;

t_stack *init_stack(int size);
void	push(t_stack *dst, t_stack *src, char *name);
void	swap(t_stack *s, char *name);
void	rotate(t_stack *s, char *name);
void	reverse_rotate(t_stack *s, char *name);
void	normalize(t_stack *a, int size);
void	radix_sort(t_stack *a, t_stack *b, int size);
int		is_sorted(t_stack *a);
void	free_stack(t_stack *s);
void	error_exit(t_stack *a, t_stack *b);

#endif
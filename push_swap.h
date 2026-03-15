/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:59:47 by aimalasi          #+#    #+#             */
/*   Updated: 2026/03/14 17:15:41 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*arr;
	int	top;
	int	size;
} t_stack

t_stack	*init_stack(int  size);
void	push(t_stack *dst, t_stack *src, char *name);
void	swap(t_stack *s, char *name);
void	rotate(t_stack *s)
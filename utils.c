/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:35:05 by aimalasi          #+#    #+#             */
/*   Updated: 2026/03/24 16:41:34 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(int size)
{
    t_stack *s;

    s = malloc(sizeof(t_stack));
    if (!s)
        return (NULL);
    s->arr = malloc(sizeof(int) * size);
    if (!s->arr)
    {
        free(s);
        return (NULL);
    }
    s->top = -1;
    s->size = size;
    return (s);
}

void    free_stack(t_stack *s)
{
    if (!s)
        return;
    free(s->arr);
    free(s);
}

void    error_exit(t_stack *a, t_stack *b)
{
    free_stack(a);
    free_stack(b);
    write(2, "Error\n", 6);
    exit(1);
}
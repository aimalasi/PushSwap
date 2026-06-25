/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:59:47 by aimalasi          #+#    #+#             */
/*   Updated: 2026/06/25 16:37:54 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*arr;
	int	top;
	int	size;
}	t_stack;

t_stack	*init_stack(int size);
void	push(t_stack *dst, t_stack *src, char *name);
void	swap(t_stack *s, char *name);
void	rotate(t_stack *s, char *name);
void	reverse_rotate(t_stack *s, char *name);
void	normalize(t_stack *a, int size);
void	radix_sort(t_stack *a, t_stack *b, int size);
int		is_sorted(t_stack *a);
void	free_stack(t_stack *s);
void	error_exit(t_stack *a, t_stack *b);
int		is_valid_int(char *s);
int		has_duplicates(t_stack *a, int size);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	free_split(char **split);
void	ft_strncpy(char *dst, const char *src, int n);
int		count_words(char *s);
char	*get_word(char *s, int *i);
char	**split_string(char *s, int count);
void	load_stack(t_stack *a, t_stack *b, char **args, int size);

#endif
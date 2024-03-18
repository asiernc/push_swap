/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:16:22 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/05 10:29:47 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	last_three(t_stack **sta, t_stack **stb);

void	init_sort(t_stack **sta, t_stack **stb)
{
	int	len;

	len = lstsize(*sta);
	if (len == 4 || len == 5)
		pb(sta, stb);
	else
	{
		pb(sta, stb);
		pb(sta, stb);
	}
	len = lstsize(*sta);
	while (len > 3)
	{
		get_index(*sta);
		get_index(*stb);
		put_total_moves(*sta, *stb);
		do_moves(sta, stb);
		len--;
	}
	if (len == 3)
		last_three(sta, stb);
}

static void	clean_b(t_stack **sta, t_stack **stb)
{
	if ((*sta)->content < (*stb)->content)
	{
		if ((*sta)->sign == 1)
			ra(sta, stb);
		else
			rra(sta, stb);
	}
	else if ((*sta)->previous->content > (*stb)->content
		&& (*sta)->previous->content < (*sta)->content)
		rra(sta, stb);
	else
		pa(sta, stb);
}

static void	last_three(t_stack **sta, t_stack **stb)
{
	int		min;
	int		max_a;
	int		max_b;
	t_stack	*tmp;

	max_a = max_find(*sta);
	ft_size3(sta);
	get_index(*stb);
	max_b = max_find(*stb);
	tmp = search_node(max_b, *stb);
	while ((*stb)->content != max_b)
	{
		if (tmp->sign == 1)
			rb(sta, stb);
		else
			rrb(sta, stb);
	}
	get_index(*sta);
	if (max_b > max_a)
		pa(sta, stb);
	while (*stb != NULL)
		clean_b(sta, stb);
	min = min_find(*sta);
	while ((*sta)->content != min)
		rra(sta, stb);
}

void	get_index(t_stack *st)
{
	t_stack	*tmp;
	int		len_a;
	int		i;
	int		len;

	tmp = st;
	i = 0;
	len_a = lstsize(st);
	len = len_a;
	while (len_a > 0)
	{
		if (i < (len / 2) + (len % 2))
		{
			tmp->to_up = i;
			tmp->sign = 1;
		}
		else
		{
			tmp->to_up = len - i;
			tmp->sign = -1;
		}
		tmp = tmp->next;
		i++;
		len_a--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:59:34 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/01 12:26:59 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_find(t_stack *stack)
{
	t_stack	*current;
	t_stack	*max;

	current = stack->next;
	max = stack;
	while (current != stack)
	{
		if (current->content > max->content)
			max = current;
		current = current->next;
	}
	return (max->content);
}

int	min_find(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min;

	current = stack->next;
	min = stack;
	while (current != stack)
	{
		if (current->content < min->content)
			min = current;
		current = current->next;
	}
	return (min->content);
}

t_stack	*get_next_min(int num, t_stack *stb)
{
	t_stack	*tmp;

	tmp = stb->next;
	if (num == min_find(stb))
		return (stb);
	while (tmp != stb)
	{
		if (tmp->content == num)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	get_target(int num, t_stack **stb)
{
	t_stack	*tmp;
	int		i;
	int		target;

	target = 0;
	tmp = *stb;
	if (num < min_find(*stb))
		return (max_find(*stb));
	while (target == 0)
	{
		i = 0;
		--num;
		while (i++ < lstsize(*stb))
		{
			if (tmp->content == num)
			{
				target = 1;
				break ;
			}
			tmp = tmp->next;
		}
	}
	return (tmp->content);
}

void	put_total_moves(t_stack *sta, t_stack *stb)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		len;
	int		target;

	tmp_a = sta;
	tmp_b = stb;
	len = lstsize(sta);
	while (len--)
	{
		target = get_target(tmp_a->content, &stb);
		while (tmp_b->content != target)
			tmp_b = tmp_b->next;
		if ((tmp_a->sign == 1 && tmp_b->sign == 1)
			|| (tmp_a->sign == -1 && tmp_b->sign == -1))
		{
			if (tmp_a->to_up > tmp_b->to_up)
				tmp_a->cheapest = tmp_a->to_up;
			else
				tmp_a->cheapest = tmp_b->to_up;
		}
		else
			tmp_a->cheapest = tmp_a->to_up + tmp_b->to_up;
		tmp_a = tmp_a->next;
	}
}

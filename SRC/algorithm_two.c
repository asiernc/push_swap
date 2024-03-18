/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:26:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/05 10:30:37 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*find_cheapest(t_stack *sta)
{
	int		len;
	t_stack	*tmp;
	t_stack	*cheap;

	len = lstsize(sta);
	tmp = sta;
	cheap = NULL;
	if (tmp->cheapest == 1 && tmp->to_up == 0)
		cheap = tmp;
	while (len)
	{
		if (cheap == NULL || tmp->cheapest < cheap->cheapest)
			cheap = tmp;
		tmp = tmp->next;
		len--;
	}
	return (cheap);
}

static void	do_share_moves(t_stack **sta, t_stack **stb,
		t_stack *cheapest, t_stack *target)
{
	while (cheapest->to_up > 0 && target->to_up > 0
		&& cheapest->sign == target->sign)
	{
		if (cheapest->sign == 1)
			rr(sta, stb);
		else
			rrr(sta, stb);
		(cheapest->to_up)--;
		(target->to_up)--;
	}
	while ((cheapest->to_up)-- > 0)
	{
		if (cheapest->sign == 1)
			ra(sta, stb);
		else
			rra(sta, stb);
	}
	while ((target->to_up)-- > 0)
	{
		if (target->sign == 1)
			rb(sta, stb);
		else
			rrb(sta, stb);
	}
}

void	do_moves(t_stack **sta, t_stack **stb)
{
	t_stack	*tmpa;
	int		target;
	t_stack	*tmpb;

	tmpa = find_cheapest(*sta);
	target = get_target(tmpa->content, stb);
	tmpb = search_node(target, *stb);
	do_share_moves(sta, stb, tmpa, tmpb);
	pb(sta, stb);
}

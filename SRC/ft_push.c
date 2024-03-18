/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:17:21 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/05 11:36:22 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	modify_pointers(t_stack *tmp, t_stack **sta)
{
	if (*sta == NULL)
	{
		*sta = tmp;
		tmp->next = tmp;
		tmp->previous = tmp;
	}
	else
	{
		tmp->next = *sta;
		tmp->previous = (*sta)->previous;
		(*sta)->previous->next = tmp;
		(*sta)->previous = tmp;
		*sta = tmp;
	}
}

void	pa(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;

	if (*stb == NULL)
		return ;
	tmp = *stb;
	if ((*stb)->next == *stb)
		*stb = NULL;
	else
	{
		(*stb)->next->previous = (*stb)->previous;
		(*stb)->previous->next = (*stb)->next;
		*stb = (*stb)->next;
	}
	modify_pointers(tmp, sta);
	if (write(1, "pa\n", 3) == -1)
		ft_free_stacks(sta, stb);
}

void	pb(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;

	tmp = *sta;
	(*sta)->next->previous = (*sta)->previous;
	(*sta)->previous->next = (*sta)->next;
	*sta = (*sta)->next;
	if (*stb == NULL)
	{
		*stb = tmp;
		tmp->next = tmp;
		tmp->previous = tmp;
	}
	else
	{
		tmp->next = *stb;
		tmp->previous = (*stb)->previous;
		(*stb)->previous->next = tmp;
		(*stb)->previous = tmp;
		*stb = tmp;
	}
	if (write(1, "pb\n", 3) == -1)
		ft_free_stacks(sta, stb);
}

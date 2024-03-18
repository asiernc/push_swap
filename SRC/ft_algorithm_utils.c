/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:45:24 by anovio-c          #+#    #+#             */
/*   Updated: 2024/02/29 11:40:59 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	index_pos(t_stack *sw)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = sw->previous;
	while (sw != tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i + 1);
}

int	lstsize(t_stack *st)
{
	t_stack	*tmp;
	int		i;

	tmp = st;
	i = 1;
	while (tmp->next != st)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_stack	*search_node(int num, t_stack *st)
{
	t_stack	*tmp;

	tmp = st;
	while (tmp->content != num)
		tmp = tmp->next;
	if (tmp->content == num)
		return (tmp);
	else
		return (0);
}

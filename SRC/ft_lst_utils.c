/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:48:54 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/05 11:39:01 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*new_node(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = num;
	new->next = new;
	new->previous = new;
	return (new);
}

void	lst_front(t_stack **sw, t_stack *new)
{
	if (!new)
		return ;
	if (!*sw)
	{
		new->next = new;
		new->previous = new;
	}
	else
	{
		new->next = *sw;
		new->previous = (*sw)->previous;
		(*sw)->previous = new;
	}
	*sw = new;
}

t_stack	*get_last(t_stack *sw)
{
	t_stack	*last_node;

	last_node = sw;
	if (sw == NULL)
		return (NULL);
	while (last_node->next != sw)
		last_node = last_node->next;
	return (last_node);
}

void	ft_lstclear(t_stack **lst, void (*del)(int))
{
	int		len;
	t_stack	*tmp;

	tmp = NULL;
	len = lstsize(*lst);
	if (del)
		del((*lst)->content);
	while (len--)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	ft_free_stacks(t_stack **sta, t_stack **stb)
{
	if (sta)
		ft_lstclear(sta, NULL);
	if (stb)
		ft_lstclear(stb, NULL);
	exit(1);
}

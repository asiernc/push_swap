/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:57:55 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/05 10:28:34 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_size3(t_stack **sta)
{
	if (((*sta)->content > (*sta)->next->content)
		&& ((*sta)->content > (*sta)->previous->content))
		ra(sta, NULL);
	else if ((*sta)->content < (*sta)->next->content
		&& (*sta)->next->content > (*sta)->previous->content)
		rra(sta, NULL);
	if ((*sta)->content > (*sta)->next->content)
		sa(*sta);
}

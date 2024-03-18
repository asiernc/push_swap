/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:59:28 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/05 11:37:29 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **sta, t_stack **stb)
{
	*sta = (*sta)->previous;
	if (write(1, "rra\n", 4) == -1)
		ft_free_stacks(sta, stb);
}

void	rrb(t_stack **sta, t_stack **stb)
{
	*stb = (*stb)->previous;
	if (write(1, "rrb\n", 4) == -1)
		ft_free_stacks(sta, stb);
}

void	rrr(t_stack **sta, t_stack **stb)
{
	*sta = (*sta)->previous;
	*stb = (*stb)->previous;
	if (write(1, "rrr\n", 4) == -1)
		ft_free_stacks(sta, stb);
}

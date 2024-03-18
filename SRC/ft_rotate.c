/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:57:47 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/05 11:41:14 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **sta, t_stack **stb)
{
	*sta = (*sta)->next;
	if (write(1, "ra\n", 3) == -1)
		ft_free_stacks(sta, stb);
}

void	rb(t_stack **sta, t_stack **stb)
{
	*stb = (*stb)->next;
	if (write(1, "rb\n", 3) == -1)
		ft_free_stacks(sta, stb);
}

void	rr(t_stack **sta, t_stack **stb)
{
	*sta = (*sta)->next;
	*stb = (*stb)->next;
	if (write(1, "rr\n", 3) == -1)
		ft_free_stacks(sta, stb);
}

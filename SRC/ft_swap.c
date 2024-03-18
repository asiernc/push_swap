/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:42:00 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/05 12:09:54 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *sta)
{
	int	tmp;

	tmp = sta->content;
	sta->content = sta->next->content;
	sta->next->content = tmp;
	if (write(1, "sa\n", 3) == -1)
		ft_free_stacks(&sta, NULL);
}

void	sb(t_stack *stb)
{
	int	tmp;

	tmp = stb->content;
	stb->content = stb->next->content;
	stb->next->content = tmp;
	if (write(1, "sb\n", 3) == -1)
		ft_free_stacks(NULL, &stb);
}

void	ss(t_stack *sta, t_stack *stb)
{
	int	tmp;

	tmp = sta->content;
	sta->content = sta->next->content;
	sta->next->content = tmp;
	tmp = stb->content;
	stb->content = stb->next->content;
	stb->next->content = tmp;
	if (write(1, "ss\n", 3) == -1)
		ft_free_stacks(&sta, &stb);
}

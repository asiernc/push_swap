/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:48:45 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/05 12:07:15 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	char	**str;
	t_stack	*sta;

	if (argc == 1)
		return (0);
	str = ft_formatter(argc, argv);
	if (!str)
		return (-1);
	sta = ft_start(str);
	if (sta == NULL)
		return (-1);
	if (ft_check_order(sta) == 0)
	{
		ft_lstclear(&sta, NULL);
		ft_free(str);
		return (0);
	}
	ft_size(ft_strlen_double(str), &sta);
	ft_free(str);
	ft_lstclear(&sta, NULL);
	return (0);
}

t_stack	*ft_start(char **str)
{
	t_stack	*sta;
	t_stack	*temp;
	int		len;
	int		tmp;

	len = ft_strlen_double(str) - 1;
	tmp = atoi_sw(str[len]);
	sta = new_node(tmp);
	len--;
	while (len >= 0)
	{
		tmp = atoi_sw(str[len]);
		temp = new_node(tmp);
		if (!temp)
			return (NULL);
		lst_front(&sta, temp);
		len--;
	}
	sta->previous->next = sta;
	return (sta);
}

int	ft_size(int argc, t_stack **sta)
{
	t_stack	*stb;

	stb = NULL;
	if (argc == 2 || argc == 3)
		ft_size3(sta);
	else
		init_sort(sta, &stb);
	return (0);
}

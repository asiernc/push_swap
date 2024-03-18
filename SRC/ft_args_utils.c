/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:48:54 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/01 12:20:23 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**ft_parse(int argc, char **argv)
{
	char	**str;
	int		i;
	int		j;

	str = (char **)malloc((argc) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 1;
	while (i < argc - 1)
	{
		str[i] = ft_strdup(argv[j++]);
		if (!str[i])
		{
			while (i >= 0)
			{
				free(str[i]);
				i--;
			}
			return (free(str), NULL);
		}
		i++;
	}
	str[i] = NULL;
	return (str);
}

long int	atoi_sw(char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (sign * res);
}

int	ft_strlen_double(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		i++;
	}
	return (i);
}

int	ft_check_order(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
			return (-1);
		if (tmp == stack)
		{
			if (tmp->content > stack->content)
				return (0);
			else
				return (-1);
		}
	}
	return (0);
}

void	ft_free(char **str)
{
	int	len;

	len = ft_strlen_double(str) - 1;
	while (len >= 0)
	{
		free(str[len]);
		len--;
	}
	free(str);
}

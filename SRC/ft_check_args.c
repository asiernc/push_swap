/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:46:37 by anovio-c          #+#    #+#             */
/*   Updated: 2024/03/05 12:04:06 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_doubles(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (atoi_sw(str[i]) > 2147483647 || atoi_sw(str[i]) < -2147483648)
			return (-1);
		j = i + 1;
		while (str[j])
		{
			if (atoi_sw(str[i]) == atoi_sw(str[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_check_max_num(char **str)
{
	int	i;
	int	j;
	int	digit;

	i = 0;
	while (str[i])
	{
		j = 0;
		digit = 0;
		while (str[i][j] && (str[i][j] == '-' || str[i][j] == '0'))
			j++;
		while (str[i][j] && ft_isdigit(str[i][j]))
		{
			digit++;
			j++;
		}
		if (digit > 10)
			return (-1);
		else
			i++;
	}
	return (0);
}

int	ft_check_num(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		if ((str[i][j] == '-' && ft_isdigit(str[i][j + 1]))
			|| ft_isdigit(str[i][j]))
		{
			if (str[i][j] == '-')
				j++;
			while (str[i][j])
			{
				if (!ft_isdigit(str[i][j]))
					return (-1);
				j++;
			}
		}
		else
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_args(char **strs)
{
	int	i;
	int	len;
	int	flag;

	i = 0;
	len = 0;
	flag = 0;
	while (strs[len])
		len++;
	if (ft_check_doubles(strs) == -1 || ft_check_max_num(strs))
		flag = 1;
	while (i < len)
	{
		if (ft_check_num(&strs[i]) == -1)
			flag = 1;
		i++;
	}
	if (flag == 1)
	{
		ft_free(strs);
		if (write(2, "Error\n", 6) == -1)
			exit(1);
		return (-1);
	}
	return (0);
}
	/*if (ft_check_doubles(strs) == -1 || ft_check_max_num(strs))
	{
		ft_free(strs);
		if (write(2, "Error\n", 6) == -1)
			exit(1);
		return (-1);
	}
	while (i < len)
	{
		if (ft_check_num(&strs[i]) == -1)
		{
			ft_free(strs);
			write(2, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (0);
}*/

char	**ft_formatter(int argc, char **argv)
{
	char	**str;

	str = ft_parse(argc, argv);
	if (str != NULL)
		if (ft_check_args(str) == -1)
			return (NULL);
	return (str);
}

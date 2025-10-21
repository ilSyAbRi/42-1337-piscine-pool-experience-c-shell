/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:00:17 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/08/31 14:51:39 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);

char	*ft_itoi_base(int nb, char *base_to);

int	is_nvalid(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (ft_strlen(str) < 2)
		return (1);
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[i] == str[j] && i != j)
				return (1);
			j++;
		}
		if ((str[i] == '-' || str[i] == '+')
			|| (str[i] >= 9 && str[i] <= 13)
			|| (str[i] == 32))
			return (1);
		i++;
	}
	return (0);
}

int	base_value(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

long long	ft_atoi_base(char *str, char *base)
{
	int			i;
	int			sign;
	long long	result;
	int			len_base;

	len_base = ft_strlen(base);
	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (base_value(base, str[i]) != -1)
	{
		result = result * len_base + (base_value(base, str[i]));
		i++;
	}
	return (result * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	result;
	char		*arr;

	if (is_nvalid(base_to) || is_nvalid(base_from))
		return (NULL);
	result = ft_atoi_base(nbr, base_from);
	arr = ft_itoi_base((int)result, base_to);
	return (arr);
}

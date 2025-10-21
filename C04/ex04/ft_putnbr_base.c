/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:21:03 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/08/24 13:13:30 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_nvalid(char *str)
{
	int	i;
	int	j;

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
		if (str[i] == '-' || str[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			len_base;
	long long	large;

	large = nbr;
	if (is_nvalid(base))
		return ;
	len_base = ft_strlen(base);
	if (large < 0)
	{
		large = large * -1;
		ft_putchar('-');
	}
	if (large >= len_base)
		ft_putnbr_base(large / len_base, base);
	ft_putchar(base[large % len_base]);
}

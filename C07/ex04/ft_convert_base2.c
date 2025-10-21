/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:54:19 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/08/31 14:50:20 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_degit(long long nb, int base_len)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb != 0)
	{
		count++;
		nb = nb / base_len;
	}
	return (count);
}

void	ft_swap(int start, int end, char *str)
{
	int	temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}

int	convert(long long nb, char *arr, char *base, int *first)
{
	int	base_len;
	int	i;

	i = 0;
	base_len = ft_strlen(base);
	if (nb < 0)
	{
		nb = nb * -1;
		arr[i] = '-';
		i++;
		*first = 1;
	}
	while (nb != 0)
	{
		arr[i] = base[nb % base_len];
		nb = nb / base_len;
		i++;
	}
	arr[i] = '\0';
	return (i - 1);
}

char	*ft_itoi_base(int nb, char *base_to)
{
	int			i;
	int			nb_degit;
	int			first;
	long long	nbr;
	char		*arr;

	first = 0;
	nbr = (long long)nb;
	nb_degit = count_degit(nbr, ft_strlen(base_to));
	arr = malloc(sizeof(char) * (nb_degit + 1));
	if (arr == NULL)
		return (NULL);
	if (nbr == 0)
	{
		arr[0] = base_to[0];
		arr[1] = '\0';
		return (arr);
	}
	i = convert(nbr, arr, base_to, &first);
	ft_swap(first, i, arr);
	return (arr);
}

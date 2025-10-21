/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:58:28 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/08/19 10:20:07 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	do_lower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	in;

	i = 0;
	in = 0;
	do_lower(str);
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && (in == 0))
		{
			str[i] = str[i] - 32;
			in = 1;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			in = 1;
		else if ((!(str[i] >= 'a' && str[i] <= 'z')) && (in == 1))
			in = 0;
		i++;
	}
	return (str);
}

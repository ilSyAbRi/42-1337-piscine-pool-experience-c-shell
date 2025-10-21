/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:13:29 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/09/02 18:38:37 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*point;
	int			i;

	i = 0;
	point = malloc(sizeof(t_stock_str) * (ac + 1));
	if (point == NULL)
		return (NULL);
	while (i < ac)
	{
		point[i].size = ft_strlen(av[i]);
		point[i].str = av[i];
		point[i].copy = malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		if (point[i].copy == NULL)
			return (NULL);
		ft_strcpy(point[i].copy, av[i]);
		i++;
	}
	point[i].str = 0;
	return (point);
}

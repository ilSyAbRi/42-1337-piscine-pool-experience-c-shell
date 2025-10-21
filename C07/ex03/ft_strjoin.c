/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:18:09 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/08/28 17:01:07 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	modify(char *arr, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			arr[e++] = strs[i][j++];
		j = 0;
		if (i < size - 1)
			while (sep[j])
				arr[e++] = sep[j++];
		i++;
	}
	arr[e] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (size == 0)
	{
		arr = malloc(sizeof(char));
		if (arr == NULL)
			return (NULL);
		arr[0] = '\0';
		return (arr);
	}
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	arr = malloc (sizeof(char) * ((len + (ft_strlen(sep) * (size - 1))) + 1));
	if (arr == NULL)
		return (NULL);
	modify(arr, strs, sep, size);
	return (arr);
}
/*
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main()
{
	char *arr[] = {"iliass", "syabri", "be"};
	char sep[] = {","};
	char *str = ft_strjoin(3, arr, sep);
	if (str == NULL)
		return 1;
	ft_putstr(str);
}*/

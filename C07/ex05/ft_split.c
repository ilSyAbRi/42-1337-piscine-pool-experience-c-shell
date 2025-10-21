/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:26:37 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/08/31 13:04:27 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_seperator(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!is_seperator(charset, str[i]))
		{
			count++;
			while (str[i] && !is_seperator(charset, str[i]))
				i++;
			i--;
		}
		i++;
	}
	return (count);
}

int	count_letter(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_seperator(charset, str[i]))
		i++;
	return (i);
}

char	*ft_allocate(char **arr, char *str, int n)
{
	int	i;

	i = 0;
	*arr = malloc(sizeof(char) * (n + 1));
	if (*arr == NULL)
		return (NULL);
	while (i < n)
	{
		(*arr)[i] = str[i];
		i++;
	}
	(*arr)[i] = '\0';
	return (*arr);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		word;
	int		letter;
	char	**arr;

	i = 0;
	j = 0;
	word = count_word(str, charset);
	arr = malloc(sizeof(char *) * (word + 1));
	if (arr == NULL)
		return (NULL);
	while (i < word)
	{
		while (str[j] && is_seperator(charset, str[j]))
			j++;
		letter = count_letter(&str[j], charset);
		if (ft_allocate(&arr[i], &str[j], letter) == NULL)
			return (NULL);
		j = j + letter;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
/*int main()
{
	char *arr = "  a,,b c";
	char **str = ft_split(arr,",");
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n",str[i]);
	i++;
	}
}*/

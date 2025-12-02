/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yramouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:25:28 by yramouch          #+#    #+#             */
/*   Updated: 2025/08/17 19:28:41 by yramouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	row(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar('/');
		else if (i == x -1)
			ft_putchar('\\');
		else
			ft_putchar('*');
		i++;
	}
}

void	mid(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar('*');
		else if (i == x - 1)
			ft_putchar('*');
		else
			ft_putchar(' ');
		i++;
	}
}

void	last(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
		{
			ft_putchar('\\');
		}
		else if (i == x - 1)
		{
			ft_putchar('/');
		}
		else
		{
			ft_putchar('*');
		}
		i++;
	}
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (x <= 0 || y <= 0)
		return ;
	while (i < y)
	{
		if (i == 0)
			row(x);
		else if (i == y - 1)
			last(x);
		else
			mid(x);
		ft_putchar('\n');
		i++;
	}
}

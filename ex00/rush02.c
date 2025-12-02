/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yramouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:32:56 by yramouch          #+#    #+#             */
/*   Updated: 2025/08/17 19:22:18 by yramouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	row(int x)
{
	int	co;

	co = 1;
	while (co <= x)
	{
		if (co == 1)
		{
			ft_putchar('A');
		}
		else if (co == x)
		{
			ft_putchar('A');
		}
		else
		{
			ft_putchar('B');
		}
		co++;
	}
}

void	mid(int x)
{
	int	co;

	co = 1;
	while (co <= x)
	{
		if (co == 1)
		{
			ft_putchar('B');
		}
		else if (co == x)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		co++;
	}
}

void	last(int x)
{
	int	co;

	co = 1;
	while (co <= x)
	{
		if (co == 1)
		{
			ft_putchar('C');
		}
		else if (co == x)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
		co++;
	}
}

void	rush(int x, int y)
{
	int	i;

	i = 1;
	if (x <= 0 || y <= 0)
		return ;
	while (i <= y)
	{
		if (i == 1)
			row(x);
		else if (i == y)
			last(x);
		else
			mid(x);
		ft_putchar('\n');
		i++;
	}
}

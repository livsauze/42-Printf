/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:34:02 by livsauze          #+#    #+#             */
/*   Updated: 2024/02/19 16:01:37 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n >= 0 && n <= 9)
	{
		count += ft_putchar((n + '0'));
	}
	else if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr((n * (-1)));
	}
	else
	{
		count += ft_putnbr((n / 10));
		count += ft_putnbr((n % 10));
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr_unsigned((n / 10));
		count += ft_putnbr_unsigned((n % 10));
	}
	else
		count += ft_putchar((n + '0'));
	return (count);
}

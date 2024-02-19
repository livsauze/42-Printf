/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:51:44 by livsauze          #+#    #+#             */
/*   Updated: 2023/11/01 15:28:25 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(unsigned long int n, int c)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_print_x((n / 16), c);
		count += ft_print_x((n % 16), c);
	}
	else
	{
		if (n > 9 && c == 1)
			count += ft_putchar(n + 'a' - 10);
		else if (n > 9 && c == 2)
			count += ft_putchar(n + 'A' - 10);
		else
			count += ft_putchar(n + '0');
	}
	return (count);
}

int	ft_put_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	count += ft_putstr("0x");
	count += ft_print_x(ptr, 1);
	return (count);
}

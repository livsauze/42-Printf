/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:12:31 by livsauze          #+#    #+#             */
/*   Updated: 2024/02/19 16:01:30 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_print_format(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_print_x(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		count += ft_print_x(va_arg(args, unsigned int), 2);
	else if (c == 'p')
		count += ft_put_ptr(va_arg(args, unsigned long long));
	va_end(args);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_print_format(args, format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

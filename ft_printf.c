/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:44:07 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/03/29 17:32:43 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(char s, va_list *arg)
{
	if (s == 'i' || s == 'd')
		return (ft_putnbr(va_arg(*arg, int)));
	else if (s == 'c')
		return (ft_putchar(va_arg(*arg, int)));
	else if (s == 's')
		return (ft_putstr(va_arg(*arg, char *)));
	else if (s == 'p')
		return (ft_point(va_arg(*arg, unsigned long long)));
	else if (s == 'u')
		return (ft_unputnbr(va_arg(*arg, unsigned int)));
	else if (s == 'x')
		return (ft_low(va_arg(*arg, unsigned int)));
	else if (s == 'X')
		return (ft_up(va_arg(*arg, unsigned int)));
	else if (s == '%')
		return (write (1, "%%", 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		count;

	va_start(arg, s);
	count = 0;
	while (s && *s)
	{
		if (*s == '%')
			count += check(*++s, &arg);
		else
			count += write(1, s, 1);
		s++;
	}
	va_end(arg);
	return (count);
}

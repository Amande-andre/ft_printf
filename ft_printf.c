/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:43:16 by anmande           #+#    #+#             */
/*   Updated: 2022/06/24 14:52:31 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>

unsigned int	ft_process(va_list args, char s);

int	ft_printf(const char *s, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	len;

	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i])
	{	
		if (s[i] != '%')
			len += ft_putchar_fd(s[i], 1);
		else if (s[i] == '%')
		{
			i++;
			len += ft_process(args, s[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}

unsigned int	ft_process(va_list args, char s)
{
	char	*base;
	char	*base_up;

	base = "0123456789abcdef";
	base_up = "0123456789ABCDEF";
	if (s == '%')
		return (ft_putchar_fd('%', 1));
	else if (s == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (s == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (s == 'd' || s == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1, 0));
	else if (s == 'x')
		return (ft_flagx(va_arg(args, unsigned long long int), 1, base));
	else if (s == 'X')
		return (ft_flagx(va_arg(args, unsigned long long int), 1, base_up));
	else if (s == 'p')
		return (ft_flagp(va_arg(args, long unsigned int), 1, base));
	else if (s == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int), 1, 0));
	return (0);
}

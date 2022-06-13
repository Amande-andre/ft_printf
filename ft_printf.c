/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:43:16 by anmande           #+#    #+#             */
/*   Updated: 2022/06/13 12:22:07 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libprintf.h"
#include "unistd.h"
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list args;
	size_t	len;
	size_t i;

	len = 0;
	i = -1;
	va_start(args, s);
	while (s[++i])
	{	
		if (s[i] != '%')
			len += ft_putchar_fd(s[i], 1);
		if (s[i] == '%' && s[i + 1] == 'c')
		{
			len = len + ft_putchar_fd(va_arg(args, size_t), 1);
			i++;
		}
		if (s[i] == '%' && s[i + 1] == 's')
		{
			len += ft_putstr_fd(va_arg(args, char *), 1);
			i++;
		}
		if (s[i] == '%' && (s[i + 1] == 'd' || s[i + 1] == 'i'))
		{
			len = len + ft_putnbr_fd(va_arg(args, int), 1, 1);
			i++;
		}
		if (s[i] == '%' && s[i + 1] == 'x')
		{
			len += ft_flagx(va_arg(args, int), 1, 0, "0123456789abcdef");
			i++;
		}
	}
	va_end(args);
	return (len);
}

int	main()
{
	// char *s;

	// s = "test";
	int n = 32;
	//int i = 100;
	printf(" %d\n", ft_printf("%x", n));
}

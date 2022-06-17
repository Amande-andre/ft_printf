/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:43:16 by anmande           #+#    #+#             */
/*   Updated: 2022/06/17 13:46:49 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libprintf.h"
#include "unistd.h"
#include <stdio.h>

int	ft_process(unsigned long i, va_list args, const char *s);

int	ft_printf(const char *s, ...)
{
	va_list			args;
	unsigned long	i;
	unsigned long	len;
	
	va_start(args, s);
	i = -1;
	len = 0;
	while (s[++i])
	{	
		if (s[i] != '%')
			len += ft_putchar_fd(s[i], 1);
		else if (s[i] == '%')
		{
			len += ft_process(len, args, s);
			i++;
		}
	}
	va_end(args);
	return (len);
}

int	ft_process(unsigned long i, va_list args, const char *s)
{
	if (s[i] != '%')
	{
		ft_putchar_fd(s[i], 1);
		//i++;
	}	
	else if (s[i] == '%' && s[i + 1] == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (s[i] == '%' && s[i + 1] == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (s[i] == '%' && (s[i + 1] == 'd' || s[i + 1] == 'i'))
		return (ft_putnbr_fd(va_arg(args, int), 1, 0));
	else if (s[i] == '%' && s[i + 1] == 'x')
		return (ft_flagx(va_arg(args, int), 1, "0123456789abcdef", 0));
	else if (s[i] == '%' && s[i + 1] == 'X')
		return (ft_flagx(va_arg(args, int), 1, "0123456789ABCDEF", 0));	
	// if (s[i] == '%' && s[i 1] == 'p')
	return (0);
}

int	main()
{
	//int n = 32;
	int i = 42;
	//printf(" %d\n", ft_printf("%d%x", i, n));
	printf("%d\n", ft_printf("%d\n", i));
	printf("%d\n", printf("%d\n", i));
}

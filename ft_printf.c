/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:43:16 by anmande           #+#    #+#             */
/*   Updated: 2022/06/13 17:41:17 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libprintf.h"
#include "unistd.h"
#include <stdio.h>

void	ft_process(t_value *value, va_list args, const char *s);

int	ft_printf(const char *s, ...)
{
	va_list args;
	t_value value;
	
	value.index = 0;
	value.len = 0;
	va_start(args, s);
	while (s[value.index])
	{	
		ft_process(&value, args, s);
	}
	va_end(args);
	printf("%d\n", value.len);
	return (value.len);
}

void	ft_process(t_value *value, va_list args, const char *s)
{
	if (s[value->index] != '%')
	{
		ft_putchar_fd(s[value->index], 1,  value);
		//value->index++;
	}	
	else if (s[value->index] == '%' && s[value->index + 1] == 'c')
		ft_putchar_fd(va_arg(args, int), 1, value);
	else if (s[value->index] == '%' && s[value->index + 1] == 's')
		ft_putstr_fd(va_arg(args, char *), 1, value);
	else if (s[value->index] == '%' && (s[value->index + 1] == 'd' || s[value->index + 1] == 'i'))
		ft_putnbr_fd(va_arg(args, int), 1, value);
	else if (s[value->index] == '%' && s[value->index + 1] == 'x')
		ft_flagx(va_arg(args, int), 1, "0123456789abcdef", value);
	else if (s[value->index] == '%' && s[value->index + 1] == 'X')
		ft_flagx(va_arg(args, int), 1, "0123456789ABCDEF", value);	
	// if (s[value->index] == '%' && s[value->index 1] == 'p')
	if (s[value->index++] == '%')
		value->index += 2;
}

int	main()
{
	 
	//int n = 32;
	int i = 42;
	//printf(" %d\n", ft_printf("%d%x", i, n));
	ft_printf("test || %s\n%d", "test ", i);
}

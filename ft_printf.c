/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:43:16 by anmande           #+#    #+#             */
/*   Updated: 2022/06/13 15:10:33 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libprintf.h"
#include "unistd.h"
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list args;

	struct s_value t_value = {0, -1};
	va_start(args, s);
	while (s[t_value.index])
	{	
		if (s[t_value.index] != '%')
			t_value.len += ft_putchar_fd(s[t_value.index], 1);
		if (s[t_value.index] == '%' && s[t_value.index 1] == 'c')
		{
			t_value.len = t_value.len + ft_putchar_fd(va_arg(args, size_t), 1);
			t_value.index++;
		}
		if (s[t_value.index] == '%' && s[t_value.index 1] == 's')
		{
			t_value.len += ft_putstr_fd(va_arg(args, char *), 1);
			t_value.index++;
		}
		if (s[t_value.index] == '%' && (s[t_value.index + 1] == 'd' || s[t_value.index + 1] == 'i'))
		{
			t_value.len = t_value.len + ft_putnbr_fd(va_arg(args, int), 1, 1);
			t_value.index++;
		}
		if (s[t_value.index] == '%' && s[t_value.index + 1] == 'x')
		{
			t_value.len += ft_flagx(va_arg(args, int), 1, 0, "0123456789abcdef");
			t_value.index++;
		}
		if (s[t_value.index] == '%' && s[t_value.index + 1] == 'X')
		{
			t_value.len += ft_flagx(va_arg(args, int), 1, 0, "0123456789ABCDEF");
			t_value.index++;
		}
		// if (s[t_value.index] == '%' && s[t_value.index 1] == 'p')
		// {
		// 	void	*ptr = va_arg(args, size_t);
		// 	t_value.index++;
		// }
	}
	va_end(args);
	return (t_value.len);
}

int	main()
{
	 
	int n = 32;
	int i = 100;
	printf(" %d\n", ft_printf("%d%x", i, n));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:43:16 by anmande           #+#    #+#             */
/*   Updated: 2022/06/22 18:09:03 by anmande          ###   ########.fr       */
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
	if (s == '%')
		return(ft_putchar_fd('%', 1));
	else if (s == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (s == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (s == 'd' || s == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1, 0));
	else if (s == 'x')
		return (ft_flagx(va_arg(args, int), 1, "0123456789abcdef"));
	else if (s == 'X')
		return (ft_flagx(va_arg(args, int), 1, "0123456789ABCDEF"));	
	else if (s == 'p')
		return (ft_flagp(va_arg(args, long unsigned int), 1, "0123456789abcdef"));
	else if (s == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int), 1, 0));
	return (0);
}

// int	main()
// {
// 	char 	*n = NULL;
// 	char	*ptr = "truc";
// 	printf("%d", printf("%c%d%%%%c%c%s%d%d%x%p%p%u%s%s", 'a', 42, 'b', ptr, 4242, -545, 20000242, n, ptr, -42424242, n, "ok"));
// 	printf("\n");
// 	printf("%d", ft_printf("%c%d%%%%c%c%s%d%d%x%p%p%u%s%s", 'a', 42, 'b', ptr, 4242, -545, 20000242, n, ptr, -42424242, n, "ok"));
	
// 	// printf("==%d", printf("%d", -123456789));
// 	// printf("==%d", ft_printf("%d", -123456789));
// }
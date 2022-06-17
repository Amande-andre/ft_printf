/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:49:43 by anmande           #+#    #+#             */
/*   Updated: 2022/06/17 18:45:41 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>

unsigned int	ft_flagp(unsigned long int n, int fd, char *base)
{
	unsigned int		len;	
	unsigned long	p;

	p = n;	
	len = 0;
	if (p >= 16)
		len += ft_flagp(p / 16, fd, base);
	else if (p == n)
		len += ft_putstr_fd("0x", 1);
	len += ft_putchar_fd(base[p % 16], fd);
	return (len);
}

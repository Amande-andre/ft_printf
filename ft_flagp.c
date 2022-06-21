/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:49:43 by anmande           #+#    #+#             */
/*   Updated: 2022/06/21 16:15:20 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>

unsigned int	ft_flagp(unsigned long int n, int fd, char *base)
{
	unsigned long long	len;	
	unsigned long int	p;

	p = n;	
	len = 0;
	if (p >= 16)
		len += ft_flagp(p / 16, fd, base);
	else if (p == n)
		len += ft_putstr_fd("0x", 1);
	len += ft_putchar_fd(base[p % 16], fd);
	return (len);
}

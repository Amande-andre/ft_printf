/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:01:23 by anmande           #+#    #+#             */
/*   Updated: 2022/06/17 13:47:10 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

unsigned long	ft_flagx(int n, int fd, char *base, unsigned long len)
{
	size_t	nb;

	nb = n;

	if (nb >= 16)
	{
		len += ft_flagx(nb / 16, fd, base, len);
		len += ft_putchar_fd(base[nb % 16], fd);
	}
	return (len);
}
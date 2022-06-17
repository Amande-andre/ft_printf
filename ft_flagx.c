/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:01:23 by anmande           #+#    #+#             */
/*   Updated: 2022/06/17 18:45:29 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

unsigned int	ft_flagx(long long unsigned int n, int fd, char *base)
{
	int				nb;
	unsigned int	len;
	nb = n;
	len = 0;
	if (nb >= 16)
		len += ft_flagx(nb / 16, fd, base);
	len += ft_putchar_fd(base[nb % 16], fd);
	return (len);
}
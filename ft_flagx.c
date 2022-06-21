/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:01:23 by anmande           #+#    #+#             */
/*   Updated: 2022/06/21 16:03:28 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

unsigned int	ft_flagx(size_t n, int fd, char *base)
{
	size_t	nb;
	unsigned int	len;
	nb = n;
	len = 0;
	if (nb >= 16)
		len += ft_flagx(nb / 16, fd, base);
	len += ft_putchar_fd(base[nb % 16], fd);
	return (len);
}
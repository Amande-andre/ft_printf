/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:01:23 by anmande           #+#    #+#             */
/*   Updated: 2022/06/24 14:45:11 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

unsigned int	ft_flagx(unsigned long long int n, int fd, char *base)
{
	unsigned long long int	nb;
	unsigned int			len;

	nb = n;
	len = 0;
	if (nb >= 16)
		len += ft_flagx(nb / 16, fd, base);
	len += ft_putchar_fd(base[nb % 16], fd);
	return (len);
}

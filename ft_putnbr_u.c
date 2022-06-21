/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:40:18 by anmande           #+#    #+#             */
/*   Updated: 2022/06/21 16:46:09 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

unsigned int	ft_putnbr_u(unsigned int n, int fd, unsigned int len)
{
	size_t			nb;

	nb = n;	
	if (nb >= 10)
	{
		len += ft_putnbr_u(nb / 10, fd, len);
	}
	len += ft_putchar_fd((nb % 10) + '0', fd);
	return (len);	
}

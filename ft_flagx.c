/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:01:23 by anmande           #+#    #+#             */
/*   Updated: 2022/06/13 12:21:52 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

size_t	ft_flagx(int n, int fd, size_t i, char *base)
{
	size_t	nb;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
		i++;
	}	
	if (nb >= 16)
	{
		ft_flagx(nb / 16, fd, i++, base);
	}
	ft_putchar_fd(base[nb % 16], fd);
	i++;
	return (i);
}
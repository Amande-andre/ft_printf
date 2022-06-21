/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:44:24 by anmande           #+#    #+#             */
/*   Updated: 2022/06/21 16:42:32 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_putnbr_fd(int n, int fd, unsigned int len)
{
	size_t			nb;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		len += ft_putchar_fd('-', fd);
	}	
	// if (nb <= 9)
	// 	ft_putchar_fd(nb + '0', fd, );
	if (nb >= 10)
	{
		len += ft_putnbr_fd(nb / 10, fd, len);
	}
	len += ft_putchar_fd((nb % 10) + '0', fd);
	return (len);
}

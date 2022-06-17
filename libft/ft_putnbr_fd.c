/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:44:24 by anmande           #+#    #+#             */
/*   Updated: 2022/06/17 13:41:02 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_putnbr_fd(int n, int fd, unsigned long len)
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

// #include <stdio.h>
// int main(int ac, char **av)
// {
// 	(void)ac;
// 	int n = ft_atoi(av[1]);
// 	ft_putnbr_fd(n, 0);
// }
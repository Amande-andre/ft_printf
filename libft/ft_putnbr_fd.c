/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:44:24 by anmande           #+#    #+#             */
/*   Updated: 2022/06/13 16:01:05 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd, t_value *value)
{
	size_t	nb;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd, value);
	}	
	// if (nb <= 9)
	// 	ft_putchar_fd(nb + '0', fd, value);
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd, value);
	}
	ft_putchar_fd((nb % 10) + '0', fd, value);
}

// #include <stdio.h>
// int main(int ac, char **av)
// {
// 	(void)ac;
// 	int n = ft_atoi(av[1]);
// 	ft_putnbr_fd(n, 0);
// }
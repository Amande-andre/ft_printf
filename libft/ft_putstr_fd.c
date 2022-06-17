/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:01:26 by anmande           #+#    #+#             */
/*   Updated: 2022/06/17 13:09:31 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_putstr_fd(char *s, int fd)
{
	int	i;
	unsigned long	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		len += ft_putchar_fd(s[i], fd);
		i++;
	}
	return (len);
}

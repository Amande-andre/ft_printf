/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:40:06 by anmande           #+#    #+#             */
/*   Updated: 2022/06/21 16:45:57 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>
#include "./libft/libft.h"


int				ft_printf(const char *s, ...);
unsigned int	ft_flagx(size_t n, int fd, char *base);
unsigned int	ft_flagp(unsigned long int n, int fd, char *base);
unsigned int	ft_putnbr_u(unsigned int n, int fd, unsigned int len);

#endif

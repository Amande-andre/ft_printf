/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:40:06 by anmande           #+#    #+#             */
/*   Updated: 2022/06/17 18:44:53 by admin            ###   ########.fr       */
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
unsigned int	ft_flagx(long long unsigned int n, int fd, char *base);
unsigned int	ft_flagp(unsigned long n, int fd, char *base);

#endif

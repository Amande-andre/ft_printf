/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:40:06 by anmande           #+#    #+#             */
/*   Updated: 2022/06/24 14:42:56 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>

int				ft_printf(const char *s, ...);
unsigned int	ft_flagx(unsigned long long int n, int fd, char *base);
unsigned int	ft_flagp(unsigned long int n, int fd, char *base);
unsigned int	ft_putnbr_u(unsigned int n, int fd, unsigned int len);
unsigned int	ft_putchar_fd(char c, int fd);
unsigned int	ft_putstr_fd(char *s, int fd);
unsigned int	ft_putnbr_fd(int n, int fd, unsigned int len);
#endif

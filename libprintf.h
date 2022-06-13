/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:40:06 by anmande           #+#    #+#             */
/*   Updated: 2022/06/13 14:44:30 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

#include "../ft_printf/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>

typedef struct s_value
{
	size_t	len;
	size_t  index;
}	t_value;

int	ft_printf(const char *s, ...);
size_t	ft_flagx(int n, int fd, size_t i, char *base);

#endif

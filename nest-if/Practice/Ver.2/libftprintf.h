/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:16:31 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/22 18:56:34 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>

int	ft_printf(const char *, ...);
int	ft_vprintf(const char s, va_list ap);
int	ft_print_c(int c);
int	ft_print_s(char *s);
int	ft_print_d_i(int n);
int ft_print_u(unsigned int n);
int ft_print_x_X(unsigned int n, char c);
int ft_print_p(unsigned long n);

#endif

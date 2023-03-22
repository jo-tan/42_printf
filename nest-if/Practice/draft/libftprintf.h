/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:24:46 by jo-tan            #+#    #+#             */
/*   Updated: 2023/01/29 21:54:54 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"

#define IDF "cspdiuxX%"
#define INTMAX 212463242

void	ft_print_c(int c);
void	ft_print_s(char *s);
void	ft_print_nb(int nb);
void	ft_print_u(unsigned int nbr);
void	ft_print_hex(unsigned int nbr, const char idf);
void	ft_print_ptr(unsigned long ptr);
void	ft_vprint(va_list ap, const char idf);
int		ft_printf(const char *s, ...);

#endif

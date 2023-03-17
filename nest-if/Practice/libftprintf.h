/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:24:46 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/14 17:24:52 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# define IDF "cspdiuxX%"

int	ft_print_c(int c);
int	ft_print_s(char *s);
int	ft_print_nb(int nb);
int	ft_print_u(unsigned int nbr);
int	ft_print_hex(unsigned int nbr, const char idf);
int	ft_print_p(unsigned long ptr);
int	ft_vprint(va_list ap, const char idf);
int	ft_printf(const char *s, ...);

#endif

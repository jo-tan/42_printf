/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:04:27 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/05 22:39:37 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_format
{
    char    *specificer;
    struct  *next;
} t_format;

typedef struct s_flag_width_conversion
{
    int    left_justify;
    char    *prefix;
    char    padding;
    int     width;
    int     precision;
    char    conversion;
    char    *argument;
    size_t     len;
} t_fwc;

int ft_printf(const char *format, ...);
int ft_vprintf(const char *format, va_list ap);
t_format	*ft_initialize_format(const char *format, va_list ap);
t_fwc	*ft_initialize_output_control(void);
void    ft_set_fwc(t_format *fmt);
void    *ft_parse(t_format *fmt, t_fwc *m);
void    *ft_parse_flag(t_format *fmt, t_fwc *m);
void    *ft_parse_width(t_format *fmt, t_fwc *m);
void    *ft_parse_precision(t_format *fmt, t_fwc *m); 
void	ft_parse_conversion(t_format *fmt, t_fwc *h);
void	ft_fill_left_pad(char **src, char padding, int width);
void	ft_fill_right_pad(char **src, char padding, int width);
void	ft_add_prefix(t_fwc *h, int sign);
void	ft_type_conversion(t_format *fmt, t_fwc *h);
void	ft_convert_c(t_format *fmt, t_fwc *h);
void	ft_convert_s(t_format *fmt, t_fwc *h);
void	ft_convert_d_i(t_format *fmt, t_fwc *h);
void	ft_convert_ux(t_format *fmt, t_fwc *h, char *base);
void	ft_convert_p(t_format *fmt, t_fwc *h);
void	ft_convert_pct(t_fwc *h);

#endif

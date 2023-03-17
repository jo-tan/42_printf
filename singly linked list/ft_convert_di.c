/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:23:40 by jo-tan            #+#    #+#             */
/*   Updated: 2023/01/26 20:23:57 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_d_i(t_format *fmt, t_fwc *ctl)
{
	int			sign;
	long int	arg;

	sign = 1;
	arg = (int)va_arg(fmt->ap, int);
	if (arg < 0)
		sign *= -1;
	ctl->argument = ft_uitoa_base(sign * arg, DECIMAL_BASE);
	if (ctl->precision > -1)
	{
		if (!ctl->precision && arg == 0)
		{
			free(ctl->argument);
			ctl->argument = ft_strdup("");
		}
		ft_fill_left_pad(&ctl->argument, '0', ctl->precision);
		ctl->padding = ' ';
	}
	ft_convert_d_i_width(ctl, sign);
	ctl->len = ft_strlen(ctl->argument);
}

static void	ft_convert_d_i_width(t_fwc *ctl, int sign)
{
	if (ctl->left_justify)
	{
		ft_add_prefix(ctl, sign);
		ft_fill_right_pad(&ctl->argument, ' ', ctl->width);
	}
	else
	{
		if (ctl->padding == ' ')
		{
			ft_add_prefix(ctl, sign);
			ft_fill_left_pad(&ctl->argument, ctl->padding, ctl->width);
		}
		else if (ctl->padding == '0')
		{
			if (sign < 0 || ft_strchr(ctl->prefix, ' ') || ft_strchr(ctl->prefix, '+'))
				ft_fill_left_pad(&ctl->argument, ctl->padding, ctl->width - 1);
			else
				ft_fill_left_pad(&ctl->argument, ctl->padding, ctl->width);
			ft_add_prefix(ctl, sign);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:12:22 by jo-tan            #+#    #+#             */
/*   Updated: 2023/01/26 20:21:56 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_c(t_format *fmt, t_fwc *ctl)
{
	char	ch;

	ch = (wint_t)va_arg(fmt->ap, wint_t);
	if (!ctl->width)
		ctl->width += 1;
	ctl->argument = (char *)malloc(ctl->width * sizeof(char));
	if (!ctl->argument)
		return ;
	ft_memset(ctl->argument, ' ', ctl->width);
	if (ctl->left_justify == 1)
		ctl->argument[0] = ch;
	else
		ctl->argument[ctl->width - 1] = ch;
	ctl->len = ctl->width;
}

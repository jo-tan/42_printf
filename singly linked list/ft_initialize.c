/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:00:04 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/05 22:26:40 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_format	*ft_initialize_format(const char *format, va_list ap)
{
	t_format	*fmt;

	fmt = malloc(sizeof(t_format));
	if (!fmt)
		return (NULL);
	fmt->format = format;
	va_copy(fmt->ap, ap);
	fmt->i = 0;
	fmt->len = 0;
	return (fmt);
}

/*Designated Initialization. For value which will filled in as 0, it can be skiiped*/
t_fwc	*ft_initialize_output_control(void)
{
	t_fwc	*ctl;

	ctl = malloc(sizeof(t_fwc));
	if (!ctl)
		return (NULL);
//	ctl->left_justify = 0;
	ctl->prefix = ft_strdup("");
	ctl->padding = ' ';
//	ctl->width = 0;
	ctl->precision = -1;
	ctl->conversion = '\0';
	ctl->argument = NULL;
//	ctl->len = 0;
	return (h);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:26:00 by jo-tan            #+#    #+#             */
/*   Updated: 2023/01/26 20:26:30 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_p(t_format *fmt, t_fwc *ctl)
{
	void	*ptr;
	char	*number;

	number = NULL;
	ptr = va_arg(fmt->ap, void *);
	if (!ptr)
		number = ft_nullset(ctl);
	else
		number = ft_uitoa_base((unsigned long)ptr, HEXADECIMAL_L_BASE);
	ctl->argument = ft_strjoin(PTR_HEX_L_PREFIX, number);
	free(number);
	if (!ctl->left_justify)
		ft_fill_left_pad(&ctl->argument, ' ', ctl->width);
	else
		ft_fill_right_pad(&ctl->argument, ' ', ctl->width);
	ctl->len = ft_strlen(ctl->argument);
}

static char	*ft_nullset(t_fwc *ctl)
{
	char	*number;

	if (ctl->precision > -1)
	{
		number = (char *)malloc((ctl->precision + 1) * sizeof(char));
		if (!number)
			return (NULL);
		ft_memset(number, '0', (size_t)ctl->precision);
		number[ctl->precision] = '\0';
	}
	else
		number = ft_strdup("0");
	return (number);
}

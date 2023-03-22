/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:56:51 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/22 19:24:14 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_vprintf(const char cs, va_list ap)
{
	int	len;

	len = 0;
	if (cs == 'c')
		len += ft_print_c(va_arg(ap, int));
	else if (cs == 's')
		len += ft_print_s(va_arg(ap, char *));
	else if (cs == 'd' || cs == 'i')
		len += ft_print_d_i(va_arg(ap, int));
	else if (cs == 'u')
		len += ft_print_u(va_arg(ap, unsigned int));
	else if (cs == 'x' || cs == 'X')
		len += ft_print_x_X(va_arg(ap, unsigned int), cs);
	else if (cs == 'p')
		len += ft_print_p(va_arg(ap, unsigned long));
	else if (cs == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	len;
	va_list ap;

	i = 0;
	len = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("csdiuxXp%", s[i + 1]))
		{
			len += ft_vprintf(s[i + 1], ap);
			i++;
		}
		else
			len += write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}

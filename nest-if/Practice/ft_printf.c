/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:23:13 by jo-tan            #+#    #+#             */
/*   Updated: 2023/01/29 23:57:53 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_vprintf(va_list ap, const char idf)
{
	if (idf == 'c')
		return (ft_print_c(va_arg(ap, int)));
	else if (idf == 's')
	 	return (ft_print_s(va_arg(ap, char *)));
	else if (idf == 'p')
	 	return (ft_print_p(va_arg(ap, unsigned long)));
	else if (idf == 'd' || idf == 'i')
	 	return (ft_print_nb(va_arg(ap, int)));
	else if (idf == 'u')
	 	return (ft_print_u(va_arg(ap, unsigned int)));
	else if (idf == 'x' || idf == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), idf));
	else if (idf == '%')
	 	return (write(1, "%", 1));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list			ap;
	unsigned int	i;
	unsigned int	len;

	if (!s)
		return (1);
	i = 0;
	len = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr(IDF, (int)s[i + 1]))
		{
			len += ft_vprintf(ap, s[i + 1]);
			i++;
		}
		else
			len += write(1, s + i, 1);
		i++;
	}
	va_end(ap);
	return (len);
}

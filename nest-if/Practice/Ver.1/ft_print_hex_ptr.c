/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:20:17 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/17 02:20:20 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_hex(unsigned int nbr, const char idf)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_print_hex(nbr / 16, idf);
		len += ft_print_hex(nbr % 16, idf);
	}
	else
	{
		if (nbr < 10)
			len += ft_print_c(nbr + '0');
		else
		{
			if (idf == 'x')
				len += ft_print_c(nbr - 10 + 'a');
			else if (idf == 'X')
				len += ft_print_c(nbr - 10 + 'A');
		}
	}
	return (len);
}

static int	ft_print_ptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
	{
		len += ft_print_ptr(ptr / 16);
		len += ft_print_ptr(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			len += ft_print_c(ptr + '0');
		else
			len += ft_print_c(ptr - 10 + 'a');
	}
	return (len);
}

int	ft_print_p(unsigned long ptr)
{
	int	len;

	if (ptr == 0)
		return (ft_print_s("(nil)"));
	len = 0;
	len += write(1, "0x", 2);
	len += ft_print_ptr(ptr);

	return (len);
}

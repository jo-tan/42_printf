/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:10:37 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/22 21:03:41 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_hex(unsigned long n, char c)
{
	int	len;

	len = 0;
	if (n == 0)
		return(write(1, "0", 1));
	else if (n >= 16)
	{
		len += ft_print_hex(n / 16, c);
		len += ft_print_hex(n % 16, c);
	}
	else
	{
		if (n > 9 && c == 'x')
			len += ft_print_c(n - 10 + 'a');
		else if (n > 9 && c == 'X')
			len += ft_print_c(n - 10 + 'A');
		else
			len += ft_print_c(n + '0');
	}
	return (len);
}

int	ft_print_x_X(unsigned int n, char c)
{
	int	len;

	len = 0;
	len += ft_print_hex(n, c);	
	return(len);
}

int	ft_print_p(unsigned long n)
{
	int	len;

	if (n == 0)
		return(write(1, "(nil)", 5));
	len = 0;
	len += write(1, "0x", 2);
	len += ft_print_hex(n, 'x');
	return (len);
}
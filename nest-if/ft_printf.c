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

void	ft_print_c(int c)
{
	write(1, &c, 1);
}

int	ft_count_digit(unsigned long int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_count_digit(n / 10));
}

char	*ft_uitoa(int n)
{
	char			*res;
	int				len;
	unsigned long int	nbr;

	nbr = n;
	len = ft_count_digit(nbr);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (nbr == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	res[len] = '\0';
	while (nbr)
	{
		res[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}

void	ft_print_s(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_print_c(s[i]);
		i++;
	}
}

void	ft_print_nb(int	nb)
{
	char *output;

	output = ft_itoa(nb);
	ft_print_s(output);
}

void	ft_print_u(unsigned int	nbr)
{
	char *output;

	output = ft_uitoa(nbr);
	ft_print_s(output);
}

void	ft_print_hex(unsigned int nbr, const char idf)
{
	if (nbr >= 16)
	{
		ft_print_hex(nbr / 16, idf);
		ft_print_hex(nbr % 16, idf);
	}
	else
	{
		if (nbr < 10)
			ft_print_c(nbr + '0');
		else
		{
			if (idf == 'x')
				ft_print_c(nbr - 10 + 'a');
			else if (idf == 'X')
				ft_print_c(nbr - 10 + 'A');
		}
	}
}


void	ft_print_ptr(unsigned long ptr)
{
	if (ptr == 0)
		ft_print_c('0');
	if (ptr >= 16)
	{
		ft_print_ptr(ptr / 16);
		ft_print_ptr(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_print_c(ptr + '0');
		else
			ft_print_c(ptr - 10 + 'a');
	}
}

void	ft_print_p(unsigned long ptr)
{
	write(1, "0x", 2);
	ft_print_ptr(ptr);
}

/*end*/

void	ft_vprintf(va_list ap, const char idf)
{
	if (idf == 'c')
		ft_print_c(va_arg(ap, int));
	else if (idf == 's')
		ft_print_s(va_arg(ap,char *));
	else if (idf == 'p')
		ft_print_p(va_arg(ap, unsigned long));
	else if (idf == 'd' || idf == 'i')
		ft_print_nb(va_arg(ap, int));
	else if (idf == 'u')
		ft_print_u(va_arg(ap, unsigned int));
	else if (idf == 'x' || idf == 'X')
		ft_print_hex(va_arg(ap, unsigned int), idf);
	else if (idf == '%')
		ft_print_c('%');
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
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
			ft_vprintf(ap, s[i + 1]);
			len++;
			i++;
		}
		else
			ft_print_c(s[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

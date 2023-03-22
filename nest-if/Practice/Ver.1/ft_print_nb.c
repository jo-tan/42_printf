/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:19:22 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/22 17:44:47 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_count_digit(unsigned long int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_count_digit(n / 10));
}

char	*ft_uitoa(unsigned int n)
{
	char				*res;
	int					len;

	len = ft_count_digit(n);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	res[len] = '\0';
	while (n)
	{
		res[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}

int	ft_print_nb(int nb)
{
	char	*output;
	int		len;

	len = 0;
	output = ft_itoa(nb);
	len += ft_print_s(output);
	free(output);
	return (len);
}

int	ft_print_u(unsigned int nbr)
{
	char	*output;
	int		len;

	len = 0;
	output = ft_uitoa(nbr);
	len += ft_print_s(output);
	free(output);
	return (len);
}

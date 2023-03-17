/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:19:22 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/17 02:19:54 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_count_digit(unsigned long int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_count_digit(n / 10));
}

char	*ft_uitoa(int n)
{
	char				*res;
	int					len;
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

int	ft_print_nb(int nb)
{
	char	*output;

	output = ft_itoa(nb);
	return (ft_print_s(output));
}

int	ft_print_u(unsigned int nbr)
{
	char	*output;

	output = ft_uitoa(nbr);
	return (ft_print_s(output));
}

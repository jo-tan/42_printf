/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:00:52 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/22 21:18:48 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_d_i(int n)
{
	int		len;
	char	*output;

	len = 0;
	output = ft_itoa(n);
	len += ft_print_s(output);
	free(output);
	return (len);	
}

static int	ft_count_digit(unsigned int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_count_digit(n / 10));
}

static char	*ft_uitoa(unsigned int n)
{
	char	*res;
	int	len;

	len = ft_count_digit(n);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[--len] = '0';
	while (n)
	{
		res[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}

int	ft_print_u(unsigned int n)
{
	int		len;
	char	*output;

	len = 0;
	output = ft_uitoa(n);
	len += ft_print_s(output);
	free(output);
	return (len);
}

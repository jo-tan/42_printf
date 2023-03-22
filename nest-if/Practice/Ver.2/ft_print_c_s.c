/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:24:38 by jo-tan            #+#    #+#             */
/*   Updated: 2023/03/22 20:56:57 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_c(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_s(char *s)
{
	int	len;

	if (!s)
		return(write(1, "(null)", 6));
	len = 0;
	while(s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:12:22 by jo-tan            #+#    #+#             */
/*   Updated: 2023/01/26 20:21:56 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_c(t_format *fmt, t_holder *h)
{
	char	ch;

	ch = (wint_t)va_arg(fmt->ap, wint_t);
	if (!h->width)
		h->width += 1;
	h->argument = (char *)malloc(h->width * sizeof(char));
	if (!h->argument)
		return ;
	ft_memset(h->argument, SPACE, h->width);
	if (h->left_justify == 1)
		h->argument[0] = ch;
	else
		h->argument[h->width - 1] = ch;
	h->len = h->width;
}

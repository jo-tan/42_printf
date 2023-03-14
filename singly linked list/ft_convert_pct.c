/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:26:50 by jo-tan            #+#    #+#             */
/*   Updated: 2023/01/26 20:27:11 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_pct(t_holder *h)
{
	h->argument = ft_appendchr("", h->conversion);
	if (!h->left_justify)
		ft_fill_left_pad(&h->argument, h->padding, h->width);
	else
		ft_fill_right_pad(&h->argument, ' ', h->width);
	h->len = ft_strlen(h->argument);
}

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

void	ft_convert_pct(t_fwc *ctl)
{
	ctl->argument = ft_appendchr("", ctl->conversion);
	if (!ctl->left_justify)
		ft_fill_left_pad(&ctl->argument, ctl->padding, ctl->width);
	else
		ft_fill_right_pad(&ctl->argument, ' ', ctl->width);
	ctl->len = ft_strlen(ctl->argument);
}

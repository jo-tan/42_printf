/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:00:41 by jo-tan            #+#    #+#             */
/*   Updated: 2023/01/26 20:01:08 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_placeholder(t_format *fmt)
{
	t_fwc	*ctl;

	fmt->i++;
	ctl = ft_initialize_output_control();
	ft_parse(fmt, ctl);
	if (ctl->conversion)
	{
		ft_type_conversion(fmt, ctl);
		fmt->len += write(1, ctl->argument, ctl->len);
		free(ctl->argument);
	}
	free(ctl->prefix);
	free(ctl);
}

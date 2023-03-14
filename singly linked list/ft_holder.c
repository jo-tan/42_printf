/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_holder.c                                        :+:      :+:    :+:   */
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
	t_holder	*h;

	fmt->i++;
	h = ft_initialize_holder();
	ft_parse(fmt, h);
	if (h->conversion)
	{
		ft_type_conversion(fmt, h);
		fmt->len += write(1, h->argument, h->len);
		free(h->argument);
	}
	free(h->prefix);
	free(h);
}

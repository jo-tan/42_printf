/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:22:09 by jo-tan            #+#    #+#             */
/*   Updated: 2023/01/26 20:22:53 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_s(t_format *fmt, t_holder *h)
{
	char	*s;
	int		len;
	char	*temp;

	s = ft_strdup(va_arg(fmt->ap, char *));
	if (!s)
		s = ft_strdup("(null)");
	len = (int)ft_strlen(s);
	h->argument = (char *)malloc((len + 1) * sizeof(char));
	if (!h->argument)
		return ;
	ft_strlcpy(h->argument, s, len + 1);
	if (h->precision > -1)
	{
		temp = h->argument;
		h->argument = ft_strndup(temp, (size_t)h->precision);
		free(temp);
	}
	if (!h->left_justify)
		ft_fill_left_pad(&h->argument, ' ', h->width);
	else
		ft_fill_right_pad(&h->argument, ' ', h->width);
	h->len = ft_strlen(h->argument);
	free(s);
}

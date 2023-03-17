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

void	ft_convert_s(t_format *fmt, t_fwc *ctl)
{
	char	*s;
	int		len;
	char	*temp;

	s = ft_strdup(va_arg(fmt->ap, char *));
	if (!s)
		s = ft_strdup("(null)");
	len = (int)ft_strlen(s);
	ctl->argument = (char *)malloc((len + 1) * sizeof(char));
	if (!ctl->argument)
		return ;
	ft_strlcpy(ctl->argument, s, len + 1);
	if (ctl->precision > -1)
	{
		temp = ctl->argument;
		ctl->argument = ft_strndup(temp, (size_t)ctl->precision);
		free(temp);
	}
	if (!ctl->left_justify)
		ft_fill_left_pad(&ctl->argument, ' ', ctl->width);
	else
		ft_fill_right_pad(&ctl->argument, ' ', ctl->width);
	ctl->len = ft_strlen(ctl->argument);
	free(s);
}

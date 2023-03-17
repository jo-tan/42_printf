/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:24:21 by jo-tan            #+#    #+#             */
/*   Updated: 2023/01/26 20:25:17 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_convert_ux(t_format *fmt, t_fwc *ctl, char *base)
{
	unsigned int	nbr;
	char			*number;

	number = NULL;
	nbr = (unsigned int)(va_arg(fmt->ap, unsigned int));
	number = ft_uitoa_base((unsigned long)nbr, base);
	ctl->argument = ft_strdup(number);
	free(number);
	if (ctl->precision > -1)
	{
		if (!ctl->precision && nbr == 0)
		{
			free(ctl->argument);
			ctl->argument = ft_strdup("");
		}
		ft_fill_left_pad(&ctl->argument, '0', ctl->precision);
		ctl->padding = ' ';
	}
	if (nbr)
		ft_add_prefix(ctl, 0);
	if (!ctl->left_justify)
		ft_fill_left_pad(&ctl->argument, ctl->padding, ctl->width);
	else
		ft_fill_right_pad(&ctl->argument, ' ', ctl->width);
	ctl->len = ft_strlen(ctl->argument);
}

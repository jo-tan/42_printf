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

void	ft_convert_ux(t_format *fmt, t_holder *h, char *base)
{
	unsigned int	nbr;
	char			*number;

	number = NULL;
	nbr = (unsigned int)(va_arg(fmt->ap, unsigned int));
	number = ft_uitoa_base((unsigned long)nbr, base);
	h->argument = ft_strdup(number);
	free(number);
	if (h->precision > -1)
	{
		if (!h->precision && nbr == 0)
		{
			free(h->argument);
			h->argument = ft_strdup("");
		}
		ft_fill_left_pad(&h->argument, '0', h->precision);
		h->padding = ' ';
	}
	if (nbr)
		ft_add_prefix(h, 0);
	if (!h->left_justify)
		ft_fill_left_pad(&h->argument, h->padding, h->width);
	else
		ft_fill_right_pad(&h->argument, ' ', h->width);
	h->len = ft_strlen(h->argument);
}

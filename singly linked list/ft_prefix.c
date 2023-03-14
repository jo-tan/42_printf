/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:06:59 by jo-tan            #+#    #+#             */
/*   Updated: 2023/01/26 20:08:18 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_fill_left_pad(char **src, char padding, int width)
{
	char	*temp;
	size_t	strlen;
	size_t	padlen;

	strlen = ft_strlen(*src);
	if (!width || width < (int)strlen)
		width = strlen;
	temp = (char *)malloc(width * sizeof(char));
	if (!temp)
		return ;
	padlen = width - strlen;
	ft_memset(temp, padding, padlen);
	temp[padlen] = '\0';
	ft_strlcat(temp, *src, width + 1);
	free(*src);
	*src = temp;
}

void	ft_fill_right_pad(char **src, char padding, int width)
{
	char	*temp;
	size_t	strlen;
	size_t	padlen;

	strlen = ft_strlen(*src);
	if (!width || width < (int)strlen)
		width = strlen;
	temp = (char *)malloc(width * sizeof(char));
	if (!temp)
		return ;
	ft_strlcpy(temp, *src, strlen + 1);
	padlen = width - strlen;
	ft_memset(&temp[strlen], padding, padlen);
	temp[width] = '\0';
	free(*src);
	*src = temp;
}

void	ft_add_prefix(t_holder	*h, int sign)
{
	int	len;

	len = (int)ft_strlen(h->argument);
	if (h->conversion == 'd' || h->conversion == 'i')
	{
		len += 1;
		if (ft_strchr(h->prefix, PLUS) && sign == 1)
			ft_fill_left_pad(&h->argument, PLUS, len);
		else if (ft_strchr(h->prefix, SPACE) && sign == 1)
			ft_fill_left_pad(&h->argument, SPACE, len);
		else if (sign == -1)
			ft_fill_left_pad(&h->argument, MINUS, len);
	}
	else if (h->conversion == 'x' || h->conversion == 'X' \
			|| h->conversion == 'o')
		ft_prefix_ux(h);
}

static void	ft_prefix_ux(t_holder *h)
{
	char	*temp;

	temp = h->argument;
	if (ft_strchr(h->prefix, '#'))
	{
		if (h->conversion == 'x')
			h->argument = ft_strjoin(PTR_HEX_L_PREFIX, temp);
		if (h->conversion == 'X')
			h->argument = ft_strjoin(HEX_U_PREFIX, temp);
		if (h->conversion == 'o')
			h->argument = ft_strjoin(OCT_PREFIX, temp);
		free(temp);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemiroz <sdemiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:51:34 by sdemiroz          #+#    #+#             */
/*   Updated: 2024/04/01 06:08:09 by sdemiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nto_str(unsigned long nbr)
{
	char	*xbase;
	int		x;

	xbase = "0123456789abcdef";
	if (nbr >= 16)
	{
		nto_str(nbr / 16);
		nto_str(nbr % 16);
	}
	else
	{
		x = fti_putchar(xbase[nbr]);
		if (x < 0)
			return (-1);
	}
	return (0);
}

int	ft_px(unsigned long nbr)
{
	int			cc;
	int			x;

	cc = fti_putstr("0x");
	if (cc != 2)
		return (-1);
	cc += 1;
	if (nbr < 0)
	{
		x = fti_putchar('-');
		if (x < 0)
			return (-1);
		cc += 1;
		nbr = -nbr;
	}
	x = nto_str(nbr);
	if (x < 0)
		return (-1);
	while (nbr >= 16)
	{
		nbr /= 16;
		cc++;
	}
	return (cc);
}

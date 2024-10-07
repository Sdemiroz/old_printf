/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemiroz <sdemiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:34:55 by sdemiroz          #+#    #+#             */
/*   Updated: 2024/04/03 05:02:06 by sdemiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nto_str(unsigned int nbr)
{
	char	*xbase;
	int		x;

	xbase = "0123456789abcdef";
	if (nbr >= 16)
	{
		if (nto_str(nbr / 16) < 0)
			return (-1);
		if (nto_str(nbr % 16) < 0)
			return (-1);
	}
	else
	{
		x = fti_putchar(xbase[nbr]);
		if (x < 0)
			return (-1);
	}
	return (0);
}

int	ft_sx(unsigned int nbr)
{
	int			cc;
	int			x;

	cc = 1;
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

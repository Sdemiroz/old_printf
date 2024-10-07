/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemiroz <sdemiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:01:51 by sdemiroz          #+#    #+#             */
/*   Updated: 2024/04/03 05:02:34 by sdemiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nto_str(unsigned int nbr)
{
	char	*xbase;
	int		x;

	xbase = "0123456789";
	if (nbr >= 10)
	{
		if (nto_str(nbr / 10) < 0)
			return (-1);
		if (nto_str(nbr % 10) < 0)
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

int	ft_ux(unsigned int nbr)
{
	int		cc;
	int		x;

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
	while (nbr >= 10)
	{
		nbr /= 10;
		cc++;
	}
	return (cc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fti_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemiroz <sdemiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 02:08:42 by sdemiroz          #+#    #+#             */
/*   Updated: 2024/04/01 03:35:22 by sdemiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fti_putstr(char *x)
{
	int	i;
	int	y;

	i = 0;
	if (!x)
	{
		y = write (1, "(null)", 6);
		if (y != 6)
			return (-1);
		return (y);
	}
	while (x[i])
	{
		y = write(1, &x[i], 1);
		if (y != 1)
			return (-1);
		i++;
	}
	return (i);
}

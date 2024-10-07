/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemiroz <sdemiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:16:42 by sdemiroz          #+#    #+#             */
/*   Updated: 2024/04/01 04:36:02 by sdemiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int			ft_strlen(const char *s);
int			ft_printf(const char *format, ...);
int			fti_putchar(char x);
int			fti_putstr(char *str);
char		*ft_itoa(int x);
int			ft_sx(unsigned int nbr);
int			ft_bx(unsigned int nbr);
int			ft_ux(unsigned int nbr);
int			ft_px(unsigned long nbr);

#endif
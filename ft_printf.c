/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemiroz <sdemiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:16:45 by sdemiroz          #+#    #+#             */
/*   Updated: 2024/04/03 04:20:13 by sdemiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent_base(va_list arg, char x, int cc)
{
	if (x == 'p')
	{
		cc = ft_px(va_arg(arg, unsigned long));
	}
	else if (x == 'u')
	{
		cc = ft_ux(va_arg(arg, unsigned int));
	}
	else if (x == 'x')
	{
		cc = ft_sx(va_arg(arg, unsigned int));
	}
	else if (x == 'X')
	{
		cc = ft_bx(va_arg(arg, unsigned int));
	}
	else if (x == '%')
		cc = fti_putchar('%');
	return (cc);
}

int	ft_percent(va_list arg, char x)
{
	int		cc;
	char	*str;

	cc = 0;
	if (x == 'p' || x == 'u' || x == 'x' || x == 'X' || x == '%')
	{
		cc = ft_percent_base(arg, x, cc);
	}
	else if (x == 'c')
		cc = fti_putchar((char)va_arg(arg, int));
	else if (x == 's')
		cc = fti_putstr(va_arg(arg, char *));
	else if (x == 'i' || x == 'd')
	{
		str = ft_itoa(va_arg(arg, int));
		if (!str)
			return (-1);
		cc = fti_putstr(str);
		free(str);
	}
	if (cc < 0)
		return (-1);
	else
		return (cc);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			cc;
	size_t		x;
	int			temp;

	va_start(arg, format);
	cc = 0;
	x = 0;
	while (format[x])
	{
		if (format[x] == '%')
		{
			temp = ft_percent(arg, format[++x]);
			x++;
		}
		else
		{
			temp = fti_putchar(format[x++]);
		}
		if (temp < 0)
			return (va_end(arg), -1);
		cc += temp;
	}
	return (va_end(arg), cc);
}

// int	main(void)
// {
// 	// char	*y;

// 	// y = "abc";

// 	// int p = 0;

// 	// p = ft_printf("%u", -200000);

// 	printf("%d", printf("%u", -200000));

// 	// printf("_____________________________\n");
// 	// ft_printf("%s\n\n", "My printf:");
// 	// ft_printf("%d \n", 5312);
// 	// ft_printf("%% \n");
// 	// ft_printf("%p \n", y);
// 	// ft_printf("%u \n", -10);
// 	// ft_printf("%u \n", INT_MAX);
// 	// printf("_____________________________\n");
// 	// printf("%s\n\n", "Original printf:");
// 	// printf("%d \n", 5312);
// 	// printf("%% \n");
// 	// printf("%p \n", y);
// 	// printf("%u \n", -10);
// 	// printf("%u \n", INT_MAX);
// 	return (0);
// }

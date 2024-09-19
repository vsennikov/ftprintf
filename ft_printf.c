/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:58:57 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/19 12:52:41 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	write_char(int c)
{
	return (write(1, &c, 1));
}

int	write_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write_char((int)str[i]);
		i++;
	}
	return (i);
}

int	choose_func(char c, va_list ap)
{
	int	j;

	j = 0;
	if (c == 'c')
		j += write_char(va_arg(ap, int));
	else if (c == 's')
		j += write_str(va_arg(ap, char *));
	else if (c == '%')
		j += write_char('%');
	else if (c == 'd' || c == 'i')
		j += ft_putnbr_decimal(va_arg(ap, int), "0123456789");
	else if ( c == 'u')
		j += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'x')
		j += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		j += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		j += ft_putnbr_add(va_arg(ap, void *), "0123456789abcdef");
	return (j);
}


int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		j;

	va_start(ap, str);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			j += choose_func(str[++i], ap);
		else
			j += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (j);
}

#include <limits.h>

int    main(void)
{

	// void *s1 = 0;
	// void *s2 = 0;
	char *str = NULL;
	int ft_res = ft_printf("%s \n", NULL);
	int p_res = printf("%s \n", NULL);
	printf("ft_res = %d, p_res = %d", ft_res, p_res);
}


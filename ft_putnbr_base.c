/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:54:50 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/18 16:01:15 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_symbols(unsigned long nbr, char *base, unsigned long size)
{
	char	ch;
	int		counter;

	counter = 0;
	if (nbr >= size)
		counter += print_symbols(nbr / size, base, size);
	ch = base[nbr % size];
	counter += write(1, &ch, 1);
	return (counter);
}

int	ft_putnbr_base(long nbr, char *base)
{
	unsigned long	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (print_symbols((unsigned long) nbr, base, i));
}

int	ft_putnbr_decimal(int nbr, char *base)
{
	int	counter;
	long	lnbr;

	counter = 0;
	lnbr = nbr;
	if (lnbr < 0)
	{
		counter += write(1, "-", 1);
		lnbr *= -1;
	}
	counter += ft_putnbr_base(lnbr, base);
	return (counter);
}

int	ft_putnbr_add(void *add, char *base)
{
	int	counter;

	counter = 0;
	counter += write_str("0x");
	counter += ft_putnbr_base((unsigned long) add, base);
	return (counter);
}
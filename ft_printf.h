/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:59:28 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/19 20:29:54 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	write_str(char *str);
int	ft_putnbr_decimal(int nbr, char *base);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putnbr_add(unsigned long add, char *base);
#endif

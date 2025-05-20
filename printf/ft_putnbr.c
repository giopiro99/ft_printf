/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:41:12 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:28:17 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Prints an integer number to the standard output.
 *
 * Handles negative numbers by printing the minus sign,
 * and recursively prints each digit of the number.
 * Special case for the minimum 32-bit integer (-2147483648).
 *
 * @param n The integer to print.
 * @return int The total number of characters printed.
 */
int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		i = 1;
	}
	if (n <= 2147483647)
	{
		if (n >= 10)
		{
			i += ft_putnbr(n / 10);
		}
		n = (n % 10) + 48;
		i += write(1, &n, 1);
	}
	return (i);
}

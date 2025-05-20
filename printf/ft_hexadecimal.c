/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:13:55 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:26:24 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Prints an unsigned int as a hexadecimal number.
 *
 * Converts the unsigned integer `n` to its hexadecimal representation and prints it.
 * The case of the letters depends on the character `c`:
 * - 'x' prints lowercase letters (a-f).
 * - 'X' prints uppercase letters (A-F).
 *
 * @param n The unsigned integer to print.
 * @param c The format specifier ('x' for lowercase, 'X' for uppercase).
 * @return int The total number of characters printed.
 */
int	ft_hexadecimal(unsigned int n, const char c)
{
	int		count;
	int		rest;
	char	*upper;
	char	*lower;

	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	count = 0;
	if (c == 'x')
	{
		if (n > 15)
			count += ft_hexadecimal(n / 16, c);
		rest = (n % 16);
		count += write(1, &lower[rest], 1);
	}
	else if (c == 'X')
	{
		if (n > 15)
			count += ft_hexadecimal(n / 16, c);
		rest = (n % 16);
		count += write(1, &upper[rest], 1);
	}
	return (count);
}

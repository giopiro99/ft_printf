/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:57:20 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:29:02 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Prints an unsigned integer to the standard output.
 *
 * Recursively prints each digit of the unsigned integer.
 *
 * @param n The unsigned integer to print.
 * @return int The total number of characters printed.
 */
int	ft_unsigned_putnbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr(n / 10);
	n = (n % 10) + 48;
	count += write(1, &n, 1);
	return (count);
}

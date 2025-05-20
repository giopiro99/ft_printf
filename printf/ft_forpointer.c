/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:03:17 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:26:06 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Recursively prints an unsigned long long as a lowercase hexadecimal string.
 *
 * Recursively divides the input number by 16 and prints the corresponding hex digit
 * for the remainder. Uses digits 0-9 and letters a-f.
 *
 * @param pointer The unsigned long long number to print in hexadecimal.
 * @return int The total number of characters printed.
 */
static int	ft_ricorsive_pointer(unsigned long long pointer)
{
	int		count;
	int		rest;
	char	*base;

	count = 0;
	rest = 0;
	base = "0123456789abcdef";
	if (pointer > 15)
		count += ft_ricorsive_pointer(pointer / 16);
	rest = (pointer % 16);
	count += write(1, &base[rest], 1);
	return (count);
}

/**
 * @brief Prints a pointer address in hexadecimal format with "0x" prefix.
 *
 * If the pointer is NULL, prints "(nil)". Otherwise, prints the pointer value
 * as a lowercase hexadecimal number prefixed with "0x".
 *
 * @param pointer The pointer to print.
 * @return int The number of characters printed.
 */
int	ft_forpointer(void *pointer)
{
	int					count;
	unsigned long long	ptr;

	ptr = (unsigned long long)pointer;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 2;
	write(1, "0x", 2);
	count += ft_ricorsive_pointer(ptr);
	return (count);
}

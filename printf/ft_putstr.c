/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:10:34 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:28:39 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Prints a string to the standard output.
 *
 * If the input string is NULL, prints "(null)" instead.
 * Otherwise, writes each character of the string until the null terminator.
 *
 * @param s The string to print.
 * @return int The total number of characters printed.
 */
int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

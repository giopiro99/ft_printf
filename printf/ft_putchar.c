/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:09:23 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:27:25 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 @brief Writes a single character to the standard output.
 Uses the write system call to output the character c to file descriptor 1 (stdout).
 @param c The character to write.
 @return int Returns 1, representing the number of characters written.
*/
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

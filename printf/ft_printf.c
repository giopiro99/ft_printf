/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:19:57 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:26:57 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Handles a single format specifier and prints the corresponding argument.
 *
 * Given a format specifier character pointed by `format`, retrieves the
 * corresponding argument from `args` and prints it using the appropriate helper function.
 *
 * Supported format specifiers:
 *  - %% : prints a literal '%'
 *  - c  : prints a single character
 *  - p  : prints a pointer address in hexadecimal
 *  - s  : prints a string
 *  - d/i: prints a signed decimal integer
 *  - u  : prints an unsigned decimal integer
 *  - x/X: prints an unsigned integer in hexadecimal (lowercase/uppercase)
 *
 * @param format Pointer to the format specifier character.
 * @param args   The va_list holding the variable arguments.
 * @return int   The number of characters printed.
 */
static int	check_format(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == '%')
		i += ft_putchar('%');
	else if (*format == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (*format == 'p')
		i += ft_forpointer(va_arg(args, void *));
	else if (*format == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		i += ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X')
		i += ft_hexadecimal(va_arg(args, unsigned int), *format);
	return (i);
}

/**
 * @brief A simplified printf implementation.
 *
 * Parses the format string and prints characters or formatted arguments
 * according to the format specifiers. Supports basic specifiers: %c, %s, %p,
 * %d, %i, %u, %x, %X, and %%.
 *
 * @param format The format string.
 * @param ...    Variable arguments corresponding to the format specifiers.
 * @return int   The total number of characters printed.
 */
int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (count);
			count += check_format(format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}

/* int	main()
{
	("%c", 'c');
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 23:45:18 by anonymous     #+#    #+#                 */
/*   Updated: 2022/11/08 17:25:54 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_char(char to_check, char *str_check)
{
	while (*str_check)
	{
		if (to_check == *str_check++)
			return (1);
	}
	return (0);
}

int	check_str(const char *str)
{
	while (*str)
	{
		if (*str++ == '%')
		{
			if (! check_char(*str, "csd%iupxX"))
				return (0);
			if (*str == '%')
				str++;
		}
	}
	return (1);
}

size_t	print_ph(va_list *ptr, char to_find)
{
	size_t	chars_written;

	chars_written = 0;
	if (to_find == 'c')
		chars_written += ft_putchar(va_arg(*ptr, int));
	else if (to_find == '%')
		chars_written += ft_putchar('%');
	else if (to_find == 's')
		chars_written += print_str(va_arg(*ptr, char *));
	else if (to_find == 'p')
		chars_written += print_ptr(va_arg(*ptr, size_t));
	else if (to_find == 'd' || to_find == 'i')
		chars_written += print_int(va_arg(*ptr, int));
	else if (to_find == 'u')
		chars_written += print_uint(va_arg(*ptr, unsigned int));
	else if (to_find == 'x')
		chars_written += print_hex(va_arg(*ptr, unsigned int), 0);
	else if (to_find == 'X')
		chars_written += print_hex(va_arg(*ptr, unsigned int), 1);
	return (chars_written);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	size_t	cnt;

	cnt = 0;
	if (! check_str(str))
		return (-1);
	va_start(ptr, str);
	while (*str)
	{
		if (*str++ == '%')
			cnt += print_ph(&ptr, *str++);
		else
			cnt += ft_putchar(*(str - 1));
	}
	va_end(ptr);
	return (cnt);
}

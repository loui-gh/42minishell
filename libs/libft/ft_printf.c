/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:55:15 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:15:24 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_putstr(char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	else
		ft_putstr_fd("(null)", 1);
}

int	ft_len_printf(const char *format, va_list args, int len)
{
	len = ft_strlen(format) - ft_count_args_printf(format) * 2;
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspdiuxX%", *(format + 1)))
		{
			format++;
			if (*format == 'c')
				va_arg(args, int);
			else if (*format == 's')
				len += ft_printf_strlen(va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
				len += ft_nbrlen_base_sign(va_arg(args, int), 1, 10);
			else if (*format == 'u')
				len += ft_nbrlen_base_sign(va_arg(args, unsigned int), 0, 10);
			else if (*format == 'p')
				len += ft_hexlen((unsigned long)va_arg(args, void *));
			else if (*format == 'x' || *format == 'X')
				len += ft_nbrlen_base_sign(va_arg(args, unsigned int), 0, 16);
			if (*format == '%' || *format == 'c')
				len++;
		}
		format++;
	}
	return (len);
}

void	ft_check_printf(const char *format, int i, va_list args)
{
	if (format[i + 1] == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (format[i + 1] == 's')
		ft_printf_putstr(va_arg(args, char *));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (format[i + 1] == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_ulong_fd_base((unsigned long)va_arg(args, void *), 1, 16, 0);
	}
	else if (format[i + 1] == 'u')
		ft_putnbr_ulong_fd_base(va_arg(args, unsigned int), 1, 10, 0);
	else if (format[i + 1] == 'x')
		ft_putnbr_ulong_fd_base(va_arg(args, unsigned int), 1, 16, 0);
	else if (format[i + 1] == 'X')
		ft_putnbr_ulong_fd_base(va_arg(args, unsigned int), 1, 16, 1);
	else if (format[i + 1] == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		format_len;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	len = ft_len_printf(format, args, len);
	va_end(args);
	format_len = ft_strlen(format);
	va_start(args, format);
	while (i < format_len)
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			ft_check_printf(format, i, args);
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

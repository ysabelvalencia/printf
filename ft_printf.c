/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavalen <ysavalen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:23:39 by ysavalen          #+#    #+#             */
/*   Updated: 2024/12/10 20:06:55 by ysavalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_format(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}


int	main() {
	int entero = 34;
	int decimal = -96;
	unsigned int sin_signo = 1456;
	int hexadecimal = 254;

	char c = 'A';
	printf("Prueba %%c:\n");
	int count_ft_c = ft_printf("ft_printf: %c\n", c);
	int count_printf_c = printf("printf   : %c\n", c);
	printf("Conteo ft_printf: %d,Conteo printf: %d\n\n", count_ft_c, count_printf_c);

	char *str = "Este es el proyecto printf";
	printf("Prueba %%s:\n");
	int count_ft_s = ft_printf("ft_printf: %s\n", str);
	int count_printf_s = printf("printf   : %s\n", str);
	printf("Conteo ft_printf: %d, Conteo printf: %d\n\n", count_ft_s, count_printf_s);
	
	void *ptr = (void *)4560;
	printf("Prueba %%p:\n");
	int count_ft_p = ft_printf("ft_printf: %p\n", ptr);
	int count_printf_p = printf("printf   : %p\n", ptr);
	printf("Conteo ft_printf: %d, Conteo printf: %d\n\n", count_ft_p, count_printf_p);

	int d = -12345;
	printf("Prueba %%d:\n");
	int count_ft_d = ft_printf("ft_printf: %d\n", d);
	int count_printf_d = printf("printf   : %d\n", d);
	printf("Conteo ft_printf: %d, Conteo printf: %d\n\n", count_ft_d, count_printf_d);
	
	int i = INT_MIN;
	printf("Prueba %%i:\n");
	int count_ft_i = ft_printf("ft_printf: %i\n", i);
	int count_printf_i = printf("printf   : %i\n", i);
	printf("Conteo ft_printf: %d, Conteo printf: %d\n\n", count_ft_i, count_printf_i);
	
	unsigned int u = INT_MIN;
	printf("Prueba %%u:\n");
	int count_ft_u = ft_printf("ft_printf: %u\n", u);
	int count_printf_u = printf("printf   : %u\n", u);
	printf("Conteo ft_printf: %d, Conteo printf: %d\n\n", count_ft_u, count_printf_u);
	
	unsigned int x = 254;
	printf("Prueba %%x:\n");
	int count_ft_x = ft_printf("ft_printf: %x\n", x);
	int count_printf_x = printf("printf   : %x\n", x);
	printf("Conteo ft_printf: %d, Conteo printf: %d\n\n", count_ft_x, count_printf_x);
	
	unsigned int X = 254;
	printf("Prueba %%X:\n");
	int count_ft_X = ft_printf("ft_printf: %X\n", X);
	int count_printf_X = printf("printf   : %X\n", X);
	printf("Conteo ft_printf: %d, Conteo printf: %d\n\n", count_ft_X, count_printf_X);

	
	printf("Prueba %%%%:\n");
	int count_ft_percent = ft_printf("ft_printf: %%\n");
	int count_printf_percent = printf("printf   : %%\n");
	printf("Conteo ft_printf: %d, Conteo printf: %d\n\n", count_ft_percent, count_printf_percent);

	printf ()

}


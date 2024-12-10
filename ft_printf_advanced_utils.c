/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_advanced_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavalen <ysavalen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:53:02 by ysavalen          #+#    #+#             */
/*   Updated: 2024/12/10 19:46:00 by ysavalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_puthex(unsigned int n, char format)
{
	char	*hex;
	int		count;

	count = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_putnbr_hex(unsigned long long n, char format)
{
	char	*hex;
	int		count;

	count = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, format);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	addr;
	int					count;

	count = 0;
	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	addr = (unsigned long long)ptr;
	count += ft_putstr("0x");
	if (addr == 0)
		count += ft_putchar('0');
	else
		count += ft_putnbr_hex(addr, 'x');
	return (count);
}

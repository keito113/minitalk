/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:17:51 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/14 16:40:05 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hex_low(va_list *ap)
{
	unsigned int	hex;
	size_t			len;
	size_t			count;
	const char		*base;
	char			buf[sizeof(unsigned int) * 2];

	base = "0123456789abcdef";
	hex = va_arg(*ap, unsigned int);
	if (hex == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	len = 0;
	while (hex != 0)
	{
		buf[len++] = base[hex % 16];
		hex /= 16;
	}
	count = len;
	while (len != 0)
		ft_putchar_fd(buf[--len], 1);
	return ((int)count);
}

int	handle_hex_up(va_list *ap)
{
	unsigned int	hex;
	size_t			len;
	size_t			count;
	const char		*base;
	char			buf[sizeof(unsigned int) * 2];

	base = "0123456789ABCDEF";
	hex = va_arg(*ap, unsigned int);
	if (hex == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	len = 0;
	while (hex != 0)
	{
		buf[len++] = base[hex % 16];
		hex /= 16;
	}
	count = len;
	while (len != 0)
		ft_putchar_fd(buf[--len], 1);
	return ((int)count);
}

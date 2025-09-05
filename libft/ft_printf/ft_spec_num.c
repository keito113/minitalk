/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:26:03 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/14 17:19:17 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	print_num_count(unsigned int n)
{
	ssize_t	i;
	char	c;

	i = 0;
	if (n > 9)
		i += print_num_count(n / 10);
	c = n % 10 + '0';
	i += write(1, &c, 1);
	return (i);
}

int	handle_d_i(va_list *ap)
{
	int		num;
	ssize_t	len;

	len = 0;
	num = va_arg(*ap, int);
	if (num == INT_MIN)
		return ((int)write(1, "-2147483648", 11));
	if (num < 0)
	{
		len += write(1, "-", 1);
		num *= -1;
	}
	len += print_num_count(num);
	return ((int)len);
}

int	handle_u(va_list *ap)
{
	unsigned int	num;
	ssize_t			len;

	num = va_arg(*ap, unsigned int);
	len = 0;
	if (num == 0)
		return ((int)write(1, "0", 1));
	len += print_num_count(num);
	return ((int)len);
}

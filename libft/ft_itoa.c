/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:07:24 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 14:05:59 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(int nb)
{
	size_t	len;

	if (nb <= 0)
		len = 1;
	else
		len = 0;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	num;
	char	*str;

	len = num_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	num = n;
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	else if (num == 0)
		str[0] = '0';
	while (num)
	{
		--len;
		str[len] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}

// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	nb;

// 	nb = 0;
// 	printf("test1  (0)             = %s\n", ft_itoa(nb));
// 	nb = 1;
// 	printf("test2  (1)             = %s\n", ft_itoa(nb));
// 	nb = 9;
// 	printf("test3  (9)             = %s\n", ft_itoa(nb));
// 	nb = -1;
// 	printf("test4  (-1)            = %s\n", ft_itoa(nb));
// 	nb = -9;
// 	printf("test5  (-9)            = %s\n", ft_itoa(nb));
// 	nb = 10;
// 	printf("test6  (10)            = %s\n", ft_itoa(nb));
// 	nb = 99;
// 	printf("test7  (99)            = %s\n", ft_itoa(nb));
// 	nb = -10;
// 	printf("test8  (-10)           = %s\n", ft_itoa(nb));
// 	nb = -99;
// 	printf("test9  (-99)           = %s\n", ft_itoa(nb));
// 	nb = 12345;
// 	printf("test10 (12345)         = %s\n", ft_itoa(nb));
// 	nb = 678901;
// 	printf("test11 (678901)        = %s\n", ft_itoa(nb));
// 	nb = -12345;
// 	printf("test12 (-12345)        = %s\n", ft_itoa(nb));
// 	nb = -678901;
// 	printf("test13 (-678901)       = %s\n", ft_itoa(nb));
// 	nb = INT_MAX;
// 	printf("test14 (INT_MAX)       = %s\n", ft_itoa(nb));
// 	nb = INT_MIN;
// 	printf("test15 (INT_MIN)       = %s\n", ft_itoa(nb));
// 	nb = INT_MAX - 1;
// 	printf("test16 (2147483646)    = %s\n", ft_itoa(nb));
// 	nb = INT_MIN + 1;
// 	printf("test17 (-2147483647)   = %s\n", ft_itoa(nb));
// 	return (0);
// }

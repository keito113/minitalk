/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:03:44 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 14:34:57 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while ('0' <= *nptr && *nptr <= '9')
	{
		i = i * 10 + (*nptr - '0');
		nptr++;
	}
	return (i * sign);
}

// #include <stdio.h>

// int	main(int ac, char *av[])
// {
// 	if (ac != 2)
// 	{
// 		printf("\n");
// 		return (0);
// 	}
// 	printf("ft_atoi = %d\n", ft_atoi(av[1]));
// 	printf("atoi = %d\n", atoi(av[1]));
// 	return (0);
// }

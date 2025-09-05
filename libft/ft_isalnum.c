/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:45:10 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 15:02:29 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	c;
// 	int	status;

// 	status = 0;
// 	for (c = 'A'; c <= 'Z'; c++)
// 	{
// 		if (ft_isalnum(c) == ft_isalnum((unsigned char)c))
// 			printf("%c:OK\n", c);
// 		else
// 		{
// 			printf("%c:KO\n", c);
// 			status = 1;
// 		}
// 	}
// 	for (c = 'a'; c <= 'z'; c++)
// 	{
// 		if (ft_isalnum(c) == ft_isalnum((unsigned char)c))
// 			printf("%c:OK\n", c);
// 		else
// 		{
// 			printf("%c:KO\n", c);
// 			status = 1;
// 		}
// 	}
// 	for (c = '0'; c <= '9'; c++)
// 	{
// 		if (ft_isalnum(c) == ft_isalnum((unsigned char)c))
// 			printf("%c:OK\n", c);
// 		else
// 		{
// 			printf("%c:KO\n", c);
// 			status = 1;
// 		}
// 	}
// 	return (status);
// }

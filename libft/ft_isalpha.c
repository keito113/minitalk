/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:50:59 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/02 10:20:44 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
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
// 		if (ft_isalpha(c) == ft_isalpha((unsigned char)c))
// 			printf("%c:OK\n", c);
// 		else
// 		{
// 			printf("%c:KO\n", c);
// 			status = 1;
// 		}
// 	}
// 	for (c = 'a'; c <= 'z'; c++)
// 	{
// 		if (ft_isalpha(c) == ft_isalpha((unsigned char)c))
// 			printf("%c:OK\n", c);
// 		else
// 		{
// 			printf("%c:KO\n", c);
// 			status = 1;
// 		}
// 	}
// 	return (status);
// }

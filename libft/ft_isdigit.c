/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:18:03 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/02 10:21:19 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	c;
// 	int	status;

// 	status = 0;
// 	for (c = '0'; c <= '9'; c++)
// 	{
// 		if (ft_isdigit(c) == ft_isdigit((unsigned char)c))
// 			printf("%c:OK\n", c);
// 		else
// 		{
// 			printf("%c:KO\n", c);
// 			status = 1;
// 		}
// 	}
// 	return (status);
// }

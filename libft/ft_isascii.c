/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:09:15 by keitabe           #+#    #+#             */
/*   Updated: 2025/04/30 12:12:08 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	c;
// 	int	status;

// 	status = 0;
// 	for (c = 0; c <= 127; c++)
// 	{
// 		if (ft_isascii(c) == ft_isascii((unsigned char)c))
// 			printf("%c:OK\n", c);
// 		else
// 		{
// 			printf("%c:KO\n", c);
// 			status = 1;
// 		}
// 	}
// 	return (status);
// }

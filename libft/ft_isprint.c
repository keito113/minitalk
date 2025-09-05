/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:00:02 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/02 11:34:06 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	i;

// 	i = -10;
// 	while (i <= 300)
// 	{
// 		printf("ft_isprint(%d) = %d\n", i, ft_isprint(i));
// 		i++;
// 	}
// 	return (0);
// }

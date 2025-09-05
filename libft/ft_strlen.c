/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:12:53 by keitabe           #+#    #+#             */
/*   Updated: 2025/04/25 17:17:24 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	int		len;

// 	str = "hello";
// 	len = ft_strlen(str);
// 	printf("len = %d\n", len);
// 	return (0);
// }

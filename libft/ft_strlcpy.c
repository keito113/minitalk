/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:42:13 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 11:06:24 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// #include "libft.h"
// #include <stdio.h>

// int	main(void)
// {
// 	char	*src;
// 	char	dest[10];
// 	int		len;

// 	src = "";
// 	len = ft_strlcpy(dest, src, 0);
// 	printf("src=\"%s\", size=0\nlen = %d\ndest = \"%s\"\n\n", src, len,
// 		dest);
// 	len = ft_strlcpy(dest, src, 1);
// 	printf("src=\"%s\", size=1\nlen = %d\ndest = \"%s\"\n\n", src, len,
// 		dest);
// 	len = ft_strlcpy(dest, src, 5);
// 	printf("src=\"%s\", size=5\nlen = %d\ndest = \"%s\"\n\n", src, len,
// 		dest);
// 	src = "A";
// 	len = ft_strlcpy(dest, src, 0);
// 	printf("src=\"%s\", size=0\nlen = %d\ndest = \"%s\"\n\n", src, len,
// 		dest);
// 	len = ft_strlcpy(dest, src, 1);
// 	printf("src=\"%s\", size=1\nlen = %d\ndest = \"%s\"\n\n", src, len,
// 		dest);
// 	len = ft_strlcpy(dest, src, 2);
// 	printf("src=\"%s\", size=2\nlen = %d\ndest = \"%s\"\n\n", src, len,
// 		dest);
// 	src = "abc";
// 	len = ft_strlcpy(dest, src, 5);
// 	printf("src=\"%s\", size=5\nlen = %d\ndest = \"%s\"\n\n", src, len,
// 		dest);
// 	src = "abcd";
// 	len = ft_strlcpy(dest, src, 5);
// 	printf("src=\"%s\", size=5\nlen = %d\ndest = \"%s\"\n\n", src, len,
// 		dest);
// 	src = "abcdef";
// 	len = ft_strlcpy(dest, src, 5);
// 	printf("src=\"%s\", size=5\nlen = %d\ndest = \"%s\"\n\n", src, len,
// 		dest);
// 	src = "hello\0world";
// 	len = ft_strlcpy(dest, src, 10);
// 	printf("src=\"%s\", size=10\nlen = %d\ndest = \"%s\"\n\n", src, len,
// 		dest);
// 	src = "A! B?";
// 	len = ft_strlcpy(dest, src, 4);
// 	printf("src=\"%s\", size=4\nlen = %d\ndest = \"%s\"\n\n", src, len,
// 		dest);
// 	src = "lorem ipsum dolor sit amet";
// 	len = ft_strlcpy(dest, src, 9);
// 	printf("src=\"%s\", size=9\nlen = %d\ndest = \"%s\"\n\n", src, len,
// 		dest);
// 	return (0);
// }

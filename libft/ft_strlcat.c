/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:09:37 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 14:25:24 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while ((i + dst_len < size - 1) && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// #include <assert.h>
// #include <stdio.h>
// #include <string.h>

// static void	test_ft_strlcat_normal(void)
// {
// 	char		dst[30] = "Hello ";
// 	const char	*src = "World";
// 	size_t		ret;

// 	ret = ft_strlcat(dst, src, 20);
// 	assert(ret == 11);
// 	assert(strcmp(dst, "Hello World") == 0);
// 	printf("✅ STRLCAT_01 passed\n");
// }

// static void	test_ft_strlcat_one_byte_left(void)
// {
// 	char		dst[30] = "Hello";
// 	const char	*src = "!";
// 	size_t		ret;

// 	ret = ft_strlcat(dst, src, 7);
// 	assert(ret == 6);
// 	assert(strcmp(dst, "Hello!") == 0);
// 	printf("✅ STRLCAT_02 passed\n");
// }

// static void	test_ft_strlcat_no_space(void)
// {
// 	char		dst[30] = "Hello";
// 	const char	*src = "World";
// 	size_t		ret;

// 	ret = ft_strlcat(dst, src, 5);
// 	assert(ret == 10);
// 	assert(strcmp(dst, "Hello") == 0);
// 	printf("✅ STRLCAT_03 passed\n");
// }

// static void	test_ft_strlcat_dstsize_zero(void)
// {
// 	char		dst[30] = "Hello";
// 	const char	*src = "World";
// 	size_t		ret;

// 	ret = ft_strlcat(dst, src, 0);
// 	assert(ret == 5);
// 	assert(strcmp(dst, "Hello") == 0);
// 	printf("✅ STRLCAT_04 passed\n");
// }

// static void	test_ft_strlcat_src_empty(void)
// {
// 	char		dst[30] = "Hello";
// 	const char	*src = "";
// 	size_t		ret;

// 	ret = ft_strlcat(dst, src, 10);
// 	assert(ret == 5);
// 	assert(strcmp(dst, "Hello") == 0);
// 	printf("✅ STRLCAT_05 passed\n");
// }

// static void	test_ft_strlcat_exact_null_terminate(void)
// {
// 	char		dst[30] = "ABCD";
// 	const char	*src = "EFGH";
// 	size_t		ret;

// 	ret = ft_strlcat(dst, src, 8);
// 	assert(ret == 8);
// 	assert(strcmp(dst, "ABCDEFG") == 0);
// 	printf("✅ STRLCAT_06 passed\n");
// }

// int	main(void)
// {
// 	test_ft_strlcat_normal();
// 	test_ft_strlcat_one_byte_left();
// 	test_ft_strlcat_no_space();
// 	test_ft_strlcat_dstsize_zero();
// 	test_ft_strlcat_src_empty();
// 	test_ft_strlcat_exact_null_terminate();
// 	printf("🎉 All ft_strlcat tests passed!\n");
// 	return (0);
// }

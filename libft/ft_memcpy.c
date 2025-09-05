/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:29:31 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 09:54:45 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*cpy;
	const unsigned char	*source;
	size_t				i;

	source = (const unsigned char *)src;
	cpy = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		cpy[i] = source[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// void	print_buffer(const char *label, const unsigned char *buf, size_t n)
// {
// 	size_t	i;

// 	printf("%s = ", label);
// 	for (i = 0; i < n; i++)
// 		printf("%02x ", buf[i]);
// 	printf("\n");
// }

// int	main(void)
// {
// 	char			src1[] = "hello";
// 	char			ft_dest1[10];
// 	char			std_dest1[10];
// 	char			src2[] = "abcdef";
// 	char			ft_dest2[10] = {0};
// 	char			std_dest2[10] = {0};
// 	char			src3[] = "12345";
// 	char			ft_dest3[10] = "xxxxx";
// 	char			std_dest3[10] = "xxxxx";
// 	unsigned char	src4[] = {'a', '\0', 'b', 'c'};
// 	unsigned char	ft_dest4[10] = {0};
// 	unsigned char	std_dest4[10] = {0};
// 	char			buffer1[] = "SELFTEST";
// 	char			buffer2[] = "SELFTEST";
// 	char			src6[] = "world";
// 	char			ft_dest6[10];
// 	char			std_dest6[10];
// 	char			*ret_ft;
// 	char			*ret_std;
// 	char			*null1;
// 	char			*null2;

// 	ft_memcpy(ft_dest1, src1, 6);
// 	memcpy(std_dest1, src1, 6);
// 	printf("test1(ft)  = %s\n", ft_dest1);
// 	printf("test1(std) = %s\n\n", std_dest1);
// 	ft_memcpy(ft_dest2, src2, 3);
// 	memcpy(std_dest2, src2, 3);
// 	ft_dest2[3] = '\0';
// 	std_dest2[3] = '\0';
// 	printf("test2(ft)  = %s\n", ft_dest2);
// 	printf("test2(std) = %s\n\n", std_dest2);
// 	ft_memcpy(ft_dest3, src3, 0);
// 	memcpy(std_dest3, src3, 0);
// 	printf("test3(ft)  = %s\n", ft_dest3);
// 	printf("test3(std) = %s\n\n", std_dest3);
// 	ft_memcpy(ft_dest4, src4, 4);
// 	memcpy(std_dest4, src4, 4);
// 	print_buffer("test4(ft)", ft_dest4, 4);
// 	print_buffer("test4(std)", std_dest4, 4);
// 	printf("\n");
// 	ft_memcpy(buffer1, buffer1, 8);
// 	memcpy(buffer2, buffer2, 8);
// 	printf("test5(ft)  = %s\n", buffer1);
// 	printf("test5(std) = %s\n\n", buffer2);
// 	ret_ft = ft_memcpy(ft_dest6, src6, 6);
// 	ret_std = memcpy(std_dest6, src6, 6);
// 	printf("test6(ft return)  = %s\n", (ret_ft == ft_dest6) ? "OK" : "NG");
// 	printf("test6(std return) = %s\n", (ret_std == std_dest6) ? "OK" : "NG");
// 	printf("test6(ft)  = %s\n", ft_dest6);
// 	printf("test6(std) = %s\n\n", std_dest6);
// 	null1 = NULL;
// 	null2 = NULL;
// 	ft_memcpy(null1, null2, 0);
// 	memcpy(null1, null2, 0);
// 	printf("test7(ft)  = passed\n");
// 	printf("test7(std) = passed\n");
// 	null1 = NULL;
// 	null2 = NULL;
// 	ft_memcpy(null1, null2, 7);
// 	memcpy(null1, null2, 7);
// 	printf("test8(ft)  = passed\n");
// 	printf("test8(std) = passed\n");
// 	return (0);
// }

// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// static void	test_ft_memcpy_normal(void)
// {
// 	char	src[] = "Hello";
// 	char	dst[6] = {0};

// 	assert(memcmp(ft_memcpy(dst, src, 6), src, 6) == 0);
// }

// static void	test_ft_memcpy_n_zero(void)
// {
// 	char	src[] = "abc";
// 	char	dst[] = "XYZ";

// 	ft_memcpy(dst, src, 0);
// 	assert(strcmp(dst, "XYZ") == 0);
// }

// static void	test_ft_memcpy_with_null_bytes(void)
// {
// 	char	src[] = {'a', '\0', 'b'};
// 	char	dst[3] = {'x', 'x', 'x'};

// 	ft_memcpy(dst, src, 3);
// 	assert(dst[0] == 'a' && dst[1] == '\0' && dst[2] == 'b');
// }

// static void	test_ft_memcpy_large_data(void)
// {
// 	unsigned char	*src;
// 	unsigned char	*dst;

// 	src = malloc(1024);
// 	dst = malloc(1024);
// 	for (size_t i = 0; i < 1024; i++)
// 		src[i] = (unsigned char)(i % 256);
// 	ft_memcpy(dst, src, 1024);
// 	assert(memcmp(dst, src, 1024) == 0);
// 	free(src);
// 	free(dst);
// }

// static void	test_ft_memcpy_same_pointer(void)
// {
// 	char	buf[] = "test";

// 	assert(ft_memcpy(buf, buf, 4) == buf);
// 	assert(strcmp(buf, "test") == 0);
// }

// void	test_memcpy_overlap_ub(void)
// {
// 	char	buf[10] = "abcdefghi";

// 	ft_memcpy(buf + 2, buf, 6);
// 	printf("After memcpy overlap: %s\n", buf);
// }

// int	main(void)
// {
// 	test_ft_memcpy_normal();
// 	test_ft_memcpy_n_zero();
// 	test_ft_memcpy_with_null_bytes();
// 	test_ft_memcpy_large_data();
// 	test_ft_memcpy_same_pointer();
// 	test_memcpy_overlap_ub();
// 	puts("All tests passed.");
// 	return (0);
// }

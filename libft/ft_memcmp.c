/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:15:25 by keitabe           #+#    #+#             */
/*   Updated: 2025/04/27 13:08:47 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	const char	*str1;
// 	const char	*str2;

// 	str1 = "abc";
// 	str2 = "abc";
// 	printf("test1 = %d\n", ft_memcmp(str1, str2, 3));
// 	printf("test1(std) = %d\n\n", memcmp(str1, str2, 3));
// 	str1 = "abc";
// 	str2 = "abd";
// 	printf("test2 = %d\n", ft_memcmp(str1, str2, 3));
// 	printf("test2(std) = %d\n\n", memcmp(str1, str2, 3));
// 	str1 = "abd";
// 	str2 = "abc";
// 	printf("test3 = %d\n", ft_memcmp(str1, str2, 3));
// 	printf("test3(std) = %d\n\n", memcmp(str1, str2, 3));
// 	str1 = "abcdef";
// 	str2 = "abcxyz";
// 	printf("test4 = %d\n", ft_memcmp(str1, str2, 3));
// 	printf("test4(std) = %d\n\n", memcmp(str1, str2, 3));
// 	str1 = "abcdef";
// 	str2 = "abcxyz";
// 	printf("test5 = %d\n", ft_memcmp(str1, str2, 6));
// 	printf("test5(std) = %d\n\n", memcmp(str1, str2, 6));
// 	str1 = "";
// 	str2 = "abc";
// 	printf("test6 = %d\n", ft_memcmp(str1, str2, 3));
// 	printf("test6(std) = %d\n\n", memcmp(str1, str2, 3));
// 	str1 = "abc";
// 	str2 = "";
// 	printf("test7 = %d\n", ft_memcmp(str1, str2, 3));
// 	printf("test7(std) = %d\n\n", memcmp(str1, str2, 3));
// 	str1 = "";
// 	str2 = "";
// 	printf("test8 = %d\n", ft_memcmp(str1, str2, 3));
// 	printf("test8(std) = %d\n\n", memcmp(str1, str2, 3));
// 	str1 = "abc";
// 	str2 = "abc";
// 	printf("test9 = %d\n", ft_memcmp(str1, str2, 0));
// 	printf("test9(std) = %d\n\n", memcmp(str1, str2, 0));
// 	str1 = "abc";
// 	str2 = "abd";
// 	printf("test10 = %d\n", ft_memcmp(str1, str2, 1));
// 	printf("test10(std) = %d\n\n", memcmp(str1, str2, 1));
// 	str1 = "abc";
// 	str2 = "abd";
// 	printf("test11 = %d\n", ft_memcmp(str1, str2, 2));
// 	printf("test11(std) = %d\n\n", memcmp(str1, str2, 2));
// 	str1 = "abc";
// 	str2 = "abd";
// 	printf("test12 = %d\n", ft_memcmp(str1, str2, 3));
// 	printf("test12(std) = %d\n\n", memcmp(str1, str2, 3));
// 	str1 = "ab";
// 	str2 = "abc";
// 	printf("test13 = %d\n", ft_memcmp(str1, str2, 5));
// 	printf("test13(std) = %d\n\n", memcmp(str1, str2, 5));
// 	str1 = "abc";
// 	str2 = "ab";
// 	printf("test14 = %d\n", ft_memcmp(str1, str2, 5));
// 	printf("test14(std) = %d\n\n", memcmp(str1, str2, 5));
// 	str1 = "ab\0c";
// 	str2 = "ab\0d";
// 	printf("test15 = %d\n", ft_memcmp(str1, str2, 5));
// 	printf("test15(std) = %d\n\n", memcmp(str1, str2, 5));
// 	str1 = "Abc";
// 	str2 = "abc";
// 	printf("test16 = %d\n", ft_memcmp(str1, str2, 3));
// 	printf("test16(std) = %d\n\n", memcmp(str1, str2, 3));
// 	str1 = "\x80";
// 	str2 = "\x00";
// 	printf("test17 = %d\n", ft_memcmp(str1, str2, 1));
// 	printf("test17(std) = %d\n\n", memcmp(str1, str2, 1));
// 	str1 = "\nabc";
// 	str2 = "\nabc";
// 	printf("test18 = %d\n", ft_memcmp(str1, str2, 4));
// 	printf("test18(std) = %d\n\n", memcmp(str1, str2, 4));
// 	str1 = "abc";
// 	str2 = "abc";
// 	printf("test19 = %d\n", ft_memcmp(str1, str2, 1000));
// 	printf("test19(std) = %d\n\n", memcmp(str1, str2, 1000));
// 	str1 = "aasdfgh\0\0ffvfg";
// 	str2 = "aasdfgh\0\0ffyfg";
// 	printf("test20 = %d\n", ft_memcmp(str1, str2, 14));
// 	printf("test20(std) = %d\n\n", memcmp(str1, str2, 14));
// 	str1 = NULL;
// 	str2 = "abc";
// 	printf("test19 = %d\n", ft_memcmp(str1, str2, 7));
// 	printf("test19(std) = %d\n\n", memcmp(str1, str2, 7));
// 	return (0);
// }

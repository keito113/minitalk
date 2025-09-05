/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:04:16 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 10:39:01 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;

// 	str = "abcdefg";
// 	printf("before = %s\n\n", str);
// 	printf("test1 = %s\n", ft_strchr(str, 'c'));
// 	printf("test2 = %s\n", ft_strchr(str, 'a'));
// 	printf("test3 = %s\n", ft_strchr(str, 'g'));
// 	printf("test4 = %s\n", ft_strchr(str, 'x'));
// 	printf("test5 = %s\n", ft_strchr(str, '\0'));
// 	printf("test6 = %s\n", ft_strchr("", 'a'));
// 	printf("test7 = %s\n", ft_strchr("abacad", 'a'));
// 	return (0);
// }

// #include <assert.h>
// #include <stdio.h>
// #include <string.h>

// static void	test_ft_strchr_head(void)
// {
// 	const char	*s = "abc";

// 	assert(ft_strchr(s, 'a') == strchr(s, 'a'));
// 	printf("✅ STRCHR_01 passed\n");
// }

// static void	test_ft_strchr_middle(void)
// {
// 	const char	*s = "abc";

// 	assert(ft_strchr(s, 'b') == strchr(s, 'b'));
// 	printf("✅ STRCHR_02 passed\n");
// }

// static void	test_ft_strchr_first_occurrence(void)
// {
// 	const char	*s = "abca";

// 	assert(ft_strchr(s, 'a') == strchr(s, 'a'));
// 	printf("✅ STRCHR_03 passed\n");
// }

// static void	test_ft_strchr_not_found(void)
// {
// 	const char	*s = "abc";

// 	assert(ft_strchr(s, 'x') == strchr(s, 'x'));
// 	printf("✅ STRCHR_04 passed\n");
// }

// static void	test_ft_strchr_nullbyte_nonempty(void)
// {
// 	const char	*s = "abc";

// 	assert(ft_strchr(s, '\0') == strchr(s, '\0'));
// 	printf("✅ STRCHR_05 passed\n");
// }

// static void	test_ft_strchr_nullbyte_empty(void)
// {
// 	const char	*s = "";

// 	assert(ft_strchr(s, '\0') == strchr(s, '\0'));
// 	printf("✅ STRCHR_06 passed\n");
// }

// static void	test_ft_strchr_empty_not_found(void)
// {
// 	const char	*s = "";

// 	assert(ft_strchr(s, 'a') == strchr(s, 'a'));
// 	printf("✅ STRCHR_07 passed\n");
// }

// static void	test_ft_strchr_unsigned_char(void)
// {
// 	const char	*s = "ÆØÅ";

// 	assert(ft_strchr(s, 0xC6) == strchr(s, 0xC6));
// 	printf("✅ STRCHR_08 passed\n");
// }

// int	main(void)
// {
// 	test_ft_strchr_head();
// 	test_ft_strchr_middle();
// 	test_ft_strchr_first_occurrence();
// 	test_ft_strchr_not_found();
// 	test_ft_strchr_nullbyte_nonempty();
// 	test_ft_strchr_nullbyte_empty();
// 	test_ft_strchr_empty_not_found();
// 	test_ft_strchr_unsigned_char();
// 	printf("🎉  All ft_strchr tests passed!\n");
// 	return (0);
// }

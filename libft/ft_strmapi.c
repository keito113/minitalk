/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:47:28 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 11:36:25 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>

// static char	identity(unsigned int idx, char c)
// {
// 	(void)idx;
// 	return (c);
// }

// static char	to_upper(unsigned int idx, char c)
// {
// 	(void)idx;
// 	if (c >= 'a' && c <= 'z')
// 		return (c - ('a' - 'A'));
// 	return (c);
// }

// static char	to_lower(unsigned int idx, char c)
// {
// 	(void)idx;
// 	if (c >= 'A' && c <= 'Z')
// 		return (c + ('a' - 'A'));
// 	return (c);
// }

// static char	star_digit(unsigned int idx, char c)
// {
// 	(void)idx;
// 	if (c >= '0' && c <= '9')
// 		return ('*');
// 	return (c);
// }

// static char	shift_i(unsigned int idx, char c)
// {
// 	return ((char)(c + idx));
// }

// int	main(void)
// {
// 	char	*res;

// 	res = ft_strmapi(NULL, to_upper);
// 	printf("test1 (NULL s): %s\n", res == NULL ? "NULL" : res);
// 	res = ft_strmapi("abc", NULL);
// 	printf("test2 (NULL f): %s\n", res == NULL ? "NULL" : res);
// 	res = ft_strmapi("", identity);
// 	printf("test3 (\"\", identity): \"%s\"\n", res);
// 	free(res);
// 	res = ft_strmapi("abc", identity);
// 	printf("test4 (\"abc\", identity): \"%s\"\n", res);
// 	free(res);
// 	res = ft_strmapi("abc", to_upper);
// 	printf("test5 (\"abc\", to_upper): \"%s\"\n", res);
// 	free(res);
// 	res = ft_strmapi("ABC", to_lower);
// 	printf("test6 (\"ABC\", to_lower): \"%s\"\n", res);
// 	free(res);
// 	res = ft_strmapi("12345", star_digit);
// 	printf("test7 (\"12345\", star_digit): \"%s\"\n", res);
// 	free(res);
// 	res = ft_strmapi("hello", shift_i);
// 	printf("test8 (\"hello\", shift_i): \"%s\"\n", res);
// 	free(res);
// 	res = ft_strmapi("a!b@C", identity);
// 	printf("test9 (\"a!b@C\", identity): \"%s\"\n", res);
// 	free(res);
// 	res = ft_strmapi("こんにちは", identity);
// 	printf("test10 (\"こんにちは\", identity): \"%s\"\n", res);
// 	free(res);
// 	res = ft_strmapi("abcdefghijklmnopqrstuvwxyz", identity);
// 	printf("test11 (alphabet, identity): \"%s\"\n", res);
// 	free(res);
// 	return (0);
// }

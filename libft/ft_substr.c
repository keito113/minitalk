/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:32:59 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 14:26:00 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	mem_len(size_t s_len, size_t len, size_t start)
{
	if (start >= s_len)
		return (0);
	else
	{
		if (len < s_len - start)
			return (len);
		else
			return (s_len - start);
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;
	size_t	need_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	need_len = mem_len(s_len, len, (size_t)start);
	str = malloc(need_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < need_len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include "libft.h"
// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	char	*test;
// 	int		start;
// 	int		len;

// 	str = "Hello, world!";
// 	start = 7;
// 	len = 5;
// 	test = ft_substr(str, start, len);
// 	printf("test1 = %s\n", test);
// 	free(test);
// 	str = "Hello";
// 	start = 10;
// 	len = 3;
// 	test = ft_substr(str, start, len);
// 	printf("test2 = %s\n", test);
// 	free(test);
// 	str = "Hello";
// 	start = 5;
// 	len = 2;
// 	test = ft_substr(str, start, len);
// 	printf("test3 = %s\n", test);
// 	free(test);
// 	str = "abcdef";
// 	start = 2;
// 	len = 10;
// 	test = ft_substr(str, start, len);
// 	printf("test4 = %s\n", test);
// 	free(test);
// 	str = "Edge";
// 	start = 1;
// 	len = 0;
// 	test = ft_substr(str, start, len);
// 	printf("test5 = %s\n", test);
// 	free(test);
// 	str = "Sample";
// 	start = 0;
// 	len = 3;
// 	test = ft_substr(str, start, len);
// 	printf("test6 = %s\n", test);
// 	free(test);
// 	str = "Sample";
// 	start = 0;
// 	len = 6;
// 	test = ft_substr(str, start, len);
// 	printf("test7 = %s\n", test);
// 	free(test);
// 	str = "Sample";
// 	start = 0;
// 	len = 10;
// 	test = ft_substr(str, start, len);
// 	printf("test8 = %s\n", test);
// 	free(test);
// 	str = "";
// 	start = 0;
// 	len = 5;
// 	test = ft_substr(str, start, len);
// 	printf("test9 = %s\n", test);
// 	free(test);
// 	str = "";
// 	start = 5;
// 	len = 3;
// 	test = ft_substr(str, start, len);
// 	printf("test10 = %s\n", test);
// 	free(test);
// 	str = "abc";
// 	start = 2;
// 	len = 1;
// 	test = ft_substr(str, start, len);
// 	printf("test11 = %s\n", test);
// 	free(test);
// 	str = "abc";
// 	start = 2;
// 	len = 5;
// 	test = ft_substr(str, start, len);
// 	printf("test12 = %s\n", test);
// 	free(test);
// 	str = NULL;
// 	start = 0;
// 	len = 5;
// 	test = ft_substr(str, start, len);
// 	if (!test)
// 		printf("test13 = NULL\n");
// 	else
// 	{
// 		printf("test13 = %s\n", test);
// 		free(test);
// 	}
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:00:15 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 12:19:08 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	mem_len(const char *str, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	while (str[start] && is_set(str[start], set))
		start++;
	end = ft_strlen(str);
	while (end > start && is_set(str[end - 1], set))
		end--;
	len = end - start;
	return (len);
}

static void	strncpy_ease(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && is_set(*s1, set))
		s1++;
	len = mem_len(s1, set);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	strncpy_ease(str, s1, len);
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*set;
// 	char	*test;

// 	s1 = NULL;
// 	set = "-";
// 	test = ft_strtrim(s1, set);
// 	if (test)
// 	{
// 		printf("test1 = %s\n", test);
// 		free(test);
// 	}
// 	else
// 		printf("test1 = NULL\n");
// 	s1 = "abc";
// 	set = NULL;
// 	test = ft_strtrim(s1, set);
// 	if (test)
// 	{
// 		printf("test2 = %s\n", test);
// 		free(test);
// 	}
// 	else
// 		printf("test2 = NULL\n");
// 	s1 = "";
// 	set = "";
// 	test = ft_strtrim(s1, set);
// 	printf("test3 = %s\n", test);
// 	free(test);
// 	s1 = "";
// 	set = "xyz";
// 	test = ft_strtrim(s1, set);
// 	printf("test4 = %s\n", test);
// 	free(test);
// 	s1 = "abc";
// 	set = "";
// 	test = ft_strtrim(s1, set);
// 	printf("test5 = %s\n", test);
// 	free(test);
// 	s1 = "abc";
// 	set = "xyz";
// 	test = ft_strtrim(s1, set);
// 	printf("test6 = %s\n", test);
// 	free(test);
// 	s1 = "--abc";
// 	set = "-";
// 	test = ft_strtrim(s1, set);
// 	printf("test7 = %s\n", test);
// 	free(test);
// 	s1 = "  foo";
// 	set = " ";
// 	test = ft_strtrim(s1, set);
// 	printf("test8 = %s\n", test);
// 	free(test);
// 	s1 = "bar##";
// 	set = "#";
// 	test = ft_strtrim(s1, set);
// 	printf("test9 = %s\n", test);
// 	free(test);
// 	s1 = "baz  ";
// 	set = " ";
// 	test = ft_strtrim(s1, set);
// 	printf("test10 = %s\n", test);
// 	free(test);
// 	s1 = "--hi--";
// 	set = "-";
// 	test = ft_strtrim(s1, set);
// 	printf("test11 = %s\n", test);
// 	free(test);
// 	s1 = "  x  ";
// 	set = " ";
// 	test = ft_strtrim(s1, set);
// 	printf("test12 = %s\n", test);
// 	free(test);
// 	s1 = "aaa";
// 	set = "a";
// 	test = ft_strtrim(s1, set);
// 	printf("test13 = %s\n", test);
// 	free(test);
// 	s1 = "xyzxyz";
// 	set = "xyz";
// 	test = ft_strtrim(s1, set);
// 	printf("test14 = %s\n", test);
// 	free(test);
// 	s1 = "_a_b_c_";
// 	set = "_";
// 	test = ft_strtrim(s1, set);
// 	printf("test15 = %s\n", test);
// 	free(test);
// 	s1 = "x";
// 	set = "x";
// 	test = ft_strtrim(s1, set);
// 	printf("test16 = %s\n", test);
// 	free(test);
// 	s1 = "y";
// 	set = "x";
// 	test = ft_strtrim(s1, set);
// 	printf("test17 = %s\n", test);
// 	free(test);
// 	s1 = "--==foo==--";
// 	set = "-=";
// 	test = ft_strtrim(s1, set);
// 	printf("test18 = %s\n", test);
// 	free(test);
// 	s1 = "xyHelloyx";
// 	set = "xy";
// 	test = ft_strtrim(s1, set);
// 	printf("test19 = %s\n", test);
// 	free(test);
// 	s1 = ",,a,,";
// 	set = ",";
// 	test = ft_strtrim(s1, set);
// 	printf("test20 = %s\n", test);
// 	free(test);
// 	return (0);
// }

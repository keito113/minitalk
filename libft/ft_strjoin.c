/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:16:40 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 11:34:33 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	str = malloc(s1_len + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[s1_len + i] = s2[i];
		i++;
	}
	str[s1_len + i] = '\0';
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	char	*test;
// 	char	s1_12[] = {'a', '\0', 'b', '\0'};
// 	char	s2_12[] = {'c', '\0', 'd', '\0'};

// 	s1 = "Hello, ";
// 	s2 = "world!";
// 	test = ft_strjoin(s1, s2);
// 	printf("test1 = %s\n", test);
// 	free(test);
// 	s1 = "";
// 	s2 = "Test";
// 	test = ft_strjoin(s1, s2);
// 	printf("test2 = %s\n", test);
// 	free(test);
// 	s1 = "Only";
// 	s2 = "";
// 	test = ft_strjoin(s1, s2);
// 	printf("test3 = %s\n", test);
// 	free(test);
// 	s1 = "";
// 	s2 = "";
// 	test = ft_strjoin(s1, s2);
// 	printf("test4 = [%s]\n", test);
// 	free(test);
// 	test = ft_strjoin(NULL, "foo");
// 	if (test)
// 	{
// 		printf("test5 = %s\n", test);
// 		free(test);
// 	}
// 	else
// 		printf("test5 = NULL\n");
// 	s1 = "bar";
// 	test = ft_strjoin(s1, NULL);
// 	if (test)
// 	{
// 		printf("test6 = %s\n", test);
// 		free(test);
// 	}
// 	else
// 		printf("test6 = NULL\n");
// 	test = ft_strjoin(NULL, NULL);
// 	if (test)
// 	{
// 		printf("test7 = %s\n", test);
// 		free(test);
// 	}
// 	else
// 		printf("test7 = NULL\n");
// 	s1 = " ";
// 	s2 = " ";
// 	test = ft_strjoin(s1, s2);
// 	printf("test8 = [%s]\n", test);
// 	free(test);
// 	s1 = "\n";
// 	s2 = "\t";
// 	test = ft_strjoin(s1, s2);
// 	printf("test9 = [%s]\n", test);
// 	free(test);
// 	s1 = "A";
// 	s2 = "B";
// 	test = ft_strjoin(s1, s2);
// 	printf("test10 = %s\n", test);
// 	free(test);
// 	test = ft_strjoin(s1_12, s2_12);
// 	printf("test11 = [%s]\n", test);
// 	free(test);
// 	return (0);
// }

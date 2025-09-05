/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:20:16 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/01 17:21:01 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word(const char *str, char charset)
{
	size_t	words;
	size_t	in_word;
	size_t	i;

	words = 0;
	in_word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != charset)
		{
			if (in_word == 0)
			{
				words++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (words);
}

static size_t	word_len(const char *str, char charset)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == charset)
			return (len);
		len++;
		i++;
	}
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

static void	free_all(char **arr, size_t n)
{
	while (n > 0)
	{
		free(arr[n - 1]);
		n--;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	words;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * ((words = get_word(s, c)) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		len = word_len(s, c);
		result[i] = malloc((len = word_len(s, c)) + 1);
		if (!result[i])
			return (free_all(result, i), NULL);
		strncpy_ease(result[i], s, len);
		s += len;
		i++;
	}
	result[i] = NULL;
	return (result);
}

// #include <stdio.h>

// static void	print_and_free(char **tab, size_t test_num)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!tab)
// 	{
// 		printf("test%zu = NULL\n", test_num);
// 		return ;
// 	}
// 	if (!tab[0])
// 	{
// 		printf("test%zu = <empty>\n", test_num);
// 		free(tab);
// 		return ;
// 	}
// 	while (tab[i])
// 	{
// 		printf("test%zu word[%zu]: %s\n", test_num, i, tab[i]);
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// }

// int	main(void)
// {
// 	char	**test;
// 	char	*s;
// 	char	c;
// 	size_t	i;

// 	s = NULL;
// 	c = ',';
// 	test = ft_split(s, c);
// 	if (!test)
// 		printf("test1 = NULL\n");
// 	else
// 	{
// 		i = 0;
// 		while (test[i])
// 		{
// 			printf("test1 word[%zu]: %s\n", i, test[i]);
// 			free(test[i]);
// 			i++;
// 		}
// 		free(test);
// 	}
// 	printf("\n");
// 	s = "";
// 	c = ',';
// 	test = ft_split(s, c);
// 	print_and_free(test, 2);
// 	printf("\n");
// 	s = ",";
// 	c = ',';
// 	test = ft_split(s, c);
// 	print_and_free(test, 3);
// 	printf("\n");
// 	s = "a";
// 	c = ' ';
// 	test = ft_split(s, c);
// 	i = 0;
// 	while (test[i])
// 	{
// 		printf("test4 word[%zu]: %s\n", i, test[i]);
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	printf("\n");
// 	s = "a";
// 	c = 'a';
// 	test = ft_split(s, c);
// 	print_and_free(test, 5);
// 	printf("\n");
// 	s = "hello";
// 	c = ',';
// 	test = ft_split(s, c);
// 	i = 0;
// 	while (test[i])
// 	{
// 		printf("test6 word[%zu]: %s\n", i, test[i]);
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	printf("\n");
// 	s = "hello,world";
// 	c = ',';
// 	test = ft_split(s, c);
// 	i = 0;
// 	while (test[i])
// 	{
// 		printf("test7 word[%zu]: %s\n", i, test[i]);
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	printf("\n");
// 	s = ",hello";
// 	c = ',';
// 	test = ft_split(s, c);
// 	i = 0;
// 	while (test[i])
// 	{
// 		printf("test8 word[%zu]: %s\n", i, test[i]);
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	printf("\n");
// 	s = "hello,";
// 	c = ',';
// 	test = ft_split(s, c);
// 	i = 0;
// 	while (test[i])
// 	{
// 		printf("test9 word[%zu]: %s\n", i, test[i]);
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	printf("\n");
// 	s = ",hello,";
// 	c = ',';
// 	test = ft_split(s, c);
// 	i = 0;
// 	while (test[i])
// 	{
// 		printf("test10 word[%zu]: %s\n", i, test[i]);
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	printf("\n");
// 	s = "a,,b";
// 	c = ',';
// 	test = ft_split(s, c);
// 	i = 0;
// 	while (test[i])
// 	{
// 		printf("test11 word[%zu]: %s\n", i, test[i]);
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	printf("\n");
// 	s = "  a  bb c  ";
// 	c = ' ';
// 	test = ft_split(s, c);
// 	i = 0;
// 	while (test[i])
// 	{
// 		printf("test12 word[%zu]: %s\n", i, test[i]);
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	printf("\n");
// 	s = "x y z";
// 	c = ' ';
// 	test = ft_split(s, c);
// 	i = 0;
// 	while (test[i])
// 	{
// 		printf("test13 word[%zu]: %s\n", i, test[i]);
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	printf("\n");
// 	s = "\tfoo\tbar";
// 	c = '\t';
// 	test = ft_split(s, c);
// 	i = 0;
// 	while (test[i])
// 	{
// 		printf("test14 word[%zu]: %s\n", i, test[i]);
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	printf("\n");
// 	s = "foo";
// 	c = '\0';
// 	test = ft_split(s, c);
// 	i = 0;
// 	while (test[i])
// 	{
// 		printf("test15 word[%zu]: %s\n", i, test[i]);
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	printf("\n");
// 	s = "abc";
// 	c = 'd';
// 	test = ft_split(s, c);
// 	i = 0;
// 	while (test[i])
// 	{
// 		printf("test16 word[%zu]: %s\n", i, test[i]);
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	printf("\n");
// 	s = "one two three four five six seven eight nine ten";
// 	c = ' ';
// 	test = ft_split(s, c);
// 	i = 0;
// 	while (test[i])
// 	{
// 		printf("test17 word[%zu]: %s\n", i, test[i]);
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	return (0);
// }

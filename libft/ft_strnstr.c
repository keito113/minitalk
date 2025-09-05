/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:15:11 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/01 09:57:00 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	word_check(const char *p1, const char *p2, size_t len)
{
	size_t	j;

	j = 0;
	while (p1[j] && p2[j] && p1[j] == p2[j] && j < len)
		j++;
	if (p2[j] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (word_check(&big[i], little, len - i))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// void	print_result(int test_num, char *result)
// {
// 	printf("Test %d: ", test_num);
// 	if (result == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", result);
// }

// int	main(void)
// {
// 	const char	*big;
// 	const char	*little;
// 	char		*result;
// 	size_t		len;

// 	big = "abcdef";
// 	little = "cde";
// 	len = 6;
// 	result = ft_strnstr(big, little, len);
// 	print_result(1, result);
// 	big = "abcdef";
// 	little = "xyz";
// 	len = 6;
// 	result = ft_strnstr(big, little, len);
// 	print_result(2, result);
// 	big = "abcdef";
// 	little = "abc";
// 	len = 6;
// 	result = ft_strnstr(big, little, len);
// 	print_result(3, result);
// 	big = "abcdef";
// 	little = "def";
// 	len = 6;
// 	result = ft_strnstr(big, little, len);
// 	print_result(4, result);
// 	big = "abcdef";
// 	little = "";
// 	len = 6;
// 	result = ft_strnstr(big, little, len);
// 	print_result(5, result);
// 	big = "";
// 	little = "";
// 	len = 0;
// 	result = ft_strnstr(big, little, len);
// 	print_result(6, result);
// 	big = "";
// 	little = "abc";
// 	len = 0;
// 	result = ft_strnstr(big, little, len);
// 	print_result(7, result);
// 	big = "abcdef";
// 	little = "def";
// 	len = 6;
// 	result = ft_strnstr(big, little, len);
// 	print_result(8, result);
// 	big = "abcdef";
// 	little = "def";
// 	len = 4;
// 	result = ft_strnstr(big, little, len);
// 	print_result(9, result);
// 	big = "abcdef";
// 	little = "abc";
// 	len = 0;
// 	result = ft_strnstr(big, little, len);
// 	print_result(10, result);
// 	big = "abc";
// 	little = "abcdef";
// 	len = 6;
// 	result = ft_strnstr(big, little, len);
// 	print_result(11, result);
// 	big = "abcdef";
// 	little = "abcdx";
// 	len = 6;
// 	result = ft_strnstr(big, little, len);
// 	print_result(12, result);
// 	big = "abcdefghi";
// 	little = "defk";
// 	len = 9;
// 	result = ft_strnstr(big, little, len);
// 	print_result(13, result);
// 	big = "abc def ghi";
// 	little = "def";
// 	len = 11;
// 	result = ft_strnstr(big, little, len);
// 	print_result(14, result);
// 	big = "abc\ndef\nghi";
// 	little = "def";
// 	len = 11;
// 	result = ft_strnstr(big, little, len);
// 	print_result(15, result);
// 	big = NULL;
// 	little = "def";
// 	len = 11;
// 	result = ft_strnstr(big, little, len);
// 	print_result(16, result);
// 	return (0);
// }

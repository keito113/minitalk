/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:01:35 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 15:19:12 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	chr;
	size_t			i;

	ptr = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptr[i] = chr;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// #include <string.h>

// void	print_result(char *label, unsigned char *s1, unsigned char *s2,
// 		size_t n)
// {
// 	size_t	i;

// 	printf("%s(ft)  = ", label);
// 	i = 0;
// 	while (i < n)
// 	{
// 		if (s1[i] >= 32 && s1[i] <= 126)
// 			printf("%c", s1[i]);
// 		else
// 			printf("\\x%02x", s1[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	printf("%s(std) = ", label);
// 	i = 0;
// 	while (i < n)
// 	{
// 		if (s2[i] >= 32 && s2[i] <= 126)
// 			printf("%c", s2[i]);
// 		else
// 			printf("\\x%02x", s2[i]);
// 		i++;
// 	}
// 	printf("\n\n");
// }

// int	main(void)
// {
// 	char	s1[20], s2[20];
// 	int		nums1[4], nums2[4];

// 	strcpy(s1, "Hello");
// 	strcpy(s2, "Hello");
// 	ft_memset(s1 + 2, '*', 3);
// 	memset(s2 + 2, '*', 3);
// 	print_result("test1", (unsigned char *)s1, (unsigned char *)s2, 5);
// 	strcpy(s1, "World");
// 	strcpy(s2, "World");
// 	ft_memset(s1, '#', 5);
// 	memset(s2, '#', 5);
// 	print_result("test2", (unsigned char *)s1, (unsigned char *)s2, 5);
// 	strcpy(s1, "Test");
// 	strcpy(s2, "Test");
// 	ft_memset(s1, 'X', 0);
// 	memset(s2, 'X', (size_t)0);
// 	print_result("test3", (unsigned char *)s1, (unsigned char *)s2, 4);
// 	strcpy(s1, "");
// 	strcpy(s2, "");
// 	ft_memset(s1, 'A', 0);
// 	memset(s2, 'A', (size_t)0);
// 	print_result("test4", (unsigned char *)s1, (unsigned char *)s2, 1);
// 	strcpy(s1, "AB\0CD");
// 	strcpy(s2, "AB\0CD");
// 	ft_memset(s1, '*', 5);
// 	memset(s2, '*', 5);
// 	print_result("test5", (unsigned char *)s1, (unsigned char *)s2, 5);
// 	strcpy(s1, "ABC");
// 	strcpy(s2, "ABC");
// 	ft_memset(s1, 0, 3);
// 	memset(s2, 0, 3);
// 	print_result("test6", (unsigned char *)s1, (unsigned char *)s2, 3);
// 	strcpy(s1, "XYZXYZ");
// 	strcpy(s2, "XYZXYZ");
// 	ft_memset(s1, 255, 6);
// 	memset(s2, 255, 6);
// 	print_result("test7", (unsigned char *)s1, (unsigned char *)s2, 6);
// 	memcpy(nums1, (int[]){1, 2, 3, 4}, sizeof(nums1));
// 	memcpy(nums2, (int[]){1, 2, 3, 4}, sizeof(nums2));
// 	ft_memset(nums1, 1, sizeof(nums1));
// 	memset(nums2, 1, sizeof(nums2));
// 	print_result("test8", (unsigned char *)nums1, (unsigned char *)nums2,
// 		sizeof(nums1));
// 	strcpy(s1, "1234567890");
// 	strcpy(s2, "1234567890");
// 	ft_memset(s1, '9', sizeof(s1));
// 	memset(s2, '9', sizeof(s2));
// 	print_result("test9", (unsigned char *)s1, (unsigned char *)s2,
// 		sizeof(s1));
// 	strcpy(s1, "ABCDEFGH");
// 	strcpy(s2, "ABCDEFGH");
// 	ft_memset(s1 + 1, 'x', 4);
// 	memset(s2 + 1, 'x', 4);
// 	print_result("test10", (unsigned char *)s1, (unsigned char *)s2, 8);
// 	return (0);
// }

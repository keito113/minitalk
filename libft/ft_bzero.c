/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:40:56 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/03 09:53:22 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <strings.h>

// void	print_memory(const unsigned char *buf, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		printf("%02x ", buf[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

// void	print_result(int test_num, void *ft_buf, void *std_buf, size_t size)
// {
// 	printf("test%02d(ft)  = ", test_num);
// 	print_memory((unsigned char *)ft_buf, size);
// 	printf("test%02d(std) = ", test_num);
// 	print_memory((unsigned char *)std_buf, size);
// 	if (memcmp(ft_buf, std_buf, size) == 0)
// 		printf("✅ test%02d: PASSED\n\n", test_num);
// 	else
// 		printf("❌ test%02d: FAILED\n\n", test_num);
// }

// int	main(void)
// {
// 	char	ft_buf[100];
// 	char	std_buf[100];
// 	void	*null_ptr;

// 	null_ptr = NULL;
// 	memset(ft_buf, 'A', 10);
// 	memset(std_buf, 'A', 10);
// 	ft_bzero(ft_buf, (size_t)0);
// 	bzero(std_buf, (size_t)0);
// 	print_result(1, ft_buf, std_buf, 10);
// 	memset(ft_buf, 'A', 10);
// 	memset(std_buf, 'A', 10);
// 	ft_bzero(ft_buf, 1);
// 	bzero(std_buf, 1);
// 	print_result(2, ft_buf, std_buf, 10);
// 	memset(ft_buf, 'A', 10);
// 	memset(std_buf, 'A', 10);
// 	ft_bzero(ft_buf, 5);
// 	bzero(std_buf, 5);
// 	print_result(3, ft_buf, std_buf, 10);
// 	memset(ft_buf, 0, 5);
// 	memset(std_buf, 0, 5);
// 	ft_bzero(ft_buf, 5);
// 	bzero(std_buf, 5);
// 	print_result(4, ft_buf, std_buf, 5);
// 	memset(ft_buf, 'X', 100);
// 	memset(std_buf, 'X', 100);
// 	ft_bzero(ft_buf, 100);
// 	bzero(std_buf, 100);
// 	print_result(5, ft_buf, std_buf, 100);
// 	ft_bzero(null_ptr, (size_t)0);
// 	bzero(null_ptr, (size_t)0);
// 	return (0);
// }

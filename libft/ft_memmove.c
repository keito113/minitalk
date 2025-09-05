/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:29:42 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 14:58:25 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*source;
	size_t				i;

	dst = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (n == 0)
		return (dest);
	i = 0;
	if (source < dst && dst < source + n)
	{
		while (n--)
			dst[n] = source[n];
	}
	else
	{
		while (i < n)
		{
			dst[i] = source[i];
			i++;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void	*ft_memmove(void *dst, const void *src, size_t len);

// void	print_case(const char *label, void *ft_dst, void *std_dst, size_t len)
// {
// 	printf("%s(ft)  = ", label);
// 	fwrite(ft_dst, 1, len, stdout);
// 	printf("\n");
// 	printf("%s(std) = ", label);
// 	fwrite(std_dst, 1, len, stdout);
// 	printf("\n\n");
// }

// int	main(void)
// {
// 	char			buf1[50] = {0};
// 	char			buf2[50] = {0};
// 	unsigned char	bin_src[] = {'a', '\0', 'b', 0xff, 'c', 0x00};
// 	unsigned char	bin_dst1[10];
// 	unsigned char	bin_dst2[10];
// 	char			*null_p;

// 	strcpy(buf1, "abcdef");
// 	strcpy(buf2, "abcdef");
// 	ft_memmove(buf1 + 10, buf1, 6);
// 	memmove(buf2 + 10, buf2, 6);
// 	print_case("test01", buf1, buf2, 20);
// 	strcpy(buf1, "abcdefghij");
// 	strcpy(buf2, "abcdefghij");
// 	ft_memmove(buf1 + 2, buf1, 8);
// 	memmove(buf2 + 2, buf2, 8);
// 	print_case("test02", buf1, buf2, 20);
// 	strcpy(buf1, "abcdefghij");
// 	strcpy(buf2, "abcdefghij");
// 	ft_memmove(buf1, buf1 + 2, 8);
// 	memmove(buf2, buf2 + 2, 8);
// 	print_case("test03", buf1, buf2, 20);
// 	strcpy(buf1, "abcdef");
// 	strcpy(buf2, "abcdef");
// 	ft_memmove(buf1, buf1, 6);
// 	memmove(buf2, buf2, 6);
// 	print_case("test04", buf1, buf2, 10);
// 	strcpy(buf1, "abcdef");
// 	strcpy(buf2, "abcdef");
// 	ft_memmove(buf1 + 1, buf1, 0);
// 	memmove(buf2 + 1, buf2, 0);
// 	print_case("test05", buf1, buf2, 10);
// 	ft_memmove(bin_dst1, bin_src, 6);
// 	memmove(bin_dst2, bin_src, 6);
// 	print_case("test06", bin_dst1, bin_dst2, 6);
// 	strcpy(buf1, "abcdefghij");
// 	strcpy(buf2, "abcdefghij");
// 	ft_memmove(buf1 + 20, buf1, 5);
// 	buf1[25] = '\0';
// 	memmove(buf2 + 20, buf2, 5);
// 	buf2[25] = '\0';
// 	print_case("test07", buf1, buf2, 30);
// 	null_p = 0;
// 	if (ft_memmove(NULL, NULL, 0) == NULL)
// 		printf("test08(ft)  = NULL\n");
// 	else
// 		printf("test08(ft)  = NOT NULL\n");
// 	if (memmove(null_p, null_p, 0) == NULL)
// 		printf("test08(std)  = NULL\n");
// 	else
// 		printf("test08(std)  = NOT NULL\n");
// 	printf("\n");
// 	if (ft_memmove(NULL, NULL, 5) == NULL)
// 		printf("test09(ft)  = NULL\n");
// 	else
// 		printf("test09(ft)  = NOT NULL\n");
// 	null_p = 0;
// 	if (memmove(null_p, null_p, 5) == NULL)
// 		printf("test9(std) = NULL\n");
// 	else
// 		printf("test9(std) = NOT NULL\n");
// 	return (0);
// }

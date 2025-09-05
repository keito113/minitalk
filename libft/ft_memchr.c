/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:51:57 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 15:03:30 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	chr;
	size_t			i;

	ptr = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == chr)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

// #include "libft.h"
// #include <stdio.h>
// #include <string.h>

// void	print_result(const char *label, void *std, void *ft, const void *base)
// {
// 	printf("%s\n", label);
// 	if (std)
// 		printf("  memchr   : found at offset %ld\n", (long)((unsigned char *)std
// 				- (unsigned char *)base));
// 	else
// 		printf("  memchr   : Not found\n");
// 	if (ft)
// 		printf("  ft_memchr: found at offset %ld\n", (long)((unsigned char *)ft
// 				- (unsigned char *)base));
// 	else
// 		printf("  ft_memchr: Not found\n");
// 	printf("\n");
// }

// int	main(void)
// {
// 	char			s1[] = "Hello";
// 	char			s2[] = "he\0lo";
// 	unsigned char	bin[] = {0x01, 0x02, 0x03, 0x04};
// 	void			*null_ptr;

// 	null_ptr = NULL;
// 	print_result("test1: search 'e' in \"Hello\"", memchr(s1, 'e', 5),
// 		ft_memchr(s1, 'e', 5), s1);
// 	print_result("test2: search 'z' in \"Hello\"", memchr(s1, 'z', 5),
// 		ft_memchr(s1, 'z', 5), s1);
// 	print_result("test3: search 'o' in \"Hello\"", memchr(s1, 'o', 5),
// 		ft_memchr(s1, 'o', 5), s1);
// 	print_result("test4: search '\\0' in \"he\\0lo\"", memchr(s2, '\0', 5),
// 		ft_memchr(s2, '\0', 5), s2);
// 	print_result("test5: search '\\0' in \"Hello\"", memchr(s1, '\0', 5),
// 		ft_memchr(s1, '\0', 5), s1);
// 	print_result("test6: search 'h' with n=0", memchr(s1, 'h', 0),
// 		ft_memchr(s1, 'h', 0), s1);
// 	print_result("test7: search 'l' from s + 2", memchr(s1 + 2, 'l', 3),
// 		ft_memchr(s1 + 2, 'l', 3), s1 + 2);
// 	print_result("test8: NULL pointer with n=0", memchr(null_ptr, 'a',
// 			(size_t)0), ft_memchr(null_ptr, 'a', (size_t)0), NULL);
// 	print_result("test9: search 0x03 in binary", memchr(bin, 0x03, 4),
// 		ft_memchr(bin, 0x03, 4), bin);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:26:44 by keitabe           #+#    #+#             */
/*   Updated: 2025/04/26 15:12:12 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	char			*ptr;

	chr = (unsigned char)c;
	ptr = NULL;
	while (*s)
	{
		if (*s == chr)
			ptr = (char *)s;
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (ptr);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*ptr1;

// 	printf("test1 = %s\n", ft_strrchr("Hello", 'e'));
// 	printf("test1(std) = %s\n\n", strrchr("Hello", 'e'));
// 	printf("test2 = %s\n", ft_strrchr("Hello World", 'o'));
// 	printf("test2(std) = %s\n\n", strrchr("Hello World", 'o'));
// 	printf("test3 = %s\n", ft_strrchr("Hello", 'H'));
// 	printf("test3(std) = %s\n\n", strrchr("Hello", 'H'));
// 	printf("test4 = %s\n", ft_strrchr("Hello", 'z'));
// 	printf("test4(std) = %s\n\n", strrchr("Hello", 'z'));
// 	printf("test5 = %s\n", ft_strrchr("Hello", '\0'));
// 	printf("test5(std) = %s\n\n", strrchr("Hello", '\0'));
// 	printf("test6 = %s\n", ft_strrchr("", 'H'));
// 	printf("test6(std) = %s\n\n", strrchr("", 'H'));
// 	printf("test7 = %s\n", ft_strrchr("", '\0'));
// 	printf("test7(std) = %s\n\n", strrchr("", '\0'));
// 	printf("test8 = %s\n", ft_strrchr("ab\ncd\nef", '\n'));
// 	printf("test8(std) = %s\n\n", strrchr("ab\ncd\nef", '\n'));
// 	printf("test9 = segmentation fault\n");
// 	ptr1 = ft_strrchr(NULL, 'e');
// 	if (ptr1)
// 		printf("Found: %s\n", ptr1);
// 	else
// 		printf("Not found\n");
// }

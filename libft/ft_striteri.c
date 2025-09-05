/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 09:35:10 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/01 12:15:52 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// static void	identity(unsigned int idx, char *c)
// {
// 	(void)idx;
// 	(void)c;
// }

// static void	to_upper(unsigned int idx, char *c)
// {
// 	(void)idx;
// 	if (*c >= 'a' && *c <= 'z')
// 		*c -= 'a' - 'A';
// }

// static void	to_lower(unsigned int idx, char *c)
// {
// 	(void)idx;
// 	if (*c >= 'A' && *c <= 'Z')
// 		*c += 'a' - 'A';
// }

// static void	star_digit(unsigned int idx, char *c)
// {
// 	(void)idx;
// 	if (*c >= '0' && *c <= '9')
// 		*c = '*';
// }

// static void	shift_i(unsigned int idx, char *c)
// {
// 	*c = (char)(*c + idx);
// }

// int	main(void)
// {
// 	char	*buf;

// 	buf = NULL;
// 	ft_striteri(buf, to_upper);
// 	printf("test1 (NULL s): %s\n", buf ? buf : "NULL");
// 	buf = strdup("abc");
// 	ft_striteri(buf, NULL);
// 	printf("test2 (NULL f): %s\n", buf);
// 	free(buf);
// 	buf = strdup("");
// 	ft_striteri(buf, identity);
// 	printf("test3 (\"\", identity): \"%s\"\n", buf);
// 	free(buf);
// 	buf = strdup("abc");
// 	ft_striteri(buf, to_upper);
// 	printf("test4 (\"abc\", to_upper): \"%s\"\n", buf);
// 	free(buf);
// 	buf = strdup("ABC");
// 	ft_striteri(buf, to_lower);
// 	printf("test5 (\"ABC\", to_lower): \"%s\"\n", buf);
// 	free(buf);
// 	buf = strdup("12345");
// 	ft_striteri(buf, star_digit);
// 	printf("test6 (\"12345\", star_digit): \"%s\"\n", buf);
// 	free(buf);
// 	buf = strdup("hello");
// 	ft_striteri(buf, shift_i);
// 	printf("test7 (\"hello\", shift_i): \"%s\"\n", buf);
// 	free(buf);
// 	return (0);
// }

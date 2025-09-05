/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:33:55 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 12:27:57 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*cpy;

	len = 0;
	while (s1[len])
		len++;
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// static void	test_ft_strdup_normal(void)
// {
// 	const char	*src = "hello";
// 	char		*res;

// 	res = ft_strdup(src);
// 	assert(res != NULL);
// 	assert(strcmp(res, src) == 0);
// 	free(res);
// 	printf("test_ft_strdup_normal: OK\n");
// }

// static void	test_ft_strdup_empty(void)
// {
// 	const char	*src = "";
// 	char		*res;

// 	res = ft_strdup(src);
// 	assert(res != NULL);
// 	assert(strcmp(res, src) == 0);
// 	free(res);
// 	printf("test_ft_strdup_empty: OK\n");
// }

// static void	test_ft_strdup_control_chars(void)
// {
// 	const char	*src = "a\nb\tc";
// 	char		*res;

// 	res = ft_strdup(src);
// 	assert(res != NULL);
// 	assert(strcmp(res, src) == 0);
// 	free(res);
// 	printf("test_ft_strdup_control_chars: OK\n");
// }

// static void	test_ft_strdup_long_string(void)
// {
// 	char	src[128];
// 	char	*res;
// 	int		i;

// 	for (i = 0; i < 127; i++)
// 		src[i] = 'A' + (i % 26);
// 	src[127] = '\0';
// 	res = ft_strdup(src);
// 	assert(res != NULL);
// 	assert(strcmp(res, src) == 0);
// 	free(res);
// 	printf("test_ft_strdup_long_string: OK\n");
// }

// int	main(void)
// {
// 	test_ft_strdup_normal();
// 	test_ft_strdup_empty();
// 	test_ft_strdup_control_chars();
// 	test_ft_strdup_long_string();
// 	return (0);
// }

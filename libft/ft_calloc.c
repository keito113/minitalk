/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:55:16 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/13 11:53:31 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	all;

	all = nmemb * size;
	if (size && all / size != nmemb)
		return (NULL);
	if (!nmemb)
		return (malloc(0));
	ptr = malloc(all);
	if (ptr)
		ft_bzero(ptr, all);
	return (ptr);
}

// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// void	print_int_array(const char *label, int *arr, size_t len)
// {
// 	size_t	i;

// 	printf("%s", label);
// 	i = 0;
// 	while (i < len)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

// void	print_char_array(const char *label, char *arr, size_t len)
// {
// 	size_t	i;

// 	printf("%s", label);
// 	i = 0;
// 	while (i < len)
// 	{
// 		printf("%02x ", (unsigned char)arr[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

// int	main(void)
// {
// 	int		*arr_ft;
// 	int		*arr_std;
// 	char	*big_ft;
// 	char	*big_std;

// 	printf("== Normal case: calloc(5, sizeof(int)) ==\n");
// 	arr_ft = (int *)ft_calloc(5, sizeof(int));
// 	arr_std = (int *)calloc(5, sizeof(int));
// 	print_int_array("ft_calloc:  ", arr_ft, 5);
// 	print_int_array("calloc:     ", arr_std, 5);
// 	free(arr_ft);
// 	free(arr_std);
// 	printf("\n== Edge case: calloc(0, sizeof(int)) ==\n");
// 	arr_ft = (int *)ft_calloc(0, sizeof(int));
// 	arr_std = (int *)calloc(0, sizeof(int));
// 	printf("ft_calloc:  %p\n", (void *)arr_ft);
// 	printf("calloc:     %p\n", (void *)arr_std);
// 	free(arr_ft);
// 	free(arr_std);
// 	printf("\n== Edge case: calloc(5, 0) ==\n");
// 	arr_ft = (int *)ft_calloc(5, 0);
// 	arr_std = (int *)calloc(5, 0);
// 	printf("ft_calloc:  %p\n", (void *)arr_ft);
// 	printf("calloc:     %p\n", (void *)arr_std);
// 	free(arr_ft);
// 	free(arr_std);
// 	printf("\n== Large case: calloc(1000, sizeof(char)) ==\n");
// 	big_ft = (char *)ft_calloc(1000, sizeof(char));
// 	big_std = (char *)calloc(1000, sizeof(char));
// 	print_char_array("ft_calloc:  ", big_ft, 10);
// 	print_char_array("calloc:     ", big_std, 10);
// 	free(big_ft);
// 	free(big_std);
// 	return (0);
// }

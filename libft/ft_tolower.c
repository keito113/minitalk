/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:15:01 by keitabe           #+#    #+#             */
/*   Updated: 2025/04/30 12:16:55 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += 32;
	return (c);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	chr;

// 	for (chr = 65; chr <= 90; chr++)
// 		printf("%c = %c\n", (char)chr, (char)(ft_tolower(chr)));
// 	printf("\nnumber\n\n");
// 	for (chr = 48; chr <= 57; chr++)
// 		printf("%c = %c\n", (char)chr, (char)(ft_tolower(chr)));
// 	printf("\nothers\n\n");
// 	chr = 37;
// 	printf("%c = %c\n", (char)chr, (char)(ft_tolower(chr)));
// 	chr = -1;
// 	printf("%d = %d\n", chr, ft_tolower(chr));
// 	chr = 2147483647;
// 	printf("%d = %d\n", chr, ft_tolower(chr));
// 	chr = -2147483648;
// 	printf("%d = %d\n", chr, ft_tolower(chr));
// 	return (0);
// }

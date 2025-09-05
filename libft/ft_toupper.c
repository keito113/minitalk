/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:15:04 by keitabe           #+#    #+#             */
/*   Updated: 2025/04/30 12:17:02 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= 32;
	return (c);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	chr;

// 	for (chr = 97; chr <= 122; chr++)
// 		printf("%c = %c\n", (char)chr, (char)(ft_toupper(chr)));
// 	printf("\nnumber\n\n");
// 	for (chr = 48; chr <= 57; chr++)
// 		printf("%c = %c\n", (char)chr, (char)(ft_toupper(chr)));
// 	printf("\nothers\n\n");
// 	chr = 37;
// 	printf("%c = %c\n", (char)chr, (char)(ft_toupper(chr)));
// 	chr = -1;
// 	printf("%d = %d\n", chr, ft_toupper(chr));
// 	chr = 2147483647;
// 	printf("%d = %d\n", chr, ft_toupper(chr));
// 	chr = -2147483648;
// 	printf("%d = %d\n", chr, ft_toupper(chr));
// 	return (0);
// }

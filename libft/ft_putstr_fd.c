/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:39:26 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/01 13:08:05 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
		write(fd, s++, 1);
}

// int	main(void)
// {
// 	ft_putstr_fd("abcdefg\n", 1);
// 	ft_putstr_fd(NULL, 1);
// 	ft_putstr_fd(NULL, -1);
// 	ft_putstr_fd("A", 1);
// 	ft_putstr_fd("", 2);
// 	ft_putstr_fd("", 1);
// 	ft_putstr_fd("Line1\nLine2\n", 1);
// 	ft_putstr_fd("\tTabbed", 1);
// 	return (0);
// }

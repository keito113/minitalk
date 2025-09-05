/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:24:25 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/01 12:37:51 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	ft_putchar_fd('A', 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putchar_fd('\0', 1);
// 	ft_putchar_fd(0x01, 1);
// 	ft_putchar_fd('E', 2);
// 	ft_putchar_fd('X', -1);
// 	ft_putchar_fd('Y', 9999);
// 	return (0);
// }

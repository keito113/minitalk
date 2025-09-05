/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:09:43 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/01 14:18:25 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

// int	main(void)
// {
// 	ft_putendl_fd("abcdefg\n", 1);
// 	ft_putendl_fd(NULL, 1);
// 	ft_putendl_fd(NULL, -1);
// 	ft_putendl_fd("A", 1);
// 	ft_putendl_fd("", 2);
// 	ft_putendl_fd("", 1);
// 	ft_putendl_fd("Line1\nLine2\n", 1);
// 	ft_putendl_fd("\tTabbed", 1);
// 	return (0);
// }

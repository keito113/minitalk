/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:20:22 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/06 19:34:02 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>

// static int	g_callback_flag;

// static void	test_del(void *content)
// {
// 	g_callback_flag++;
// 	(void)content;
// }

// static void	test_ft_lstdelone_basic(void)
// {
// 	t_list	*node;
// 	int		*data;

// 	node = malloc(sizeof(*node));
// 	data = malloc(sizeof(*data));
// 	g_callback_flag = 0;
// 	node->content = data;
// 	ft_lstdelone(node, test_del);
// 	assert(g_callback_flag == 1);
// }

// static void	test_ft_lstdelone_null_list(void)
// {
// 	ft_lstdelone(NULL, test_del);
// }

// static void	test_ft_lstdelone_null_del(void)
// {
// 	t_list	*node;

// 	node = malloc(sizeof(*node));
// 	node->content = malloc(1);
// 	ft_lstdelone(node, NULL);
// 	free(node->content);
// 	free(node);
// }

// static void	test_ft_lstdelone_null_content(void)
// {
// 	t_list	*node;

// 	node = malloc(sizeof(*node));
// 	node->content = NULL;
// 	g_callback_flag = 0;
// 	ft_lstdelone(node, test_del);
// 	assert(g_callback_flag == 1);
// }

// int	main(void)
// {
// 	test_ft_lstdelone_basic();
// 	printf("test_ft_lstdelone_basic passed\n");
// 	test_ft_lstdelone_null_list();
// 	printf("test_ft_lstdelone_null_list passed\n");
// 	test_ft_lstdelone_null_del();
// 	printf("test_ft_lstdelone_null_del passed\n");
// 	test_ft_lstdelone_null_content();
// 	printf("test_ft_lstdelone_null_content passed\n");
// 	printf("All tests passed\n");
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:27:05 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 14:10:04 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>

// static void	test_ft_lstnew_with_content(void)
// {
// 	int		x;
// 	t_list	*node;

// 	x = 42;
// 	node = ft_lstnew(&x);
// 	assert(node != NULL);
// 	assert(node->content == &x);
// 	assert(node->next == NULL);
// 	free(node);
// 	printf("test_ft_lstnew_with_content: OK\n");
// }

// static void	test_ft_lstnew_with_null_content(void)
// {
// 	t_list	*node;

// 	node = ft_lstnew(NULL);
// 	assert(node != NULL);
// 	assert(node->content == NULL);
// 	assert(node->next == NULL);
// 	free(node);
// 	printf("test_ft_lstnew_with_null_content: OK\n");
// }

// static void	test_ft_lstnew_independent_nodes(void)
// {
// 	int		x;
// 	int		y;
// 	t_list	*node1;
// 	t_list	*node2;

// 	x = 1;
// 	y = 2;
// 	node1 = ft_lstnew(&x);
// 	node2 = ft_lstnew(&y);
// 	assert(node1 != node2);
// 	assert(node1->content == &x);
// 	assert(node2->content == &y);
// 	assert(node1->next == NULL);
// 	assert(node2->next == NULL);
// 	free(node1);
// 	free(node2);
// 	printf("test_ft_lstnew_independent_nodes: OK\n");
// }

// int	main(void)
// {
// 	test_ft_lstnew_with_content();
// 	test_ft_lstnew_with_null_content();
// 	test_ft_lstnew_independent_nodes();
// 	printf("All ft_lstnew tests passed!\n");
// 	return (0);
// }

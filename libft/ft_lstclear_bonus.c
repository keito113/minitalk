/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:38:02 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/06 19:49:42 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*current;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next_node = current->next;
		del(current->content);
		free(current);
		current = next_node;
	}
	*lst = NULL;
}

// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>

// static t_list	*create_node(void *content)
// {
// 	t_list	*node;

// 	node = malloc(sizeof(t_list));
// 	assert(node != NULL);
// 	node->content = content;
// 	node->next = NULL;
// 	return (node);
// }

// static void	test_null_lst_ptr(void)
// {
// 	ft_lstclear(NULL, free);
// 	printf("[test_null_lst_ptr] passed\n");
// }

// static void	test_null_del(void)
// {
// 	char	*content;
// 	t_list	*lst;
// 	t_list	*orig;

// 	content = malloc(1);
// 	lst = create_node(content);
// 	orig = lst;
// 	ft_lstclear(&lst, NULL);
// 	assert(lst == orig);
// 	free(content);
// 	free(lst);
// 	printf("[test_null_del] passed\n");
// }

// static void	test_empty_list(void)
// {
// 	t_list	*lst;

// 	lst = NULL;
// 	ft_lstclear(&lst, free);
// 	assert(lst == NULL);
// 	printf("[test_empty_list] passed\n");
// }

// static void	test_single_node(void)
// {
// 	char	*content;
// 	t_list	*lst;

// 	content = malloc(1);
// 	lst = create_node(content);
// 	ft_lstclear(&lst, free);
// 	assert(lst == NULL);
// 	printf("[test_single_node] passed\n");
// }

// static void	test_multiple_nodes(void)
// {
// 	char	*c1;
// 	char	*c2;
// 	t_list	*n1;
// 	t_list	*n2;
// 	t_list	*lst;

// 	c1 = malloc(1);
// 	c2 = malloc(1);
// 	n1 = create_node(c1);
// 	n2 = create_node(c2);
// 	n1->next = n2;
// 	lst = n1;
// 	ft_lstclear(&lst, free);
// 	assert(lst == NULL);
// 	printf("[test_multiple_nodes] passed\n");
// }

// int	main(void)
// {
// 	test_null_lst_ptr();
// 	test_null_del();
// 	test_empty_list();
// 	test_single_node();
// 	test_multiple_nodes();
// 	printf("All ft_lstclear tests passed.\n");
// 	return (0);
// }

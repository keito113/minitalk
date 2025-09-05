/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:36:32 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 14:24:42 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}

// #include "libft.h"
// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>

// static t_list	*create_node(void *content)
// {
// 	t_list	*node;

// 	node = (t_list *)malloc(sizeof(t_list));
// 	assert(node != NULL);
// 	node->content = content;
// 	node->next = NULL;
// 	return (node);
// }

// static void	test_ft_lstadd_back_append(void)
// {
// 	t_list	*head;
// 	t_list	*tail;
// 	t_list	*new;

// 	head = create_node("A");
// 	tail = create_node("B");
// 	new = create_node("C");
// 	head->next = tail;
// 	ft_lstadd_back(&head, new);
// 	assert(tail->next == new);
// 	assert(new->next == NULL);
// 	assert(ft_lstlast(head) == new);
// 	free(head);
// 	free(tail);
// 	free(new);
// }

// static void	test_ft_lstadd_back_empty(void)
// {
// 	t_list	*head;
// 	t_list	*new;

// 	head = NULL;
// 	new = create_node("C");
// 	ft_lstadd_back(&head, new);
// 	assert(head == new);
// 	assert(new->next == NULL);
// 	free(new);
// }

// static void	test_ft_lstadd_back_lstptr_null(void)
// {
// 	t_list	*new;

// 	new = create_node("C");
// 	ft_lstadd_back(NULL, new);
// 	assert(new->next == NULL);
// 	free(new);
// }

// static void	test_ft_lstadd_back_new_null(void)
// {
// 	t_list	*head;
// 	t_list	*tail;

// 	head = create_node("A");
// 	tail = create_node("B");
// 	head->next = tail;
// 	ft_lstadd_back(&head, NULL);
// 	assert(ft_lstlast(head) == tail);
// 	free(tail);
// 	free(head);
// }

// int	main(void)
// {
// 	test_ft_lstadd_back_append();
// 	test_ft_lstadd_back_empty();
// 	test_ft_lstadd_back_lstptr_null();
// 	test_ft_lstadd_back_new_null();
// 	printf("✅  All ft_lstadd_back tests passed!\n");
// 	return (0);
// }

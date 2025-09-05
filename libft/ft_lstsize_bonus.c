/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:58:19 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 09:53:39 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
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

// static t_list	*create_list_of_size(int size)
// {
// 	t_list	*head;
// 	t_list	*curr;
// 	int		i;

// 	if (size <= 0)
// 		return (NULL);
// 	head = create_node(NULL);
// 	curr = head;
// 	for (i = 1; i < size; i++)
// 	{
// 		curr->next = create_node(NULL);
// 		curr = curr->next;
// 	}
// 	return (head);
// }

// static void	free_list(t_list *lst)
// {
// 	t_list	*tmp;

// 	while (lst)
// 	{
// 		tmp = lst->next;
// 		free(lst);
// 		lst = tmp;
// 	}
// }

// static void	test_ft_lstsize_null(void)
// {
// 	assert(ft_lstsize(NULL) == 0);
// 	printf("✅ LSTSIZE_01: NULL input passed\n");
// }

// static void	test_ft_lstsize_zero(void)
// {
// 	t_list	*lst;

// 	lst = NULL;
// 	assert(ft_lstsize(lst) == 0);
// 	printf("✅ LSTSIZE_02: empty list passed\n");
// }

// static void	test_ft_lstsize_one(void)
// {
// 	t_list	*lst;

// 	lst = create_node("one");
// 	assert(ft_lstsize(lst) == 1);
// 	free(lst);
// 	printf("✅ LSTSIZE_03: one element list passed\n");
// }

// static void	test_ft_lstsize_three(void)
// {
// 	t_list	*lst;

// 	lst = create_list_of_size(3);
// 	assert(ft_lstsize(lst) == 3);
// 	free_list(lst);
// 	printf("✅ LSTSIZE_04: three element list passed\n");
// }

// static void	test_ft_lstsize_large(void)
// {
// 	t_list	*lst;

// 	lst = create_list_of_size(100);
// 	assert(ft_lstsize(lst) == 100);
// 	free_list(lst);
// 	printf("✅ LSTSIZE_05: 100 element list passed\n");
// }

// int	main(void)
// {
// 	test_ft_lstsize_null();
// 	test_ft_lstsize_zero();
// 	test_ft_lstsize_one();
// 	test_ft_lstsize_three();
// 	test_ft_lstsize_large();
// 	printf("🎉 All ft_lstsize tests passed successfully!\n");
// 	return (0);
// }

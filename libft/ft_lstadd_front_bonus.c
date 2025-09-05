/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:50:33 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 14:08:35 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>

// static void	test_ft_lstadd_front_normal(void)
// {
// 	t_list	node1;
// 	t_list	node2;
// 	t_list	*lst;

// 	node1.next = NULL;
// 	lst = &node1;
// 	ft_lstadd_front(&lst, &node2);
// 	assert(lst == &node2);
// 	assert(lst->next == &node1);
// 	printf("test_ft_lstadd_front_normal: OK\n");
// }

// static void	test_ft_lstadd_front_empty(void)
// {
// 	t_list	*lst;
// 	t_list	node1;

// 	lst = NULL;
// 	ft_lstadd_front(&lst, &node1);
// 	assert(lst == &node1);
// 	assert(lst->next == NULL);
// 	printf("test_ft_lstadd_front_empty: OK\n");
// }

// static void	test_ft_lstadd_front_new_null(void)
// {
// 	t_list	node1;
// 	t_list	*lst;

// 	node1.next = NULL;
// 	lst = &node1;
// 	ft_lstadd_front(&lst, NULL);
// 	assert(lst == &node1);
// 	assert(lst->next == NULL);
// 	printf("test_ft_lstadd_front_new_null: OK\n");
// }

// static void	test_ft_lstadd_front_lst_null(void)
// {
// 	t_list	node1;

// 	node1.next = NULL;
// 	ft_lstadd_front(NULL, &node1);
// 	assert(node1.next == NULL);
// 	printf("test_ft_lstadd_front_lst_null: OK\n");
// }

// static void	test_ft_lstadd_front_multiple(void)
// {
// 	t_list	*lst;
// 	t_list	node1;
// 	t_list	node2;
// 	t_list	node3;

// 	node1.next = NULL;
// 	lst = &node1;
// 	ft_lstadd_front(&lst, &node2);
// 	ft_lstadd_front(&lst, &node3);
// 	assert(lst == &node3);
// 	assert(node3.next == &node2);
// 	assert(node2.next == &node1);
// 	printf("test_ft_lstadd_front_multiple: OK\n");
// }

// int	main(void)
// {
// 	test_ft_lstadd_front_normal();
// 	test_ft_lstadd_front_empty();
// 	test_ft_lstadd_front_new_null();
// 	test_ft_lstadd_front_lst_null();
// 	test_ft_lstadd_front_multiple();
// 	printf("All ft_lstadd_front tests passed!\n");
// 	return (0);
// }

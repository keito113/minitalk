/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:15:34 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/07 14:17:43 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_cont;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_cont = f(lst->content);
		new_node = ft_lstnew(new_cont);
		if (!new_node)
		{
			del(new_cont);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// static void	*str_dup(void *ptr)
// {
// 	if (!ptr)
// 		return (NULL);
// 	return (strdup((char *)ptr));
// }

// static void	*always_null(void *ptr)
// {
// 	(void)ptr;
// 	return (NULL);
// }

// static size_t	lst_size(t_list *lst)
// {
// 	size_t	count;

// 	count = 0;
// 	while (lst)
// 	{
// 		count++;
// 		lst = lst->next;
// 	}
// 	return (count);
// }

// static void	free_str(void *ptr)
// {
// 	free(ptr);
// }

// static void	test_ft_lstmap_null(void)
// {
// 	assert(ft_lstmap(NULL, str_dup, free_str) == NULL);
// }

// static void	test_ft_lstmap_single(void)
// {
// 	t_list	*src;
// 	t_list	*dup;

// 	src = ft_lstnew(strdup("42"));
// 	dup = ft_lstmap(src, str_dup, free_str);
// 	assert(dup && dup->next == NULL);
// 	assert(strcmp(dup->content, "42") == 0);
// 	assert(dup->content != src->content);
// 	ft_lstclear(&src, free_str);
// 	ft_lstclear(&dup, free_str);
// }

// static void	test_ft_lstmap_multiple(void)
// {
// 	t_list	*src;
// 	t_list	*dup;

// 	src = ft_lstnew(strdup("hello"));
// 	ft_lstadd_back(&src, ft_lstnew(strdup("world")));
// 	dup = ft_lstmap(src, str_dup, free_str);
// 	assert(lst_size(dup) == 2);
// 	assert(strcmp(dup->content, "hello") == 0);
// 	assert(strcmp(dup->next->content, "world") == 0);
// 	assert(dup->content != src->content);
// 	assert(dup->next->content != src->next->content);
// 	ft_lstclear(&src, free_str);
// 	ft_lstclear(&dup, free_str);
// }

// static void	test_ft_lstmap_null_content(void)
// {
// 	t_list	*src;
// 	t_list	*dup;

// 	src = ft_lstnew(strdup("x"));
// 	dup = ft_lstmap(src, always_null, free_str);
// 	assert(dup && dup->content == NULL);
// 	ft_lstclear(&src, free_str);
// 	ft_lstclear(&dup, free_str);
// }

// static void	test_ft_lstmap_large(void)
// {
// 	t_list	*src;
// 		char buf[8];
// 	t_list	*dup;

// 	src = NULL;
// 	for (size_t i = 0; i < 1000; ++i)
// 	{
// 		snprintf(buf, sizeof(buf), "%zu", i);
// 		ft_lstadd_back(&src, ft_lstnew(strdup(buf)));
// 	}
// 	dup = ft_lstmap(src, str_dup, free_str);
// 	assert(lst_size(dup) == 1000);
// 	ft_lstclear(&src, free_str);
// 	ft_lstclear(&dup, free_str);
// }

// int	main(void)
// {
// 	test_ft_lstmap_null();
// 	test_ft_lstmap_single();
// 	test_ft_lstmap_multiple();
// 	test_ft_lstmap_null_content();
// 	test_ft_lstmap_large();
// 	puts("ft_lstmap: all tests passed");
// 	return (0);
// }

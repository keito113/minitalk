/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:03:21 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/06 18:14:29 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>

// static void	print_result(const char *label, t_list *node)
// {
// 	printf("%s ⇒ ", label);
// 	if (node == NULL)
// 		printf("(NULL)\n");
// 	else
// 		printf("\"%s\"  @ %p\n", (char *)node->content, (void *)node);
// }

// int	main(void)
// {
// 	t_list	*empty;
// 	t_list	*one;
// 	t_list	*a;
// 	t_list	*b;
// 	t_list	*c;

// 	empty = NULL;
// 	print_result("Empty list", ft_lstlast(empty));
// 	one = ft_lstnew("42");
// 	print_result("Single node", ft_lstlast(one));
// 	a = ft_lstnew("a");
// 	b = ft_lstnew("b");
// 	c = ft_lstnew("c");
// 	a->next = b;
// 	b->next = c;
// 	print_result("Head-first  (a→b→c)", ft_lstlast(a));
// 	print_result("Mid-start  (b→c)", ft_lstlast(b));
// 	free(one);
// 	free(a);
// 	free(b);
// 	free(c);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:54:35 by keitabe           #+#    #+#             */
/*   Updated: 2025/05/06 20:09:29 by keitabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next_node;

	if (!lst || !f)
		return ;
	while (lst)
	{
		next_node = lst->next;
		f(lst->content);
		lst = next_node;
	}
}

// #include "libft.h"
// #include <assert.h>
// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// static t_list	*new_node(void *content)
// {
// 	t_list	*node;

// 	node = (t_list *)malloc(sizeof(t_list));
// 	if (!node)
// 		return (NULL);
// 	node->content = content;
// 	node->next = NULL;
// 	return (node);
// }

// static void	add_back(t_list **lst, t_list *new)
// {
// 	t_list	*cur;

// 	if (!lst || !new)
// 		return ;
// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	cur = *lst;
// 	while (cur->next)
// 		cur = cur->next;
// 	cur->next = new;
// }

// static void	free_all(t_list **lst, int is_str)
// {
// 	t_list	*tmp;

// 	while (lst && *lst)
// 	{
// 		tmp = (*lst)->next;
// 		if (is_str)
// 			free((*lst)->content);
// 		else
// 			free((*lst)->content);
// 		free(*lst);
// 		*lst = tmp;
// 	}
// }

// static void	increment_int(void *p)
// {
// 	int	*n;

// 	n = (int *)p;
// 	*n += 1;
// }

// static void	uppercase_str(void *p)
// {
// 	char	*s;

// 	s = (char *)p;
// 	while (*s)
// 	{
// 		*s = (char)toupper((unsigned char)*s);
// 		s++;
// 	}
// }

// static void	test_ft_lstiter_case01(void)
// {
// 	t_list	*lst;
// 	int		*a;
// 	int		*b;
// 	int		*c;

// 	lst = NULL;
// 	a = malloc(sizeof(int));
// 	b = malloc(sizeof(int));
// 	c = malloc(sizeof(int));
// 	*a = 1;
// 	*b = 2;
// 	*c = 3;
// 	add_back(&lst, new_node(a));
// 	add_back(&lst, new_node(b));
// 	add_back(&lst, new_node(c));
// 	ft_lstiter(lst, increment_int);
// 	assert(*((int *)lst->content) == 2);
// 	assert(*((int *)lst->next->content) == 3);
// 	assert(*((int *)lst->next->next->content) == 4);
// 	free_all(&lst, 0);
// }

// static void	test_ft_lstiter_case02(void)
// {
// 	t_list	*lst;
// 	char	*str;

// 	lst = NULL;
// 	str = strdup("abc");
// 	add_back(&lst, new_node(str));
// 	ft_lstiter(lst, uppercase_str);
// 	assert(strcmp((char *)lst->content, "ABC") == 0);
// 	free_all(&lst, 1);
// }

// static void	test_ft_lstiter_case03(void)
// {
// 	ft_lstiter(NULL, increment_int);
// 	assert(1);
// }

// static void	test_ft_lstiter_case04(void)
// {
// 	t_list	*lst;
// 	int		*x;
// 	int		*y;

// 	lst = NULL;
// 	x = malloc(sizeof(int));
// 	y = malloc(sizeof(int));
// 	*x = 5;
// 	*y = 6;
// 	add_back(&lst, new_node(x));
// 	add_back(&lst, new_node(y));
// 	ft_lstiter(lst, NULL);
// 	assert(*((int *)lst->content) == 5);
// 	assert(*((int *)lst->next->content) == 6);
// 	free_all(&lst, 0);
// }

// int	main(void)
// {
// 	test_ft_lstiter_case01();
// 	test_ft_lstiter_case02();
// 	test_ft_lstiter_case03();
// 	test_ft_lstiter_case04();
// 	printf("✅ All ft_lstiter tests passed!\n");
// 	return (0);
// }

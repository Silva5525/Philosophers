/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:11:15 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 16:14:49 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Allocates (with malloc(3)) and returns a new node.
/// The member variable ’content’ is initialized with
/// the value of the parameter ’content’. The variable
/// ’next’ is initialized to NULL.
/// @param content content for the new node.
/// @return the new node
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	if (new_node)
	{
		new_node -> content = content;
		new_node -> next = NULL;
	}
	return (new_node);
}

// #include <stdio.h>
// void	print_list(t_list *head)
// {
// 	t_list *current = head;
// 	while (current != NULL)
// 	{
// 		printf("%d -> ", *((int *)current -> content));
// 		current = current->next;
// 	}
// 	printf("NULL\n");
// }
// int	main(void)
// {
// 	t_list 		*head = NULL;
// 	int 		data1 = 42;
// 	int			data2 = 23;
// 	int 		data3 = 48;
// 	t_list *node1 = ft_lstnew(&data1);
// 	t_list *node2 = ft_lstnew(&data2);
// 	t_list *node3 = ft_lstnew(&data3);
// 	node1->next = node2;
// 	node2->next = node3;
// 	head = node1;
// 	print_list(head);
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return (0);
// }

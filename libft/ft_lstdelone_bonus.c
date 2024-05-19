/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:55:12 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 15:46:39 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Takes as a parameter a node and frees the memory of
/// the node’s content using the function ’del’ given
/// as a parameter and free the node. The memory of
/// ’next’ must not be freed.
/// @param lst the pointer to the node to free
/// @param del the function to free the node
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	if (lst -> content != NULL && del != NULL )
	{
		del(lst -> content);
	}
	free(lst);
}

// #include <stdio.h>
// void	print_list(t_list *head)
// {
// 	t_list *current = head;
// 	if (head == NULL)
// 		printf("NULL\n");
// 	while (current != NULL){
// 		printf("%d -> ", *((int *)current -> content));
// 		current = current->next;
// 	}
// 	printf("NULL\n");
// }

// void dele(void *del_c)
// {
//     free(del_c);
// }

// int main(void)
// {
//     t_list *head = NULL;
//     int *data1;
//     int *data2;
//     int *data3;
// 	data1 = (int *)malloc(sizeof(int));
// 	data2 = (int *)malloc(sizeof(int));
// 	data3 = (int *)malloc(sizeof(int));
// 	*data1 = 42;
// 	*data2 = 23;
// 	*data3 = 48;
//     t_list *node1 = ft_lstnew(data1);
//     t_list *node2 = ft_lstnew(data2);
//     t_list *node3 = ft_lstnew(data3);
//     node1->next = node2;
//     node2->next = node3;
//     head = node1;
//     print_list(head);
//     void (*del)(void *) = dele;
//     ft_lstdelone(head, del);
//     printf("Linked List after clearing: ");
//     print_list(head);
//     return (0);
// }

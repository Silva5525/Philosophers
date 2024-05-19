/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:04:32 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 15:46:19 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Deletes and frees the given node and every
/// successor of that node, using the function ’del’
/// and free(3).
/// Finally, the pointer to the list must be set to NULL.
/// @param lst The address of a pointer to a node.
/// @param del The address of the function used to delete
/// the content of the node lst.
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*hold;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		hold = *lst;
		*lst = (*lst)->next;
		if (hold -> content && del)
			del(hold -> content);
		free(hold);
	}
	*lst = NULL;
}

// #include <stdio.h>
// void	print_list(t_list *head)
// {
// 	t_list *current = head;
// 		if (head == NULL)
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
//     ft_lstclear(&head, del);
//     printf("Linked List after clearing: ");
//     print_list(head);
//     free(node1);
//     free(node2);
//     free(node3);
//     return (0);
// }

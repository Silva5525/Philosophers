/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:36:41 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 16:12:19 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Iterates the list ’lst’ and applies the function
/// ’f’ on the content of each node. Creates a new
/// list resulting of the successive applications of
/// the function ’f’. The ’del’ function is used to
/// delete the content of a node if needed.
/// @param lst The address of a pointer to a node.
/// @param f pointer to a function (f)
/// @param del pointer to a delete function if needed (del)
/// @return The new list. NULL if the allocation fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	void	*temp;

	new = NULL;
	head = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		temp = f(lst -> content);
		new = ft_lstnew(temp);
		if (!new)
		{
			free(temp);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back (&head, new);
		lst = lst -> next;
	}
	return (head);
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

// void *print_content(void *content) {
//     printf("%c\n", *((char *)content));
// 	return (content);
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
// 	*data1 = 36;
// 	*data2 = 36;
// 	*data3 = 36;
//     t_list *node1 = ft_lstnew(data1);
//     t_list *node2 = ft_lstnew(data2);
//     t_list *node3 = ft_lstnew(data3);
//     node1->next = node2;
//     node2->next = node3;
//     head = node1;
//     print_list(head);
//     void (*del)(void *) = dele;
// 	void *(*f)(void *) = print_content;
//     ft_lstmap(head, f, del);
//     printf("Linked List after all: ");
//     print_list(head);
//     free(node1);
//     free(node2);
//     free(node3);
//     return (0);
// }

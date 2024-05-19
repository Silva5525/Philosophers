/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:04:52 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 15:50:17 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/// @brief Iterates the list ’lst’ and applies the function
/// ’f’ on the content of each node.
/// @param lst The address of a pointer to a node.
/// @param f The address of the function used to iterate on the list
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

// #include <stdio.h>
// void print_content(void *content) {
//     printf("%c\n", *((char *)content));
// }
// int main(void) {
//     t_list *head = NULL;
//     int data1 = 36;
//     int data2 = 36;
//     int data3 = 36;
//     t_list *node1 = ft_lstnew(&data1);
//     t_list *node2 = ft_lstnew(&data2);
//     t_list *node3 = ft_lstnew(&data3);
//     node1->next = node2;
//     node2->next = node3;
//     head = node1;
//     printf("Linked List before applying ft_lstiter:\n");
//     t_list *current = head;
//     while (current != NULL) {
//         printf("%d -> ", *((int *)current->content));
//         current = current->next;
//     }
//     printf("NULL\n");
//     void (*f)(void *) = print_content;
//     ft_lstiter(head, f);
//     return 0;
// }

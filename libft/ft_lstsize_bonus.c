/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:40:07 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/28 13:32:34 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Counts the number of nodes in a list
/// @param lst The beginning of the list
/// @return The length of the list
int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*current;

	size = 0;
	current = lst;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list 		*head = NULL;
// 	int 		data1 = 42;
// 	int			data2 = 23;
// 	int 		data3 = 48;
// 	int			size;
// 	t_list *node1 = ft_lstnew(&data1);
// 	t_list *node2 = ft_lstnew(&data2);
// 	t_list *node3 = ft_lstnew(&data3);
// 	node1->next = node2;
// 	node2->next = node3;
// 	head = node1;
// 	size = ft_lstsize(head);
// 	printf("Size is %i\n", size);
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return (0);
// }

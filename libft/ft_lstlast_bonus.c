/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:05:06 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 16:09:42 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief shows the last node of lst
/// @param lst the list pointer
/// @return the last node (end) of the lst
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*end;

	end = lst;
	if (lst == NULL)
		return (NULL);
	while (end -> next != NULL)
	{
		end = end -> next;
	}
	return (end);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list 		*head = NULL;
// 	int 		data1 = 42;
// 	int			data2 = 23;
// 	int 		data3 = 48;
// 	t_list		*end;
// 	t_list *node1 = ft_lstnew(&data1);
// 	t_list *node2 = ft_lstnew(&data2);
// 	t_list *node3 = ft_lstnew(&data3);
// 	node1->next = node2;
// 	node2->next = node3;
// 	head = node1;
// 	end = ft_lstlast(head);
// 	printf("end is %i\n", *((int *)end->content));
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return (0);
// }

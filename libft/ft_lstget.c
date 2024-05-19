/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:17:26 by wdegraf           #+#    #+#             */
/*   Updated: 2024/05/10 15:52:08 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Gets the index-th element of the list.
/// @param lst the beginning of the list
/// @param index the index of the element to get
/// @return the index-th element of the list. NULL if the index is out of range.
t_list	*ft_lstget(t_list *lst, int index)
{
	if (index < 0 || !lst)
		return (NULL);
	while (index-- && lst)
		lst = lst->next;
	return (lst);
}

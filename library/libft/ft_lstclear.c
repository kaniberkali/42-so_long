/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:45:29 by akaniber          #+#    #+#             */
/*   Updated: 2022/10/10 11:49:25 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	size_t	counter;
	t_list	*temp;

	counter = 0;
	while (lst[counter] != NULL)
	{
		temp = lst[counter];
		lst[counter] = lst[counter]->next;
		del(temp->content);
		free(temp);
	}
}

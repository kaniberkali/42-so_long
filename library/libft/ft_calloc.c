/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:41:49 by akaniber          #+#    #+#             */
/*   Updated: 2022/10/09 17:01:28 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	length;

	length = count * size;
	ptr = (void *)malloc(length);
	if (ptr != NULL)
		ft_bzero(ptr, length);
	else
		return (NULL);
	return (ptr);
}

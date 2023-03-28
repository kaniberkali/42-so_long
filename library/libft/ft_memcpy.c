/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:41:56 by akaniber          #+#    #+#             */
/*   Updated: 2022/10/11 15:42:51 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_new;
	unsigned char	*src_new;
	size_t			counter;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_new = (unsigned char *)dst;
	src_new = (unsigned char *)src;
	counter = 0;
	while (counter < n)
	{
		dst_new[counter] = src_new[counter];
		counter++;
	}
	return (dst);
}

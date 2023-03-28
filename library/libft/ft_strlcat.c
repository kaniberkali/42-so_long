/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:06:56 by akaniber          #+#    #+#             */
/*   Updated: 2022/10/12 17:31:31 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	dst_length;
	size_t	src_length;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen((char *)src);
	if (dstsize <= dst_length)
		return (dstsize + src_length);
	counter = 0;
	while (src[counter] != '\0' && dstsize > (dst_length + 1))
	{
		dst[dst_length] = src[counter];
		counter++;
		dst_length++;
	}
	dst[dst_length] = '\0';
	return (dst_length + ft_strlen((char *)(&src[counter])));
}

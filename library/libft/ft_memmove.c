/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:34:24 by akaniber          #+#    #+#             */
/*   Updated: 2022/10/09 15:59:37 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_new;
	unsigned char	*src_new;

	if ((dst == NULL) && (src == NULL))
		return (NULL);
	dst_new = (unsigned char *)dst;
	src_new = (unsigned char *)src;
	i = 1;
	if (src_new < dst_new)
	{
		while (i <= len)
		{
			dst_new[len - i] = src_new[len - i];
			i++;
		}
	}
	else
		ft_memcpy(dst_new, src_new, len);
	return (dst);
}

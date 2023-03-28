/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:31:18 by akaniber          #+#    #+#             */
/*   Updated: 2022/10/13 11:30:18 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	q;

	if (needle[0] == '\0')
		return ((char *)&haystack[0]);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		q = 0;
		while ((haystack[i + q] == needle[q]) && (i + q) < len)
		{
			if (needle[q + 1] == '\0')
				return ((char *)(&haystack[i]));
			q++;
		}
		i++;
	}
	return (0);
}

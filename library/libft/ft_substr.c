/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:12:53 by akaniber          #+#    #+#             */
/*   Updated: 2022/10/13 12:11:03 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	length;

	if (s == NULL)
		return (NULL);
	length = ft_strlen((char *)s);
	if (start > length)
		return (ft_strdup(""));
	if (length - start >= len)
		result = (char *)malloc((len + 1) * sizeof(char));
	else
		result = (char *)malloc((length - start + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, (char *)&s[start], (len + 1));
	return (result);
}

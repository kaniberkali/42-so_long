/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:01:44 by akaniber          #+#    #+#             */
/*   Updated: 2022/10/09 16:27:48 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*result;

	length = ft_strlen((char *)s1);
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, length);
	result[length] = '\0';
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:58:58 by akaniber          #+#    #+#             */
/*   Updated: 2022/10/09 16:03:17 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	letter;
	unsigned char	*str;
	size_t			counter;

	counter = 0;
	letter = (unsigned char)c;
	str = (unsigned char *)s;
	while (counter < n)
	{
		if (str[counter] == letter)
			return ((void *)(&str[counter]));
		counter++;
	}
	return (0);
}

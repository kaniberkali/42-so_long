/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:44:25 by akaniber          #+#    #+#             */
/*   Updated: 2022/10/09 15:21:29 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		lastletter;
	int		counter;
	char	letter;

	counter = 0;
	letter = (unsigned char)c;
	lastletter = -1;
	while (s[counter] != '\0')
	{
		if (s[counter] == letter)
			lastletter = counter;
		counter++;
	}
	if (lastletter != -1)
		return ((char *)&s[lastletter]);
	if (c == '\0')
		return ((char *)&s[counter]);
	return (0);
}

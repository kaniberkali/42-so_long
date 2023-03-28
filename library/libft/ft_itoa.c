/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:47:56 by akaniber          #+#    #+#             */
/*   Updated: 2022/10/11 15:52:21 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_nbr_length(int nbr)
{
	int	counter;

	counter = 0;
	while (nbr > 9)
	{
		counter++;
		nbr /= 10;
	}
	return (counter);
}

static	int	calc_nbr_length(int length)
{
	int	result;

	result = 1;
	while (length > 0)
	{
		result *= 10;
		length--;
	}
	return (result);
}

static	int	get_sign(int *sign, int n)
{
	int	sign_result;

	sign_result = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n = -147483648;
			sign_result++;
		}
		n = -n;
		sign_result++;
	}
	*sign = sign_result;
	return (n);
}

static	void	write_zeros(int n, char *result, int *index)
{
	int	counter_res;
	int	length;

	counter_res = *index;
	length = get_nbr_length(n);
	while (length >= 0)
	{
		result[counter_res] = '0';
		counter_res++;
		length--;
	}
	*index = counter_res;
}

char	*ft_itoa(int n)
{
	int		calc_nbr;
	char	*result;
	int		sign;
	int		counter;

	n = get_sign(&sign, n);
	result = (char *)malloc(sizeof(char) * (get_nbr_length(n) + sign + 1));
	calc_nbr = calc_nbr_length(get_nbr_length(n));
	counter = 0;
	if (sign > 0)
	{
		result[counter++] = '-';
		if (sign == 2)
			result[counter++] = '2';
	}
	while (n != 0)
	{
		result[counter++] = (n / calc_nbr) + 48;
		n %= calc_nbr;
		calc_nbr /= 10;
	}
	if (calc_nbr != 0)
		write_zeros(calc_nbr, result, &counter);
	result[counter] = '\0';
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <mait-oub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:05:31 by mait-oub          #+#    #+#             */
/*   Updated: 2025/04/06 01:20:12 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long double	ft_strtold(const char *str, char **endptr)
{
	int			sign;
	long double	result;
	long double	fraction;

	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	fraction = 0.0L;
	result = 0.0L;
	while (ft_isdigit(*str) || (*str == '.' && !fraction))
	{
		if (*str == '.')
			fraction = 0.1L;
		else if (fraction)
		{
			result += (*str - '0') * fraction;
			fraction *= 0.1L;
		}
		else
			result = result * 10.0L + (*str - '0');
		str++;
	}
	return (*endptr = (char *) str, sign * result);
}

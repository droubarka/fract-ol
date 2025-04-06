/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:44:55 by mait-oub          #+#    #+#             */
/*   Updated: 2025/02/27 23:44:56 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
t_ldouble	map_value(t_ldouble x, t_ldouble *from, t_ldouble *to)
{
	return (to[0] + (x - from[0]) * (to[1] - to[0]) / (from[1] - from[0]));
}
*/

t_ldouble	map_value(t_ldouble x, t_ldouble size, t_ldouble *to)
{
	return (to[0] + x * (to[1] - to[0]) / size);
}

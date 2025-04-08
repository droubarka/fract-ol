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
t_ldouble	map_value(t_ldouble value, t_ldouble *from, t_ldouble *to)
{
	t_ldouble	old_range;
	t_ldouble	new_range;
	t_ldouble	new_value;

	old_range = from[1] - from[0];
	new_range = to[1] - to[0];
	new_value = ((value - from[0]) * new_range) / old_range + to[0];
	return (new_value);
}
*/

t_ldouble	map_value(t_ldouble value, t_ldouble old_range, t_ldouble *to)
{
	t_ldouble	new_range;
	t_ldouble	new_value;

	new_range = to[1] - to[0];
	new_value = (value * new_range) / old_range + to[0];
	return (new_value);
}

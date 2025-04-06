/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:45:52 by mait-oub          #+#    #+#             */
/*   Updated: 2025/02/27 15:45:54 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef long double			t_ldouble;
typedef struct s_complex	t_complex;

struct s_complex
{
	t_ldouble	real;
	t_ldouble	imag;
};

/* libc */
int	ft_isdigit(int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

size_t ft_strlen(const char *s);

long double	ft_strtold(const char *str, char **endptr);

/* other */
void	error(const char *errmsg);
void	usage_error(int nargs);

int	init_julia_params(t_complex *julia_params, char **av);

t_ldouble	map_value(t_ldouble x, t_ldouble size, t_ldouble *to);

#endif

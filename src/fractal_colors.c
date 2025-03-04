/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:29:49 by mait-oub          #+#    #+#             */
/*   Updated: 2025/03/04 05:57:01 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	get_color(t_fractal *fractal, int iter)
{
	unsigned char r, g, b;

	double t = ((double)iter + fractal->graph.color) / fractal->graph.iterations;

	r = (unsigned char)(9 * (1 - t) * t * t * t * 255);
	g = (unsigned char)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (unsigned char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

	return (r << 16 | g << 8 | b);
}

/*
int dget_color2(t_fractal *fractal, int iter) {
    unsigned char r, g, b;
    if (iter == fractal->graph.iterations) {
        // Inside the Mandelbrot set (black)
        r = 0;
        g = 0;
        b = 0;
    } else {
        // Outside the Mandelbrot set (lava-like color based on iterations)
        double t = ((double)iter + fractal->graph.color) / fractal->graph.iterations;

        // Lava color gradient
        r = (unsigned char)(255 * (0.8 + 0.2 * sin(t * 10))); // Bright red with variation
        g = (unsigned char)(128 * t * t);                    // Orange/yellow tones
        b = (unsigned char)(64 * t * t * t);                 // Darker tones for depth

        // Add some cooling effect (darker tones for lower iterations)
        if (t < 0.5) {
            r = (unsigned char)(r * t * 2);                  // Darker red for cooler areas
            g = (unsigned char)(g * t * 2);                  // Darker orange for cooler areas
        }
    }
    return (r << 16 | g << 8 | b);
}
*/

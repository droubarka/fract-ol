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

typedef struct {
    unsigned char r, g, b; // RGB values in range [0, 255]
} color;

typedef color Color;

// Function to initialize the mapping array
void initializeMapping(color mapping[], int size) {
    // Manually set the RGB values for each color in the mapping array
    mapping[0] = (Color){66, 30, 15};
    mapping[1] = (Color){25, 7, 26};
    mapping[2] = (Color){9, 1, 47};
    mapping[3] = (Color){4, 4, 73};
    mapping[4] = (Color){0, 7, 100};
    mapping[5] = (Color){12, 44, 138};
    mapping[6] = (Color){24, 82, 177};
    mapping[7] = (Color){57, 125, 209};
    mapping[8] = (Color){134, 181, 229};
    mapping[9] = (Color){211, 236, 248};
    mapping[10] = (Color){241, 233, 191};
    mapping[11] = (Color){248, 201, 95};
    mapping[12] = (Color){255, 170, 0};
    mapping[13] = (Color){204, 128, 0};
    mapping[14] = (Color){153, 87, 0};
    mapping[15] = (Color){106, 52, 3};
}

// Function to get a color from the mapping array
Color getColor(Color mapping[], int i) {
    return mapping[i];
}


typedef struct {
    float r, g, b;
} QColor;

float _clamp(float min, float max, float value) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

#define MAX_ITERATIONS 30

QColor QColor_mapping(int n) {
    QColor mapping = {1.0f, 1.0f, 1.0f}; // Qt::white equivalent

        double quotient = (double)n / (double)MAX_ITERATIONS;
        double color = _clamp(0.0f, 1.0f, (float)quotient);

        if (quotient > 0.5) {
            // Close to the Mandelbrot set, the color changes from green to white
            mapping.r = (float)color;
            mapping.g = 1.0f;
            mapping.b = (float)color;
        } else {
            // Far away, it changes from black to green
            mapping.r = 0.0f;
            mapping.g = 0.0f;
            mapping.b = (float)color;
        }

    return mapping;
}

int	gxxet_color(t_fractal *fractal, int iterations)
{
    QColor color = QColor_mapping(iterations);
//	printf("%f,%f,%f\n", color.r, color.g, color.b);
//    printf("%x\n", (int)(color.r * 65536) | (int)(color.g * 256) | (int)(color.b * 2));
    return ((int)(color.r * 65536) | (int)(color.g * 256) | (int)(color.b * 2));
}

int	dddget_color(t_fractal *fractal, int iterations)
{
	color mapping[16];

	initializeMapping(mapping, 16);
	color color = mapping[iterations];
	return (color.r << 16 | color.g << 8 | color.b);
}

int	get_color(t_fractal *fractal, int iterations)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	double	t;

	if (iterations == fractal->graph.iterations)
		return (0x0);

	t = ((double) iterations + fractal->graph.color) / fractal->graph.iterations;

	r = (unsigned char) (9 * (1 - t) * t * t * t * 255);
	g = (unsigned char) (15 * (1 - t) * (1 - t) * t * t * 255);
	b = (unsigned char) (8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

	return (r << 16 | g << 8 | b);
}

int xxxxxxxxxxget_color(t_fractal *fractal, int iter) {
    unsigned char r, g, b;
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
    return (r << 16 | g << 8 | b);
}

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
/*
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

int	gxxxxxxxxxxxxxxet_color(t_fractal *fractal, int iterations)
{
    QColor color = QColor_mapping(iterations);
//	printf("%f,%f,%f\n", color.r, color.g, color.b);
//    printf("%x\n", (int)(color.r * 65536) | (int)(color.g * 256) | (int)(color.b * 2));
    return ((int)(color.r * 65536) | (int)(color.g * 256) | (int)(color.b * 2));
}

int	xxxxxxxxxxxxxxxxget_color(t_fractal *fractal, int iterations)
{
	color mapping[16];

	initializeMapping(mapping, 16);
	color color = mapping[iterations];
	return (color.r << 16 | color.g << 8 | color.b);
}







#include <stdio.h>
#include <stdlib.h>

#define NUM_POINTS 8
#define NUM_INTERPOLATED 1000

// Linear interpolation function
double linear_interpolate(double x0, double y0, double x1, double y1, double x) {
    return y0 + (y1 - y0) * (x - x0) / (x1 - x0);
}

// Function to perform interpolation
void interpolate(double *x_observed, double *y_observed, double *x, double *y, int num_points, int num_interp) {
    int j = 0;
    for (int i = 0; i < num_interp; i++) {
        while (j < num_points - 1 && x[i] > x_observed[j + 1]) {
            j++;
        }
        y[i] = linear_interpolate(x_observed[j], y_observed[j], x_observed[j + 1], y_observed[j + 1], x[i]);
    }
}

int	xxxxxxxxxxxxxget_color(t_fractal *fractal, int iterations)
{
    // Observed control points
    double x_observed[NUM_POINTS] = {-0.1425, 0, 0.16, 0.42, 0.6425, 0.8575, 1, 1.16};
    double yR_observed[NUM_POINTS] = {0, 0, 32, 237, 255, 0, 0, 32};
    double yG_observed[NUM_POINTS] = {2, 7, 107, 255, 170, 2, 7, 107};
    double yB_observed[NUM_POINTS] = {0, 100, 203, 255, 0, 0, 100, 203};

    // Interpolated x values
    double x[NUM_INTERPOLATED];
    double step = (x_observed[NUM_POINTS - 1] - x_observed[0]) / (NUM_INTERPOLATED - 1);
    
    for (int i = 0; i < NUM_INTERPOLATED; i++) {
        x[i] = x_observed[0] + i * step;
    }

    // Interpolated y values
    double yR[NUM_INTERPOLATED], yG[NUM_INTERPOLATED], yB[NUM_INTERPOLATED];
    
    interpolate(x_observed, yR_observed, x, yR, NUM_POINTS, NUM_INTERPOLATED);
    interpolate(x_observed, yG_observed, x, yG, NUM_POINTS, NUM_INTERPOLATED);
    interpolate(x_observed, yB_observed, x, yB, NUM_POINTS, NUM_INTERPOLATED);

    // Find indices where x crosses 0 and 1
    int start = 0, end = NUM_INTERPOLATED;
    for (int i = 0; i < NUM_INTERPOLATED; i++) {
        if (x[i] >= 0) {
            start = i;
            break;
        }
    }
    for (int i = 0; i < NUM_INTERPOLATED; i++) {
        if (x[i] > 1) {
            end = i;
            break;
        }
    }

    // Print the values within the range 0 to 1
    printf("Interpolated Values (x, yR, yG, yB):\n");
    for (int i = start; i < end; i++) {
        printf("%f, %f, %f, %f\n", x[i], yR[i], yG[i], yB[i]);
    }

    return 0;
}
*/







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

/*
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
*/


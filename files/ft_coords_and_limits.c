/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coords_and_limits.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:20:48 by dpadovan          #+#    #+#             */
/*   Updated: 2021/10/31 00:34:55 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Function to verify every pixel one by one and calculate viewport
//Pointer to function as required (Mandelbrot or Julia)
//Function to print the pixel

void	ft_coords(t_vars *vars)
{
	vars->coord.win_pos_h = 0;
	while (vars->coord.win_pos_h < HEIGHT)
	{	
		vars->coord.win_pos_w = 0;
		while (vars->coord.win_pos_w < WIDTH)
		{
			ft_win_to_viewport(vars);
			vars->ft_calc(vars);
			ft_my_print_pixel(vars);
			vars->coord.win_pos_w++;
		}
		vars->coord.win_pos_h++;
	}
}

//Function to initialize min and max of virtual coordinates
void	ft_set_limits(t_vars *vars)
{
	if (vars->fract.fract_number == 1)
	{
		vars->coord.x_vmax = 1.0;
		vars->coord.x_vmin = -2.0;
		vars->coord.y_vmax = 1.1;
		vars->coord.y_vmin = -1.1;
	}
	else if (vars->fract.fract_number == 2)
	{
		vars->coord.x_vmax = 2.0;
		vars->coord.x_vmin = -2.0;
		vars->coord.y_vmax = 2.0;
		vars->coord.y_vmin = -2.0;
	}
	else if (vars->fract.fract_number == 3)
	{
		vars->coord.x_vmax = 2.0;
		vars->coord.x_vmin = -2.0;
		vars->coord.y_vmax = 2.0;
		vars->coord.y_vmin = -2.0;
	}
}

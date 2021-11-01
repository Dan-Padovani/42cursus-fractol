/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:04:20 by dpadovan          #+#    #+#             */
/*   Updated: 2021/10/31 00:54:17 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot_calc(t_vars *vars)
{
	vars->coord.zx = 0;
	vars->coord.zy = 0;
	vars->coord.xx = 0;
	vars->coord.yy = 0;
	vars->coord.temp = 0;
	vars->coord.iter = 0;
	while (vars->coord.xx + vars->coord.yy < 4 && vars->coord.iter < MAX_ITER)
	{
		vars->coord.zx = vars->coord.xx - vars->coord.yy + vars->coord.x_viewp;
		vars->coord.zy = (vars->coord.temp - vars->coord.xx - vars->coord.yy)
			+ vars->coord.y_viewp;
		vars->coord.xx = vars->coord.zx * vars->coord.zx;
		vars->coord.yy = vars->coord.zy * vars->coord.zy;
		vars->coord.temp = (vars->coord.zx + vars->coord.zy) * (vars->coord.zx
				+ vars->coord.zy);
		vars->coord.iter++;
	}
}

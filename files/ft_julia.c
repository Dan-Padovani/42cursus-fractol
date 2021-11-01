/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:59:22 by dpadovan          #+#    #+#             */
/*   Updated: 2021/10/31 18:47:19 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia_calc(t_vars *vars)
{
	vars->coord.xx = 0;
	vars->coord.yy = 0;
	vars->coord.zx = vars->coord.x_viewp;
	vars->coord.zy = vars->coord.y_viewp;
	vars->coord.iter = 0;
	while (vars->coord.xx + vars->coord.yy < 4 && vars->coord.iter < MAX_ITER)
	{
		vars->coord.xx = vars->coord.zx * vars->coord.zx;
		vars->coord.yy = vars->coord.zy * vars->coord.zy;
		vars->coord.zx = vars->coord.xx - vars->coord.yy + vars->fract.julia_px;
		vars->coord.zy = 2 * vars->coord.zx * vars->coord.zy
			+ vars->fract.julia_py * -1;
		vars->coord.iter++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_to_viewport.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:54:11 by dpadovan          #+#    #+#             */
/*   Updated: 2021/10/27 22:31:05 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_win_to_viewport(t_vars *vars)
{
	vars->coord.sf_x = (double)(vars->coord.x_vmax - vars->coord.x_vmin)
		/ WIDTH;
	vars->coord.sf_y = (double)(vars->coord.y_vmax - vars->coord.y_vmin)
		/ HEIGHT;
	vars->coord.x_viewp = vars->coord.x_vmin + (double)((vars->coord.win_pos_w)
			* vars->coord.sf_x);
	vars->coord.y_viewp = vars->coord.y_vmin + (double)((vars->coord.win_pos_h)
			* vars->coord.sf_y);
}

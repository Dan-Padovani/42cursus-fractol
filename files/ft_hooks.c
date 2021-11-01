/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:19:26 by dpadovan          #+#    #+#             */
/*   Updated: 2021/11/01 10:45:35 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*	My hook function from minilibx to call the events on pressed buttons
*	ESC to close the window
*	R to reset and set original limits of the image
*	Arrow UP DOWN RIGHT LEFT to move the image
*/

int	ft_key_hook(int keycode, t_vars *vars)
{
	double	delta_x;
	double	delta_y;

	delta_x = vars->coord.x_vmax - vars->coord.x_vmin;
	delta_y = vars->coord.y_vmax - vars->coord.y_vmin;
	if (keycode == ESC)
		ft_close_clean(vars);
	if (keycode == R)
		ft_reset(vars);
	if (keycode == UP || keycode == LEFT || keycode == DOWN || keycode == RIGHT)
		ft_move_img(keycode, vars, delta_x, delta_y);
	return (0);
}

int	ft_key_hook_scroll(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == ZOOM_IN)
		ft_zoom(vars, x, y, keycode);
	if (keycode == ZOOM_OUT)
		ft_zoom(vars, x, y, keycode);
	ft_coords(vars);
	mlx_put_image_to_window(vars->img.mlx, vars->img.mlx_win,
		vars->img.img, 0, 0);
	return (0);
}

void	ft_reset(t_vars *vars)
{
	ft_set_limits(vars);
	ft_coords(vars);
	mlx_put_image_to_window(vars->img.mlx, vars->img.mlx_win,
		vars->img.img, 0, 0);
}

int	ft_refresh_image(t_vars *vars)
{
	mlx_put_image_to_window(vars->img.mlx, vars->img.mlx_win,
		vars->img.img, 0, 0);
	return (0);
}

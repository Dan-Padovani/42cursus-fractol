/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:55:40 by dpadovan          #+#    #+#             */
/*   Updated: 2021/10/27 21:07:33 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close_clean(t_vars *vars)
{
	mlx_destroy_image(vars->img.mlx, vars->img.img);
	mlx_clear_window(vars->img.mlx, vars->img.mlx_win);
	mlx_destroy_window(vars->img.mlx, vars->img.mlx_win);
	mlx_destroy_display(vars->img.mlx);
	free(vars->img.mlx);
	exit(0);
}

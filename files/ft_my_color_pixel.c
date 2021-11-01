/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_color_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:41:47 by dpadovan          #+#    #+#             */
/*   Updated: 2021/10/29 00:06:50 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_my_color_pixel(int iter)
{
	int		r;
	int		g;
	int		b;
	double	t;

	t = (double)log(iter) / log(MAX_ITER);
	r = 9 * (1 - t) * t * t * t * 255;
	g = 15 * (1 - t) * (1 - t) * t * t * 255;
	b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	return (r << 16 | g << 8 | b);
}

void	ft_my_print_pixel(t_vars *vars)
{
	char	*px;

	px = &vars->img.img_addr[vars->coord.win_pos_h * vars->img.line_length
		+ vars->coord.win_pos_w * 4];
	*(unsigned int *)px = ft_my_color_pixel(vars->coord.iter);
}

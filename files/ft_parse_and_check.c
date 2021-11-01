/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_and_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:16:21 by dpadovan          #+#    #+#             */
/*   Updated: 2021/10/27 22:24:47 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_msg(void)
{
	printf("\nAvailable Fractals: Mandelbrot, Burning Ship and Julia\n\n");
	printf("Please enter a valid input, follow the example:\n");
	printf("./fractol mandelbrot\n");
	printf("./fractol burning-ship\n\n");
	printf("For julia insert two points, follow the example:\n");
	printf("./fractol julia 0.355 0.355\n");
	printf("./fractol julia -0.4 +0.6\n");
	printf("./fractol julia -0.835 -0.2321\n");
	printf("./fractol julia -0.8 0.156\n\n");
	exit(0);
}

static int	ft_check_values(char *str, t_parse *parse)
{
	if (*str == '.')
	{
		parse->point++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		parse->nap++;
		str++;
	}
	if ((parse->point > 0 && parse->nap == 0) || (parse->signal > 0
			&& parse->nap == 0) || parse->nbp > 1)
		return (0);
	return ((parse->signal + parse->nbp + parse->point + parse->nap)
		== ft_strlen(parse->tmp));
}

int	ft_check_jvalues(char *str)
{
	t_parse	parse;

	parse.tmp = str;
	parse.signal = 0;
	parse.nbp = 0;
	parse.point = 0;
	parse.nap = 0;
	if (*str == '+' || *str == '-')
	{
		parse.signal++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (*str >= '0' && *str <= '2')
			parse.nbp++;
		str++;
	}
	return (ft_check_values(str, &parse));
}	

void	ft_check_args(int argc, char **argv, t_vars *vars)
{
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		vars->ft_calc = &ft_mandelbrot_calc;
		vars->fract.fract_number = 1;
	}
	else if (argc == 2 && ft_strcmp(argv[1], "burning-ship") == 0)
	{
		vars->ft_calc = &ft_burning_ship;
		vars->fract.fract_number = 2;
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		if (ft_check_jvalues(argv[2]) && ft_check_jvalues(argv[3]))
		{
			vars->fract.julia_px = ft_atof(argv[2]);
			vars->fract.julia_py = ft_atof(argv[3]);
			vars->ft_calc = &ft_julia_calc;
			vars->fract.fract_number = 3;
		}
		else
			ft_error_msg();
	}
	else
		ft_error_msg();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 12:29:18 by jflorimo          #+#    #+#             */
/*   Updated: 2014/05/10 12:29:19 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"
#include "libft.h"

void	draw_philo1(void *mlx, void *win, t_data *data)
{
	int	color;

	if (data[0].etat == 0)
		color = 0x00FF00;
	if (data[0].etat == 1)
		color = 0xFF0000;
	if (data[0].etat == 2)
		color = 0x00FFFF;
	mlx_string_put(mlx, win, 120, 30, color, "P1");
	mlx_string_put(mlx, win, 120, 40, color, ft_itoa(data[0].life));
}

void	draw_philo2(void *mlx, void *win, t_data *data)
{
	int	color;

	if (data[1].etat == 0)
		color = 0x00FF00;
	if (data[1].etat == 1)
		color = 0xFF0000;
	if (data[1].etat == 2)
		color = 0x00FFFF;
	mlx_string_put(mlx, win, 40, 70, color, "P2");
	mlx_string_put(mlx, win, 40, 80, color, ft_itoa(data[1].life));
}

void	draw_philo3(void *mlx, void *win, t_data *data)
{
	int	color;

	if (data[2].etat == 0)
		color = 0x00FF00;
	if (data[2].etat == 1)
		color = 0xFF0000;
	if (data[2].etat == 2)
		color = 0x00FFFF;
	mlx_string_put(mlx, win, 40, 120, color, "P3");
	mlx_string_put(mlx, win, 40, 130, color, ft_itoa(data[2].life));
}

void	draw_philo4(void *mlx, void *win, t_data *data)
{
	int	color;

	if (data[3].etat == 0)
		color = 0x00FF00;
	if (data[3].etat == 1)
		color = 0xFF0000;
	if (data[3].etat == 2)
		color = 0x00FFFF;
	mlx_string_put(mlx, win, 90, 150, color, "P4");
	mlx_string_put(mlx, win, 90, 160, color, ft_itoa(data[3].life));
}

void	draw_philo5(void *mlx, void *win, t_data *data)
{
	int	color;

	if (data[4].etat == 0)
		color = 0x00FF00;
	if (data[4].etat == 1)
		color = 0xFF0000;
	if (data[4].etat == 2)
		color = 0x00FFFF;
	mlx_string_put(mlx, win, 150, 150, color, "P5");
	mlx_string_put(mlx, win, 150, 160, color, ft_itoa(data[4].life));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 12:29:10 by jflorimo          #+#    #+#             */
/*   Updated: 2014/05/10 12:29:11 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"
#include "libft.h"

void	exit_normal(t_data *data)
{
	ft_putstr("Now, it is time... To DAAAAAAAANCE ! ! !\n");
	mlx_loop(data->shared->mlx);
}

int		error(char *s)
{
	ft_putstr(s);
	exit(1);
	return (1);
}

int		exit_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (data[i].life <= 0)
		{
			ft_putstr("Un philosophe est mort ! ! !\n");
			mlx_loop(data->shared->mlx);
			return (1);
		}
		i++;
	}
	return (0);
}

void	draw_philo6(void *mlx, void *win, t_data *data)
{
	int	color;

	if (data[5].etat == 0)
		color = 0x00FF00;
	if (data[5].etat == 1)
		color = 0xFF0000;
	if (data[5].etat == 2)
		color = 0x00FFFF;
	mlx_string_put(mlx, win, 200, 120, color, "P6");
	mlx_string_put(mlx, win, 200, 130, color, ft_itoa(data[5].life));
}

void	draw_philo7(void *mlx, void *win, t_data *data)
{
	int	color;

	if (data[6].etat == 0)
		color = 0x00FF00;
	if (data[6].etat == 1)
		color = 0xFF0000;
	if (data[6].etat == 2)
		color = 0x00FFFF;
	mlx_string_put(mlx, win, 200, 70, color, "P7");
	mlx_string_put(mlx, win, 200, 80, color, ft_itoa(data[6].life));
}

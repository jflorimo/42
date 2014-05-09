/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 15:02:53 by jflorimo          #+#    #+#             */
/*   Updated: 2014/05/08 17:32:53 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"
#include "libft.h"


void	draw(void *mlx, void *win, t_data *data, int time)
{
	mlx_clear_window(mlx, win);
	mlx_string_put(mlx, win, 120, 30, 0xFF0000,"P1");
	mlx_string_put(mlx, win, 120, 40, 0xFF0000,ft_itoa(data[0].life));
	mlx_string_put(mlx, win, 40, 70, 0xFF0000,"P2");
	mlx_string_put(mlx, win, 40, 80, 0xFF0000,ft_itoa(data[1].life));
	mlx_string_put(mlx, win, 40, 120, 0xFF0000,"P3");
	mlx_string_put(mlx, win, 40, 130, 0xFF0000,ft_itoa(data[2].life));
	mlx_string_put(mlx, win, 90, 150, 0xFF0000,"P4");
	mlx_string_put(mlx, win, 90, 160, 0xFF0000,ft_itoa(data[3].life));
	mlx_string_put(mlx, win, 150, 150, 0xFF0000,"P5");
	mlx_string_put(mlx, win, 150, 160, 0xFF0000,ft_itoa(data[4].life));
	mlx_string_put(mlx, win, 200, 120, 0xFF0000,"P6");
	mlx_string_put(mlx, win, 200, 130, 0xFF0000,ft_itoa(data[5].life));
	mlx_string_put(mlx, win, 200, 70, 0xFF0000,"P7");
	mlx_string_put(mlx, win, 200, 80, 0xFF0000,ft_itoa(data[6].life));
	mlx_string_put(mlx, win, 320, 60, 0xFF0000,"temps:");
	mlx_string_put(mlx, win, 320, 80, 0xFF0000,ft_itoa(time + 1));
	mlx_string_put(mlx, win, 340, 80, 0xFF0000,"/");
	mlx_string_put(mlx, win, 350, 80, 0xFF0000,ft_itoa(TIMEOUT));
}

void	init_data(void)
{
	int			k;
	int			i;
	t_data		data[7];
	pthread_t	philosophe[7];
	t_shared	shared;
	t_env		e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420 , "Philosophe");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	shared.mlx = e.mlx;
	shared.win = e.win;
	init_chopstick(&shared);
	i = 0;
	while (i < 7)
	{
		data[i].i = i;
		data[i].shared = &shared;
		data[i].life = MAX_LIFE;
		data[i].etat = 0;
		if ((k = pthread_create(&philosophe[i], NULL, thread_1, &data[i])) != 0)
		{
			ft_putstr("Thread creation error \n");
			exit(1);
		}
		i++;
	}
	init_time(data);
	join_thread(philosophe);
}

int		main (void)
{
	init_data();
	return (0);
}

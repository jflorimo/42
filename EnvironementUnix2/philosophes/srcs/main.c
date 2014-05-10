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
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"
#include "libft.h"

void	draw(void *mlx, void *win, t_data *data, int time)
{
	mlx_clear_window(mlx, win);
	draw_philo1(mlx, win, data);
	draw_philo2(mlx, win, data);
	draw_philo3(mlx, win, data);
	draw_philo4(mlx, win, data);
	draw_philo5(mlx, win, data);
	draw_philo6(mlx, win, data);
	draw_philo7(mlx, win, data);
	mlx_string_put(mlx, win, 320, 60, 0xFF0000, "temps:");
	mlx_string_put(mlx, win, 320, 80, 0xFF0000, ft_itoa(time + 1));
	mlx_string_put(mlx, win, 340, 80, 0xFF0000, "/");
	mlx_string_put(mlx, win, 350, 80, 0xFF0000, ft_itoa(TIMEOUT));
	mlx_string_put(mlx, win, 0, 374, 0x00FF00, "Philosope en repos");
	mlx_string_put(mlx, win, 0, 386, 0xFF0000, "Philosophe reflechit");
	mlx_string_put(mlx, win, 0, 398, 0x00FFFF, "Philosiophe mange");
	mlx_string_put(mlx, win, 0, 410, 0x0000FF, "Philosiophe dort");
}

void	init_data(t_shared shared)
{
	int			k;
	int			i;
	t_data		data[7];
	pthread_t	philosophe[7];

	i = 0;
	while (i < 7)
	{
		data[i].i = i;
		data[i].shared = &shared;
		data[i].life = MAX_LIFE;
		data[i].etat = 0;
		data[i].prior = 0;
		data[i].shared->pos = 7;
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
	t_env		e;
	t_shared	shared;

	if ((e.mlx = mlx_init()) == NULL)
		return (error("mlx init error\n"));
	e.win = mlx_new_window(e.mlx, 420, 420, "Philosophe");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	shared.mlx = e.mlx;
	shared.win = e.win;
	init_chopstick(&shared);
	init_data(shared);
	return (0);
}

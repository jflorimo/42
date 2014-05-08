/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 12:42:05 by jflorimo          #+#    #+#             */
/*   Updated: 2014/05/08 12:42:11 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"
#include "libft.h"

// void *life_thread(void *arg)
// {
// 	t_data  *data;
// 	int     i;
// 	time_t  current_time;

// 	data = arg;
// 	current_time = time(NULL);
// 	while (time(NULL) < current_time + TIMEOUT)
// 	{
// 		i = 0;
// 		while (i < 7)
// 		{
// 			if (data[i].etat != 2)
// 			data[i].life--;
// 			i++;
// 		}
// 		usleep(1000000);
// 	}
// 	printf("######END######\n");
// 	exit(1);
// }

void			init_chopstick(t_shared *shared)
{
	int			i;
	int			k;

	i = 0;
	while (i < 7)
	{
		if ((k = pthread_mutex_init(&shared->chopstick[i], NULL)) == -1)
		{
			ft_putstr("Mutex initialization failed\n");
			exit(1);
		}
		i++;
	}
}

// void			init_time(t_data *data)
// {
// 	pthread_t	life;
// 	int			k;

// 	if ((k = pthread_create(&life, NULL, life_thread , data)) != 0)
// 	{
// 		ft_putstr("Thread creation error \n");
// 		exit(1);
// 	}
// }
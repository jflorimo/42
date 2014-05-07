/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 16:47:41 by jflorimo          #+#    #+#             */
/*   Updated: 2014/05/07 16:47:41 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"
#include "libft.h"

void	init_chopstick(t_shared *shared)
{
	int	i;
	int	k;

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

void	choose_action(t_data *data)
{
	printf("Philosophe %d au repos life %d\n",data->i, data->life);
	pthread_mutex_lock(&data->shared->chopstick[data->i]);
	pthread_mutex_lock(&data->shared->chopstick[(data->i+1)%7]);
	printf("Philosophe %d mange life %d\n",data->i, data->life);
	data->etat = 1;
	usleep(EAT_T * 1000000);
	pthread_mutex_unlock(&data->shared->chopstick[data->i]);
	pthread_mutex_unlock(&data->shared->chopstick[(data->i+1)%7]);
	data->etat = 0;
	data->life = MAX_LIFE;
	printf("Philosopher %d fini de manger life %d\n",data->i, data->life);	
}
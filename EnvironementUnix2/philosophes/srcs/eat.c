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

void	mange(t_data *data)
{
	printf("Philosophe %d mange life %d\n",data->i, data->life);
	data->etat = 2;
	usleep(EAT_T * 1000000);
	data->life = MAX_LIFE;
	pthread_mutex_unlock(&data->shared->chopstick[data->i]);
	pthread_mutex_unlock(&data->shared->chopstick[(data->i+1)%7]);
	printf("Philosopher %d fini de manger life %d\n",data->i, data->life);	
	data->etat = 0;
}

void	reflechi_current(t_data *data)
{
	printf("Philosophe %d reflechi life %d\n",data->i, data->life);
	data->etat = 1;
	usleep(THINK_T * 1000000);
	data->etat = 0;
	pthread_mutex_unlock(&data->shared->chopstick[data->i]);
	printf("Philosopher %d fini de reflichir life %d\n",data->i, data->life);	
}

void	reflechi_other(t_data *data)
{
	printf("Philosophe %d reflechi life %d\n",data->i, data->life);
	data->etat = 1;
	usleep(THINK_T * 1000000);
	data->etat = 0;
	pthread_mutex_unlock(&data->shared->chopstick[(data->i+1)%7]);
	printf("Philosopher %d fini de reflichir life %d\n",data->i, data->life);	
}

void	repos(t_data *data)
{
	printf("Philosophe %d se repose life %d\n",data->i, data->life);
	usleep(REST_T * 1000000);
}

void	choose_action(t_data *data)
{
	if (data->etat == 0)
	{
		if (pthread_mutex_trylock(&data->shared->chopstick[data->i]) != EBUSY)
		{
			if (pthread_mutex_trylock(&data->shared->chopstick[(data->i+1)%7]) != EBUSY)
				mange(data);
			else
				reflechi_current(data);
		}
		else
		{
			repos(data);
		}
	}
	choose_action(data);
}
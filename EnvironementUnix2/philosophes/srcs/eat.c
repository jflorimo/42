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
	printf("\x1b[31mPhilosophe %d mange life %d\n\x1b[0m",data->i, data->life);
	data->etat = 2;
	usleep(EAT_T * 1000000);
	data->life = MAX_LIFE;
	pthread_mutex_unlock(&(data->shared->chopstick[data->i]));
	pthread_mutex_unlock(&(data->shared->chopstick[(data->i+1)%7]));
	printf("Philosopher %d fini de manger life %d\n",data->i, data->life);	
	data->etat = 0;
}

void	reflechi_current(t_data *data)
{
	printf("\x1b[32mPhilosophe %d reflechi GAUCHE life %d\n\x1b[0m",data->i, data->life);
	data->etat = 1;
	usleep(THINK_T * 1000000);
	data->etat = 0;
	pthread_mutex_unlock(&(data->shared->chopstick[data->i]));
	printf("\x1b[32mPhilosopher %d fini de reflichir life %d\n\x1b[0m",data->i, data->life);	
}

void	reflechi_other(t_data *data)
{
	printf("\x1b[33mPhilosophe %d reflechi DROITE life %d\n\x1b[0m",data->i, data->life);
	data->etat = 1;
	usleep(THINK_T * 1000000);
	data->etat = 0;
	pthread_mutex_unlock(&(data->shared->chopstick[(data->i+1)%7]));
	printf("\x1b[33mPhilosopher %d fini de reflichir life %d\n\x1b[0m",data->i, data->life);	
}

void	repos(t_data *data)
{
	printf("Philosophe %d se repose life %d\n",data->i, data->life);
	usleep(REST_T * 1000000);
}

int		gauche(t_data *data)
{
	if (pthread_mutex_trylock(&(data->shared->chopstick[data->i])) != EBUSY)
		return (1);
	return (0);
}

int		droite(t_data *data)
{
	if (pthread_mutex_trylock(&(data->shared->chopstick[(data->i+1)%7])) != EBUSY)
		return (1);
	return (0);
}

void	choose_action(t_data *data)
{
	if (data->etat == 0)
	{
		if (gauche(data))
		{
			if (droite(data))
				mange(data);
			else
				reflechi_current(data);
		}
		else if (droite(data))
		{
			reflechi_other(data);
		}
		else
		{
			repos(data);
		}
	}
	choose_action(data);
}

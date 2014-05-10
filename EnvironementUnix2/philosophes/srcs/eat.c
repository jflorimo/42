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

#include <stdlib.h>
#include <unistd.h>
#include "philo.h"

void	mange(t_data *data)
{
	int	define;

	define = EAT_T;
	data->etat = 2;
	usleep(define * 1000000);
	data->life = MAX_LIFE;
	pthread_mutex_unlock(&(data->shared->chopstick[data->i]));
	pthread_mutex_unlock(&(data->shared->chopstick[(data->i + 1) % 7]));
}

void	reflechi_current(t_data *data)
{
	int	define;

	define = THINK_T;
	data->etat = 1;
	usleep(define * 1000000);
	pthread_mutex_unlock(&(data->shared->chopstick[data->i]));
}

void	reflechi_other(t_data *data)
{
	int	define;

	define = THINK_T;
	data->etat = 1;
	usleep(define * 1000000);
	pthread_mutex_unlock(&(data->shared->chopstick[(data->i + 1) % 7]));
}

void	repos(t_data *data)
{
	int	define;

	define = REST_T;
	data->etat = 0;
	usleep(define * 1000000);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 14:52:03 by lcharpen          #+#    #+#             */
/*   Updated: 2014/05/10 14:52:05 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "philo.h"
#include "libft.h"

int		gauche(t_data *data)
{
	if (pthread_mutex_trylock(&(data->shared->chopstick[data->i])) != EBUSY)
		return (1);
	return (0);
}

int		droite(t_data *data)
{
	if (pthread_mutex_trylock(&(data->shared->chopstick[(data->i + 1) % 7]))
		!= EBUSY)
		return (1);
	return (0);
}

void	choose_action2(t_data *data, int prior1, int prior2)
{
	if (prior1 == 1 && prior2 == data->i)
		reflechi_other(data);
	if (prior1 == 1)
		reflechi_current(data);
	if (prior1 == 2)
		mange(data);
	if (prior1 == 0)
		repos(data);
}

void	choose_action(t_data *data)
{
	int prior1;
	int	prior2;

	prior1 = data->shared->pos == 0 ? 6 : data->shared->pos - 1;
	prior2 = (data->shared->pos + 1) % 7;
	if (data->i == prior1 || data->i == prior2)
	{
		repos(data);
		choose_action(data);
	}
	prior2 = 0;
	prior1 = gauche(data);
	if (prior1 == 1)
		prior2 = data->i;
	if (data->etat == 2)
	{
		if (prior1 == 1)
			reflechi_other(data);
		else
			repos(data);
		choose_action(data);
	}
	prior1 += droite(data);
	choose_action2(data, prior1, prior2);
	choose_action(data);
}

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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"
#include "libft.h"

void	*thread_1(void *arg)
{
	t_data *data;

	data = arg;
	choose_action(data);
	return (NULL);
}

void	init_data(void)
{
	int			k;
	int			i;
	t_data		data[7];
	pthread_t	philosophe[7];
	t_shared	shared;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 17:38:11 by jflorimo          #+#    #+#             */
/*   Updated: 2014/04/22 17:38:13 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# define MAX_LIFE 42
# define EAT_T 3
# define REST_T 1
# define THINK_T 2
# define TIMEOUT 10
# define EBUSY 16

typedef struct		s_shared
{
	pthread_mutex_t	chopstick[7];
	int				pos;
}					t_shared;

typedef struct		s_data
{
	t_shared		*shared;
	int				i;
	int				life;
	int				etat;
}					t_data;

void	choose_action(t_data *data);
void	init_chopstick(t_shared *shared);
void	init_time(t_data *data);
void	join_thread(pthread_t *philo);

#endif
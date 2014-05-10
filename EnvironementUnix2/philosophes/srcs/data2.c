/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 17:31:23 by jflorimo          #+#    #+#             */
/*   Updated: 2014/05/09 17:31:25 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
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

int		expose_hook(t_env *e)
{
	(void)e;
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == 65307)
		exit (1);
	return (0);
}

void	check_life(t_data *data)
{
	int	i;
	int	savelife;
	int	pos;

	i = 1;
	pos = 5;
	savelife = data[0].life;
	while (i < 7)
	{
		if (data[i].life < savelife && data[i].etat != 2)
		{
			pos = i;
			savelife = data[i].life;
		}
		i++;
	}
	data[pos].shared->pos = pos;
}

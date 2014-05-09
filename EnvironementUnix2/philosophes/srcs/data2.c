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

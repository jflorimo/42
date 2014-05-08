/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 15:02:53 by jflorimo          #+#    #+#             */
/*   Updated: 2014/05/06 15:34:46 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"
#include "libft.h"

void *thread_1(void *arg)
{
    t_data *data;
    data = arg;

    choose_action(data);

    return (NULL);
}

void *life_thread(void *arg)
{
    t_data  *data;
    int     i;
    time_t  current_time;

    data = arg;
    current_time = time(NULL);
    while (time(NULL) < current_time + TIMEOUT)
    {
        i = 0;
        while (i < 7)
        {
            if (data[i].etat != 2)
                data[i].life--;
            i++;
        }
        usleep(1000000);
    }
    printf("######END######\n");
    exit(1);
}

void  init_data(void)
{
    int         k;
    int         i;
    t_data      data[7];
    pthread_t   philosophe[7];
    pthread_t   life;
    t_shared    shared;
    void *msg;

    init_chopstick(&shared);
    i = 0;
    while (i < 7)
    {
        data[i].i = i;
        data[i].shared = &shared;
        data[i].life = MAX_LIFE;
        data[i].etat = 0;
        if ((k = pthread_create(&philosophe[i], NULL, thread_1 , &data[i])) != 0)
        {
            ft_putstr("Thread creation error \n");
            exit(1);
        }
        i++;
    }
    if ((k = pthread_create(&life, NULL, life_thread , &data)) != 0)
    {
        ft_putstr("Thread creation error \n");
        exit(1);
    }
    i = 0;
    while (i < 7)
    {
        k = pthread_join(philosophe[i],&msg);
        i++;
    }
}

int main (void)
{
    init_data();
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 17:38:11 by jflorimo          #+#    #+#             */
/*   Updated: 2014/05/08 17:33:21 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# define MAX_LIFE 42
# define EAT_T 3
# define REST_T 1
# define THINK_T 2
# define TIMEOUT 50
# define EBUSY 16

typedef	struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_shared
{
	pthread_mutex_t	chopstick[7];
	int				pos;
	void			*mlx;
	void			*win;

}					t_shared;

typedef struct		s_data
{
	t_shared		*shared;
	int				i;
	int				life;
	int				etat;
	int				prior;
}					t_data;

void				choose_action(t_data *data);
void				init_chopstick(t_shared *shared);
void				init_time(t_data *data);
void				join_thread(pthread_t *philo);
void				draw(void *mlx, void *win, t_data *data, int time);
void				*thread_1(void *arg);
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
void				exit_normal(t_data *data);
int					exit_dead(t_data *data);
void				mange(t_data *data);
void				repos(t_data *data);
void				reflechi_current(t_data *data);
void				reflechi_other(t_data *data);
void				draw_philo1(void *mlx, void *win, t_data *data);
void				draw_philo2(void *mlx, void *win, t_data *data);
void				draw_philo3(void *mlx, void *win, t_data *data);
void				draw_philo4(void *mlx, void *win, t_data *data);
void				draw_philo5(void *mlx, void *win, t_data *data);
void				draw_philo6(void *mlx, void *win, t_data *data);
void				draw_philo7(void *mlx, void *win, t_data *data);
void				check_life(t_data *data);
int					error(char *s);

#endif

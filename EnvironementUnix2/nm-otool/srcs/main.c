/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 16:41:36 by jflorimo          #+#    #+#             */
/*   Updated: 2014/04/22 16:41:37 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "nm.h"
#include "libft.h"

void		ft_read_file(char *s)
{
	int		fd;
	char	*line;

	fd = open(s, O_RDONLY);
	line = NULL;
	while(get_next_line(fd, &line))
	{
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
	}
}

int 		main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac > 1)
	{
		while(av[i])
		{
			ft_putstr(av[i]);
			ft_putstr("\n");
			ft_read_file(av[i]);
			i++;
		}
	}
	return (0);
}
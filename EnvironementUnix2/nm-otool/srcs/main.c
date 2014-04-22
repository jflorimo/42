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

#include "nm.h"
#include "libft.h"

int 	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1)
	{
		while(av[i])
		{
			ft_putstr(av[i]);
			ft_putstr("\n");
			// ft_read_file(av[i]);
			i++;
		}
	}
	return (0);
}
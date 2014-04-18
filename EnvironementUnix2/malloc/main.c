/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 12:13:05 by jflorimo          #+#    #+#             */
/*   Updated: 2014/04/15 12:13:07 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "malloc.h"
#include <stdio.h>

int main()
{
	char *s;
	int	i = 0;

	s = malloc(sizeof(char) * 50);
	while (i < 50)
	{
		s[i] = '\0';
		i++;
	}
	i = 0;
	while (i < 49)
	{
		s[i] = 'a';
		i++;
	}
	s[i] = '\0';
	// ft_putstr(s);
	// ft_putstr("\n");
	printf("2.%p\n", s);	
	free(s);
	i = 0;
	while (i < 49)
	{
		s[i] = 'x';
		i++;
	}
	// ft_putstr(s);
	// ft_putstr("\n");
	// i = 1;
	// while (i < 40)
	// {
	// 	printf("%d: ", i);
	// 	s = malloc(sizeof(char) * 110);
	// 	i++;
	// }
	i = 0;
	char *x = malloc(sizeof(char) * 50);
	while (i < 40)
	{
		x[i] = 'x';
		i++;
	}
	i = 0;
	char *y = malloc(sizeof(char) * 50);
	while (i < 40)
	{
		y[i] = 'y';
		i++;
	}
	i = 0;
	char *z = malloc(sizeof(char) * 50);
	while (i < 40)
	{
		z[i] = 'z';
		i++;
	}
	free (y);
	i = 0;
	char *t = malloc(sizeof(char) * 50);
	while (i < 40)
	{
		t[i] = 't';
		i++;
	}
	return (0);
}

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
    int lol = 0;
    while ( lol < 100)
    {
	   char *xxx = malloc(sizeof(char) * 180);
       lol++;
    }
	
    int    i = 0;
    char *x = malloc(sizeof(char) * 50);
    while (i < 50)
    {
        x[i] = 'x';
        i++;
    }
    printf("%p\n%s\n", x, x);
    i = 0;
    char *y = malloc(sizeof(char) * 50);
    while (i < 50)
    {
        y[i] = 'y';
        i++;
    }
    printf("%p\n%s\n", y, y);
    i = 0;
    char *z = malloc(sizeof(char) * 50);
    while (i < 50)
    {
        z[i] = 'z';
        i++;
    }
    printf("%p\n%s\n", z, z);
    free(z);
    printf("%d\n", *(int *)z);
    i = 0;
    while (i < 100)
    {
        z[i] = 'a';
        i++;
    }
    printf("%p\n%s\n", z, z);
    i = 0;
    char *t = malloc(sizeof(char) * 50);
    while (i < 50)
    {
        t[i] = 't';
        i++;
    }
    printf("%p\n%s\n", t, t);
    i = 0;
    return (0);
}
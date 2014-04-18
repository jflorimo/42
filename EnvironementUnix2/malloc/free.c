/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 19:00:45 by jflorimo          #+#    #+#             */
/*   Updated: 2014/04/18 19:00:48 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <stdio.h>
#include "malloc.h"

void free (void *ptr)
{
	printf("3.%p\n", ptr);
	ptr -= 16;
	printf("4.%p\n", ptr);
	size_t len = *(size_t *)ptr;
	printf("5.%d\n", (int)len);
	munmap(ptr, len);
}

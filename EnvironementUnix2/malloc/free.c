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
	size_t len;
	size_t blocklen;
	t_block    *block;


	// printf("1ptr%p\n", ptr);
	blocklen = sizeof(block->size) + sizeof(block->next);
	ptr -= blocklen;
	if (*(size_t *)ptr > 1024)
	{
		len = *(size_t *)ptr + blocklen;
		printf("apres%d - %d\n", *(int *)ptr, (len / getpagesize() + (len % getpagesize() != 0)) * getpagesize());
		munmap(ptr, (len / getpagesize() + (len % getpagesize() != 0)) * getpagesize());
	}
	else
	{
	// printf("2ptr%p\n", ptr);
	// printf("avant%d\n", *(int *)ptr);
	*(size_t *)ptr = 0;
	// printf("apres%d\n", *(int *)ptr);
	}
}

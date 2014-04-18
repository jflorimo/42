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
	t_block	*block;

	ptr -= sizeof(block->size) + sizeof(block->next);
	len = *(size_t *)ptr;
	munmap(ptr, len);
}

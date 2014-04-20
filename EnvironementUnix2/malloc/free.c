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
#include "malloc.h"

void			free(void *ptr)
{
	size_t		len;
	size_t		blocklen;
	int			pagesize;
	t_block		*block;

	blocklen = sizeof(block->size) + sizeof(block->next);
	ptr -= blocklen;
	if (*(size_t *)ptr > 1024 - 16)
	{
		pagesize = getpagesize();
		len = *(size_t *)ptr + blocklen;
		len = (len / pagesize + (len % pagesize != 0)) * pagesize;
		munmap(ptr, len);
	}
	else
	{
		*(size_t *)ptr = 0;
	}
}

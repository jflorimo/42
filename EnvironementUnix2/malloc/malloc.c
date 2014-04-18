/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 11:28:14 by jflorimo          #+#    #+#             */
/*   Updated: 2014/04/18 11:28:15 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <stdio.h>
#include "malloc.h"

void	*alloc_pages(size_t size)
{
	int *plen;
	int	len;
	int	pagesize;
	
	pagesize = getpagesize();
	len = (size / pagesize + (size % pagesize != 0)) * pagesize;
	plen = mmap(0, len, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (plen == MAP_FAILED)
		return (NULL);
	return (plen);
}

void	new_block(size_t size)
{
	if (size <= N)
	{
		m_list.tiny = alloc_pages(size);
	}
	else if (size <= M)
	{
		m_list.small = alloc_pages(size);
	}
	else
	{
		m_list.large = alloc_pages(size);
	}
}

void	*add_block(size_t size)
{
	t_block	*block;

	if (size <= N)
	{
		if (!m_list.tiny)
		{
			new_block(size);
		}
		*(size_t *)m_list.tiny = size;
		m_list.tiny += sizeof(block->size);
		*(void **)m_list.tiny = m_list.tiny - sizeof(block->size) + N;
		m_list.tiny += sizeof(size);
		void *res = m_list.tiny;
		m_list.tiny += N - 16;
		return(res);
	}
	else if (size <= M)
	{

	}
	else
	{

	}
	return (NULL);
}

void	*malloc(size_t size)
{
	void	*ret;
	ret = add_block(size);
	printf("1.%p\n", ret);
	return (ret);
}
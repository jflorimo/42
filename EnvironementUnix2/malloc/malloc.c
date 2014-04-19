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
	if (size <= N - 16)
	{
		m_list.tiny.page = alloc_pages(size);
		m_list.tiny.start = m_list.tiny.page;
		m_list.tiny.nb_elem = 0;
		m_list.tiny.type = 1;
	}
	else if (size <= M)
	{
		m_list.small.page = alloc_pages(size);
		m_list.small.start = m_list.small.page;
		m_list.small.nb_elem = 0;
		m_list.small.type = 2;
	}
	else
	{
		m_list.large.page = alloc_pages(size);
		m_list.large.start = m_list.large.page;
		m_list.large.nb_elem = 0;
		m_list.large.type = 3;
	}
}

void	*add_block(size_t size)
{
	t_block	*block;

	if (size <= N - 16)
	{
		if (!m_list.tiny.page || m_list.tiny.nb_elem >= 31)
		{
			new_block(size);
		}
		*(size_t *)m_list.tiny.page = size;
		m_list.tiny.page += sizeof(block->size);
		*(void **)m_list.tiny.page = m_list.tiny.page - sizeof(block->size) + N;
		m_list.tiny.page += sizeof(size);
		void *res = m_list.tiny.page;
		m_list.tiny.page += N - 16;
		m_list.tiny.nb_elem += 1;
		return(res);
	}
	else if (size <= M - 16)
	{
		if (!m_list.small.page || m_list.small.nb_elem >= 4)
		{
			new_block(size);
		}
		*(size_t *)m_list.small.page = size;
		m_list.small.page += sizeof(block->size);
		*(void **)m_list.small.page = m_list.small.page - sizeof(block->size) + M;
		m_list.small.page += sizeof(size);
		void *res = m_list.small.page;
		m_list.small.page += M - 16;
		m_list.small.nb_elem += 1;
		return(res);
	}
	else
	{
		new_block(size);
		int len = (size / getpagesize() + (size % getpagesize() != 0)) * getpagesize();
		*(size_t *)m_list.large.page = size;
		m_list.large.page += sizeof(block->size);
		*(void **)m_list.large.page = m_list.large.page - sizeof(block->size) - len;
		m_list.large.page += sizeof(size);
		void *res = m_list.large.page;
		return(res);
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
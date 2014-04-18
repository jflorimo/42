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
	printf("len: %d\n", len);
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
	if (size <= N)
	{
		if (!m_list.tiny)
		{
			printf("%p\n", m_list.tiny);
			new_block(size);
		}
		printf("\t1.%p\n", m_list.tiny);
		*(size_t *)m_list.tiny = size;
		printf("\t2.%p\n", m_list.tiny);
		m_list.tiny += sizeof(size);
		printf("\t3.%p\n", m_list.tiny);
		*(void **)m_list.tiny = m_list.tiny - sizeof(size) + N;
		printf("\t4.%p\n", m_list.tiny);
		m_list.tiny += sizeof(size);
		printf("\t5.%p\n", m_list.tiny);
		void *res = m_list.tiny;
		printf("\t6.%p\n", m_list.tiny);
		m_list.tiny += N - 4;
		printf("\t7.%p\n", m_list.tiny);
		return(res);
	}
	else if (size <= M)
	{

	}
	else
	{

	}


}

void	*malloc(size_t size)
{
	void	*ret;
	ret = add_block(size);
	printf("%p\n", m_list.tiny);
	return (ret);
}
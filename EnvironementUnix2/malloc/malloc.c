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
#include "malloc.h"

void		*alloc_pages(size_t size)
{
	int		*p;
	int		len;
	int		pagesize;

	pagesize = getpagesize();
	len = (size / pagesize + (size % pagesize != 0)) * pagesize;
	p = mmap(0, len, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (p == MAP_FAILED)
		return (NULL);
	return (p);
}

void		new_block(size_t size)
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

void		*add_block(size_t size)
{
	void	*res;

	if (size <= N - 16)
	{
		if (!m_list.tiny.page || m_list.tiny.nb_elem >= 31)
			new_block(size);
		res = update_tiny_header(size);
		return (res);
	}
	else if (size <= M - 16)
	{
		if (!m_list.small.page || m_list.small.nb_elem >= 4)
			new_block(size);
		res = update_small_header(size);
		return (res);
	}
	else
	{
		res = update_large_header(size);
		return (res);
	}
	return (NULL);
}

void		*malloc(size_t size)
{
	void	*ret;

	ret = add_block(size);
	return (ret);
}

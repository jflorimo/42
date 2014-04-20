/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 11:28:06 by jflorimo          #+#    #+#             */
/*   Updated: 2014/04/18 11:28:07 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*update_tiny_header(size_t size)
{
	void	*res;
	t_block	*block;

	*(size_t *)m_list.tiny.page = size;
	m_list.tiny.page += sizeof(block->size);
	*(void **)m_list.tiny.page = m_list.tiny.page - sizeof(block->size) + N;
	m_list.tiny.page += sizeof(size);
	res = m_list.tiny.page;
	m_list.tiny.page += N - 16;
	m_list.tiny.nb_elem += 1;
	return (res);
}

void		*update_small_header(size_t size)
{
	void	*res;
	t_block	*block;

	*(size_t *)m_list.small.page = size;
	m_list.small.page += sizeof(block->size);
	*(void **)m_list.small.page = m_list.small.page - sizeof(block->size) + M;
	m_list.small.page += sizeof(size);
	res = m_list.small.page;
	m_list.small.page += M - 16;
	m_list.small.nb_elem += 1;
	return (res);
}

void		*update_large_header(size_t size)
{
	void	*res;
	int		len;
	int		pagesize;
	t_block	*block;

	new_block(size);
	pagesize = getpagesize();
	len = (size / pagesize + (size % pagesize != 0)) * pagesize;
	*(size_t *)m_list.large.page = size;
	m_list.large.page += sizeof(block->size);
	*(void **)m_list.large.page = m_list.large.page - sizeof(block->size) - len;
	m_list.large.page += sizeof(size);
	res = m_list.large.page;
	return (res);
}

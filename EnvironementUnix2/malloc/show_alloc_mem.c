/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 11:55:30 by jflorimo          #+#    #+#             */
/*   Updated: 2014/04/20 11:55:30 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "malloc.h"

void			show_alloc_mem(void)
{
	if (!m_list.tiny.page && m_list.tiny.nb_elem > 0)
	{
		ft_putstr("TINY : ");
	}
	if (!m_list.small.page && m_list.small.nb_elem > 0)
	{
		ft_putstr("SMALL : ");
	}
	if (!m_list.large.page)
	{
		ft_putstr("LARGE : ");
	}
	ft_putstr("Total : ");
	ft_putstr(" octets\n");
}

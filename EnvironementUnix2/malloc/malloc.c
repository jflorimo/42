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

void	*malloc(size_t size)
{
    int *plen;
    int len = size + sizeof( size ); // Add sizeof( size ) for holding length.

    plen = mmap(0, len, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    *plen = len;                     // First 4 bytes contain length.
    return (void*)(&plen[1]);
}
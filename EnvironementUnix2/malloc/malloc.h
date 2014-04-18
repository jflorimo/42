/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 11:28:23 by jflorimo          #+#    #+#             */
/*   Updated: 2014/04/18 11:28:24 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>

# define N			128
# define M			1024

typedef struct		s_block
{
	size_t			size;
	void			*next;
}					t_block;

typedef struct		s_list
{
	void			*tiny;
	void			*small;
	void			*large;
}					t_list;

t_list				m_list;

void				ft_putstr(char const *s);
void				*malloc(size_t size);

#endif

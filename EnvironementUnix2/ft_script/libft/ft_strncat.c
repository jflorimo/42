/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 17:38:28 by jflorimo          #+#    #+#             */
/*   Updated: 2013/12/07 17:38:44 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s;

	s = s1;
	while (*s1)
		s1++;
	while (*s2 && (int)n-- > 0)
		*s1++ = *s2++;
	*s1 = '\0';
	return (s);
}

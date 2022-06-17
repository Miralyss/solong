/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shduong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:06:10 by shduong           #+#    #+#             */
/*   Updated: 2022/02/28 10:08:21 by shduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*m1;
	unsigned char	*m2;

	m1 = (unsigned char *)s1;
	m2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (m1[i] != m2[i])
			return (m1[i] - m2[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shduong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:54:10 by shduong           #+#    #+#             */
/*   Updated: 2022/03/02 13:54:36 by shduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i < dstsize - 1 && dstsize != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != '\0')
	{
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

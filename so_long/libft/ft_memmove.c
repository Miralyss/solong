/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shduong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:06:55 by shduong           #+#    #+#             */
/*   Updated: 2022/02/28 16:33:37 by shduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*sdst;
	unsigned char	*ssrc;

	i = 0;
	sdst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	if (sdst > ssrc)
	{
		while (i < len)
		{
			sdst[len - 1] = ssrc[len -1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			sdst[i] = ssrc[i];
			i++;
		}
	}
	return (dst);
}

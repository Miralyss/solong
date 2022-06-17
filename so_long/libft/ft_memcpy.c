/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shduong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:42:18 by shduong           #+#    #+#             */
/*   Updated: 2022/03/02 15:43:38 by shduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*sdst;
	unsigned char	*ssrc;

	sdst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	while (n > 0)
	{
		*sdst++ = *ssrc++;
		n--;
	}
	return (dst);
}

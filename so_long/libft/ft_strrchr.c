/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shduong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:00:05 by shduong           #+#    #+#             */
/*   Updated: 2022/03/02 16:19:29 by shduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (len--)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
	}
	if (s[len] == (char)c)
		return ((char *)s + len);
	return (NULL);
}

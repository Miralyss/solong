/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shduong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:19:26 by shduong           #+#    #+#             */
/*   Updated: 2022/03/02 15:44:23 by shduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*rtn;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (char_set(s1[start], set) == 0)
		start++;
	if (start == ft_strlen(s1))
	{
		rtn = ft_strdup("");
		if (!rtn)
			return (NULL);
		else
			return (rtn);
	}
	while (char_set(s1[end - 1], set) == 0)
		end --;
	rtn = ft_substr(s1, start, end - start);
	return (rtn);
}

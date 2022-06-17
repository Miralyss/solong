/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shduong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:25:14 by shduong           #+#    #+#             */
/*   Updated: 2022/03/01 18:08:03 by shduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	char	*final;

	if (s1 == 0 && s2 == 0)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len + 1;
	final = malloc (sizeof(char) * total_len);
	if (!final)
		return (0);
	ft_memmove(final, s1, s1_len);
	ft_memmove(final + s1_len, s2, s2_len);
	final[total_len - 1] = '\0';
	return (final);
}

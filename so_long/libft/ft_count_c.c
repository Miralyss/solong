/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shduong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:57:01 by shduong           #+#    #+#             */
/*   Updated: 2022/06/15 12:57:02 by shduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_c(char *s, char c)
/* will count appearances of c inside s and return them as integer */
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!s)
		return (-1);
	while (s && s[i])
	{
		if (s[i++] == c)
			x++;
	}
	return (x);
}

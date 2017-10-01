/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 01:19:36 by sgardner          #+#    #+#             */
/*   Updated: 2017/09/20 15:34:13 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ASSIGNMENT:
** Re-code similarly named libc function.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const t_byte	*b1;
	const t_byte	*b2;
	size_t			i;

	if (n == 0)
		return (0);
	b1 = (const t_byte *)s1;
	b2 = (const t_byte *)s2;
	i = 0;
	while (i < n && b1[i])
	{
		if (b1[i] != b2[i])
			break ;
		i++;
	}
	if (i == n)
		return (0);
	return (b1[i] - b2[i]);
}

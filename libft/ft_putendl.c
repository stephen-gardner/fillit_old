/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 01:15:55 by sgardner          #+#    #+#             */
/*   Updated: 2017/01/14 22:49:25 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ASSIGNMENT:
** Outputs the string s to the standard output followed by a
**  '\n'.
*/

void	ft_putendl(const char *s)
{
	ft_putendl_fd(s, 1);
}

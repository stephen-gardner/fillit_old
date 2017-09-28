/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_verifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 19:01:11 by sgardner          #+#    #+#             */
/*   Updated: 2017/09/27 15:59:08 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		flood(t_shape *shape, char c, int row, int col)
{
	if (row < 0 || row > 3 || col < 0 || col > 3
			|| shape->grid[row][col] != '#')
		return (0);
	shape->grid[row][col] = c;
	return (1 + flood(shape, c, row, col - 1) + flood(shape, c, row, col + 1)
			+ flood(shape, c, row - 1, col) + flood(shape, c, row + 1, col));
}

t_bool			verify_chars(t_shape *shape)
{
	int		blocks;
	int		row;
	int		col;
	char	c;

	blocks = 0;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = shape->grid[row][col];
			if (c != '.' && c != '#')
				return (FALSE);
			if (c == '#')
				blocks++;
			col++;
		}
		row++;
	}
	return (blocks == 4);
}

t_bool			verify_connected(t_shape *shape, int count)
{
	int		row;
	int		col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if ((shape->grid)[row][col] == '#')
				return (flood(shape, 'A' + count, row, col) == 4);
			col++;
		}
		row++;
	}
	return (FALSE);
}

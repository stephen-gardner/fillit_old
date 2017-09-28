/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 23:46:04 by sgardner          #+#    #+#             */
/*   Updated: 2017/09/27 21:59:59 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bool	can_place(t_board *board, t_shape *shape, int row, int col)
{
	int	s_row;
	int	s_col;

	if (col + shape->width > board->size || row + shape->length > board->size)
		return (FALSE);
	s_row = 0;
	while (s_row < shape->length)
	{
		s_col = 0;
		while (s_col < shape->width)
		{
			if (shape->grid[s_row][s_col] != '.'
					&& (board->grid[row][col] != '.'))
				return (FALSE);
			s_col++;
			col++;
		}
		col -= shape->width;
		s_row++;
		row++;
	}
	return (TRUE);
}

static void		place(t_board *board, t_shape *shape, int row, int col)
{
	int	s_row;
	int	s_col;

	s_row = 0;
	while (s_row < shape->length)
	{
		s_col = 0;
		while (s_col < shape->width)
		{
			if (shape->grid[s_row][s_col] != '.')
				board->grid[row][col] = (board->grid[row][col] == '.') ?
					shape->grid[s_row][s_col] : '.';
			s_col++;
			col++;
		}
		col -= shape->width;
		s_row++;
		row++;
	}
}

static t_board	*work_board(t_board *board, t_shape *shape)
{
	int	row;
	int	col;

	if (!shape)
		return (board);
	row = 0;
	while (row < (board->size - shape->length) + 1)
	{
		col = 0;
		while (col < (board->size - shape->width) + 1)
		{
			if (can_place(board, shape, row, col))
			{
				place(board, shape, row, col);
				if (work_board(board, shape->next))
					return (board);
				else
					place(board, shape, row, col);
			}
			col++;
		}
		row++;
	}
	return (NULL);
}

t_board			*solve(t_shape *shapes)
{
	t_board	*board;
	t_shape	*current;
	int		min_area;
	int		size;

	min_area = 4;
	current = shapes;
	while ((current = current->next))
		min_area += 4;
	size = 2;
	while (size * size < min_area)
		size++;
	board = gen_board(size);
	while (!work_board(board, shapes))
	{
		free_board(board);
		board = gen_board(++size);
	}
	return (board);
}

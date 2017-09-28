/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:18:24 by sgardner          #+#    #+#             */
/*   Updated: 2017/09/27 22:57:33 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_board(t_board *board)
{
	int	i;

	i = 0;
	while (board->grid[i])
		free(board->grid[i++]);
	free(board->grid);
	free(board);
}

t_board	*gen_board(int size)
{
	t_board	*board;
	int		i;

	if (!(board = (t_board *)malloc(sizeof(t_board))))
		return (NULL);
	board->size = size;
	if (!(board->grid = (char **)ft_memalloc((sizeof(char *) * (size + 1)))))
	{
		free(board);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		if (!(board->grid[i] = (char *)malloc(size)))
		{
			free_board(board);
			return (NULL);
		}
		ft_memset(board->grid[i++], '.', size);
	}
	return (board);
}

void	print_board(t_board *board)
{
	int	row;

	row = 0;
	while (row < board->size)
	{
		write(1, board->grid[row++], board->size);
		write(1, "\n", 1);
	}
	free_board(board);
}

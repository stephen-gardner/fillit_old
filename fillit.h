/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 22:37:34 by sgardner          #+#    #+#             */
/*   Updated: 2017/09/27 15:52:38 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_shape
{
	char			grid[4][4];
	int				length;
	int				width;
	struct s_shape	*next;
}				t_shape;

typedef struct	s_board
{
	char	**grid;
	int		size;
}				t_board;

/*
** board.c
*/

void			free_board(t_board *board);
t_board			*gen_board(int size);
void			print_board(t_board *board);

/*
** solver.c
*/

t_board			*solve(t_shape *shape);

/*
** shape_loader.c
*/

t_bool			load_all_shapes(int fd, t_shape **shapes);
void			unload_shapes(t_shape *shapes);

/*
** shape_verifier.c
*/

t_bool			verify_chars(t_shape *shape);
t_bool			verify_connected(t_shape *shape, int count);
#endif

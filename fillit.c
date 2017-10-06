/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 15:20:29 by sgardner          #+#    #+#             */
/*   Updated: 2017/10/05 23:15:58 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_shape	*shapes;

	if (argc != 2)
	{
		ft_putendl("usage: fillit target_file");
		return (1);
	}
	shapes = NULL;
	if ((fd = open(argv[1], O_RDONLY)) == -1
			|| !load_all_shapes(fd, &shapes)
			|| close(fd) == -1)
	{
		unload_shapes(shapes);
		ft_putendl("error");
		return (1);
	}
	print_board(solve(shapes));
	unload_shapes(shapes);
	return (0);
}

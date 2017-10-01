/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 17:17:05 by sgardner          #+#    #+#             */
/*   Updated: 2017/09/29 00:08:50 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		calc_dimen(t_shape *shape)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (shape->grid[row][col] != '.')
			{
				if (row + 1 > shape->length)
					shape->length = row + 1;
				if (col + 1 > shape->width)
					shape->width = col + 1;
			}
			col++;
		}
		row++;
	}
}

static void		trim_shape(t_shape *shape)
{
	int	row;

	while (shape->grid[0][0] == '.' && shape->grid[1][0] == '.'
			&& shape->grid[2][0] == '.' && shape->grid[3][0] == '.')
	{
		row = 0;
		while (row < 4)
		{
			ft_memmove((void *)shape->grid[row],
					(const void *)shape->grid[row] + 1, 3);
			shape->grid[row++][3] = '.';
		}
	}
	while (ft_strnequ(shape->grid[0], "....", 4))
	{
		ft_memcpy(shape->grid[0], shape->grid[1], 4);
		ft_memcpy(shape->grid[1], shape->grid[2], 4);
		ft_memcpy(shape->grid[2], shape->grid[3], 4);
		ft_memcpy(shape->grid[3], "....", 4);
	}
}

static t_shape	*load_shape(char *buf)
{
	t_shape	*shape;
	int		row;

	if (!(shape = (t_shape *)malloc(sizeof(t_shape))))
		return (NULL);
	shape->length = 0;
	shape->width = 0;
	shape->next = NULL;
	row = 0;
	while (row < 4)
	{
		if (buf[((row + 1) * 5) - 1] != '\n')
		{
			free(shape);
			return (NULL);
		}
		ft_memcpy(shape->grid[row], buf + (row * 5), 4);
		row++;
	}
	return (shape);
}

t_bool			load_all_shapes(int fd, t_shape **shapes)
{
	char	buf[21];
	int		bytes;
	int		count;
	int		more;

	count = 0;
	while ((bytes = read(fd, buf, 21)) == 20 || bytes == 21)
	{
		if ((bytes == 21 && buf[20] != '\n')
			|| !(*shapes = load_shape(buf))
			|| !verify_chars(*shapes)
			|| !verify_connected(*shapes, count))
			return (0);
		trim_shape(*shapes);
		calc_dimen(*shapes);
		more = (bytes > 20) ? TRUE : FALSE;
		if (++count > 26)
			break ;
		shapes = &(*shapes)->next;
	}
	if (bytes != 0 || more)
		return (FALSE);
	return (count > 0 && count <= 26);
}

void			unload_shapes(t_shape *shapes)
{
	t_shape	*next;

	while (shapes)
	{
		next = shapes->next;
		free(shapes);
		shapes = next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shduong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:09:13 by shduong           #+#    #+#             */
/*   Updated: 2022/05/20 17:09:14 by shduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_data *data)
/* will cause the different actions of the valid key presses
** will cause you to win if you reached the exit */
{
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == W)
		ft_move(data, 'y', UP);
	else if (keycode == A)
		ft_move(data, 'x', LEFT);
	else if (keycode == S)
		ft_move(data, 'y', DOWN);
	else if (keycode == D)
		ft_move(data, 'x', RIGHT);
	if (data->map->map[data->p_y][data->p_x] == 'E')
		ft_win(data);
	return (0);
}

static void	ft_player_move(t_data *data, char position, int direction)
/* will put the correct orientation of the spaceship on the screen */
{
	if (position == 'y' && direction == UP)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_up,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
	if (position == 'x' && direction == LEFT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_left,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
	if (position == 'y' && direction == DOWN)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_down,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
	if (position == 'x' && direction == RIGHT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_right,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
}

static void	ft_collect(t_data *data, char pos, int dir)
/* will collect the collectables
** will remove them from the map-struct as well as the screen */
{
	data->collected++;
	data->map->map[data->p_y][data->p_x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->p_x * IMG_W), (data->p_y * IMG_H));
	ft_player_move(data, pos, dir);
}

void	ft_move(t_data *data, char pos, int dir)
/* will check if a move is valid and move the player if valid */
{
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->p_x * IMG_W), (data->p_y * IMG_H));
	if (pos == 'y' && data->map->map[data->p_y + 1 * dir][data->p_x] != '1'
		&& (data->map->map[data->p_y + 1 * dir][data->p_x] != 'E'
		|| data->collected == data->map->diamonds))
		data->p_y = data->p_y + 1 * dir;
	else if (pos == 'x' && data->map->map[data->p_y][data->p_x + 1 * dir] != '1'
		&& (data->map->map[data->p_y][data->p_x + 1 * dir] != 'E'
		|| data->collected == data->map->diamonds))
		data->p_x = data->p_x + 1 * dir;
	else if (pos == 'y' && data->map->map[data->p_y + 1 * dir][data->p_x] == 'E'
		&& data->collected != data->map->diamonds)
		printf("Collect all before leaving\n");
	else if (pos == 'x' && data->map->map[data->p_y][data->p_x + 1 * dir] == 'E'
		&& data->collected != data->map->diamonds)
		printf("Collect all before leaving\n");
	ft_player_move(data, pos, dir);
	if (data->map->map[data->p_y][data->p_x] == 'C')
		ft_collect(data, pos, dir);
	mlx_do_sync(data->mlx);
	printf("Moves : %d\n", ++data->counter);
}

void	ft_win()
{
	printf("GG !\n");
	printf("You won!\n");
	exit(EXIT_SUCCESS);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shduong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:35:29 by shduong           #+#    #+#             */
/*   Updated: 2022/05/20 16:32:07 by shduong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_help(t_data *data)
/* only exists because of the 25 line limit */
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./textures/DinoB.xpm";
	data->img->player_right = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./textures/grassbg.xpm";
	data->img->background = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
}

void	ft_init(t_data *data, t_map *map)
/* initialises most of my used data inside the structs */
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	t_img	*img;

	data->map = map;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		perror("Error\nmalloc failed\n");
		exit(EXIT_FAILURE);
	}
	data->img = img;
	relative_path = "textures/DinoB.xpm";
	data->img->player_up = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./textures/DinoBR.xpm";
	data->img->player_left = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./textures/DinoBR.xpm";
	data->img->player_down = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	ft_init_help(data);
	data->counter = 0;
	data->collected = 0;
}
int	ft_exit(t_data *data)
/* will show a message in the terminal and exit the process */
{
	mlx_destroy_window(data->mlx, data->win);
	printf("Game Over :(\n");
	exit(EXIT_SUCCESS);
}

static int	ft_render_next_frame(t_data *data)
/* checks for keyboard or mouse input */
{
	ft_put_background(data);
	ft_create_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}

int	main(int argc, char **argv)
/* runs the mlx loop */
{
	t_data	data;
	t_map	map;

	ft_window_size(&data, argv);
	map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	if (!map.map)
	{
		perror("Error\ncalloc failed\n");
		exit(EXIT_FAILURE);
	}
	ft_init(&data, &map);
	ft_parse_input(&data, argv, argc);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		perror("Error\nprogramm init failed\n");
		exit(EXIT_FAILURE);
	}
	data.win = mlx_new_window(data.mlx, data.size_x,
			data.size_y, "./so_long");
	ft_render_next_frame(&data);
	mlx_loop(data.mlx);
	perror("Error\nloop failed\n");
	exit(EXIT_FAILURE);
}


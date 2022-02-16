/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:36:12 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/02/16 11:16:35 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"
#include "so_long.h"

void	ft_move_x(t_mlx_lst *list, int collectible_count, int direction, int *movescounter)
{
	ft_check_enemy_facing(list, direction, 'x');
	if (!((list->string[list->playerx + direction][list->playery] == 'E') && (collectible_count > 0)))
	{
		if (!(list->string[list->playerx + direction][list->playery] == '1'))
		{
			if ((collectible_count == 0) && (list->string[list->playerx + direction][list->playery] == 'E'))
				exit(1);
			if (list->string[list->playerx + direction][list->playery] == 'C')
				list->string[list->playerx + direction][list->playery] = '0';
			*movescounter += 1;
			ft_create_elements(list, (list->playery) * MAP_UNITY, (list->playerx * MAP_UNITY), BLACK_IMG);
			list->playerx += direction;
			ft_create_elements(list, (list->playery) * MAP_UNITY, (list->playerx) * MAP_UNITY, PLAYER_IMG);
		}
	}
}

void	ft_move_y(t_mlx_lst *list, int collectible_count, int direction, int *movescounter)
{
	ft_check_enemy_facing(list, direction, 'y');
	if (!((list->string[list->playerx][list->playery + direction] == 'E') && (collectible_count > 0)))
	{
		if (!(list->string[list->playerx][list->playery + direction] == '1'))
		{
			if ((collectible_count == 0) && (list->string[list->playerx] [list->playery + direction] == 'E'))
				exit(1);
			if (list->string[list->playerx][list->playery + direction] == 'C')
				list->string[list->playerx][list->playery + direction] = '0';
			*movescounter += 1;
			ft_create_elements(list, (list->playery * MAP_UNITY), (list->playerx * MAP_UNITY), BLACK_IMG);
			list->playery += direction;
			ft_create_elements(list, (list->playery) * MAP_UNITY, (list->playerx) * MAP_UNITY, PLAYER_IMG);
		}
	}
}

void	ft_trying_to_create_element(t_mlx_lst *list, int i, int j)
{
	while (list->string[++i])
	{
		j = -1;
		while (list->string[i][++j])
		{
			if (list->string[i][j] == '1')
				ft_create_elements(list, j * MAP_UNITY, i * MAP_UNITY, WALL_IMG);
			else if (list->string[i][j] == 'P')
				ft_create_player(list, i, j);
			else if (list->string[i][j] == 'C')
				ft_create_elements(list, j * MAP_UNITY, i * MAP_UNITY, COLLECTIBLE_IMG);
			else if (list->string[i][j] == 'E')
				ft_create_elements(list, j * MAP_UNITY, i * MAP_UNITY, EXIT_IMG);
			else if (list->string[i][j] == 'N')
				ft_create_elements(list, j * MAP_UNITY, i * MAP_UNITY, ENEMY_IMG);
		}
	}
}

void	so_long(int fd)
{
	t_mlx_lst			list;
	t_variables_list	var;

	var.i = -1;
	var.j = -1;
	var.str = check_isvalidemap(fd);
	if (var.str == NULL)
		return ;
	list.string = ft_split(var.str, '\n');
	var.window_height = ft_length(list.string);
	var.window_width = ft_strlen(list.string[0]);
	list.mlx = mlx_init();
	list.win = mlx_new_window(list.mlx, (var.window_width * MAP_UNITY), (var.window_height * MAP_UNITY), "so_long");
	ft_trying_to_create_element(&list, var.i, var.j);
	mlx_hook(list.win, 17, 0, ft_destroy, NULL);
	mlx_key_hook(list.win, ft_moveit, &list);
	mlx_loop(list.mlx);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*ber;

	ber = ft_strrchr(av[1], '.');
	if (ber && ac == 2)
	{
		if (ft_strncmp(ber, ".ber", 4) == 0)
		{
			fd = open(av[1], 2);
			so_long(fd);
			return (0);
		}
	}
	printf("Error\n");
}

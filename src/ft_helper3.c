/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:48:26 by ael-hiou          #+#    #+#             */
/*   Updated: 2021/12/18 18:10:23 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../so_long.h"

char	*check_isvalidemap(int fd)
{
	int		i;
	t_list	*head;
	char	*str;

	head = NULL;
	head = ft_create_nodes();
	str = ft_get_all_lines(fd);
	i = 0;
	if (ft_check_wall(str) == 0)
	{
		while (str[i] && check_player_counter(head) == 0)
		{
			ft_check_elements(str, i);
			ft_which_one_to_increment(str[i], head);
			i++;
		}
		if (ft_check_for_characters(head) == 0)
		{
			ft_lstclear(&head);
			return (str);
		}	
	}
	return (NULL);
}

void	ft_create_elements(t_mlx_lst *list, \
		int positionx, int positiony, char *imagepath)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	list->img = mlx_xpm_file_to_image(list->mlx, imagepath, &width, &height);
	mlx_put_image_to_window (list->mlx, list->win, \
			list->img, positionx, positiony);
}

int	ft_collectibles_counter(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_create_player(t_mlx_lst *list, int i, int j)
{
	list->playerx = i;
	list->playery = j;
	ft_create_elements(list, j * MAP_UNITY, i \
			* MAP_UNITY, PLAYER_IMG);
}

void	ft_check_enemy_facing(t_mlx_lst *list, int direction, char a)
{
	if (a == 'x')
	{
		if (list->string[list->playerx + direction][list->playery] == 'N')
		{
			printf("\033[0;31mGame Over \n");
			exit(1);
		}
	}
	else
	{
		if (list->string[list->playerx][list->playery + direction] == 'N')
		{
			printf("\033[0;31mGame Over \n");
			exit(1);
		}
	}
}

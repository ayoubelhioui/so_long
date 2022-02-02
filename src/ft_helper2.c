/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:46:01 by ael-hiou          #+#    #+#             */
/*   Updated: 2021/12/18 17:52:37 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_moveit(int key, t_mlx_lst *list)
{
	int			collectible_count;
	static int	movescounter = 0;
	char		*saver;

	collectible_count = ft_collectibles_counter(list->string);
	if (key == 13 || key == 126)
		ft_move_x(list, collectible_count, -1, &movescounter);
	else if (key == 2 || key == 124)
		ft_move_y(list, collectible_count, 1, &movescounter);
	else if (key == 1 || key == 125)
		ft_move_x(list, collectible_count, 1, &movescounter);
	else if (key == 0 || key == 123)
		ft_move_y(list, collectible_count, -1, &movescounter);
	else if (key == 53)
		exit(1);
	saver = ft_itoa(movescounter);
	ft_create_elements(list, 0, 0, WALL_IMG);
	mlx_string_put(list->mlx, list->win, COUNTER_POSITION, \
		COUNTER_POSITION, COUNTER_COLOR, saver);
	free(saver);
	return (0);
}

int	ft_check_for_characters(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		if (temp ->character == 'P' && temp ->counter == 0)
		{
			printf("Error\nYou May Have Multiple Players,\
 Or May You Dont Have A Player !!");
			exit(1);
		}
		if (temp ->character == 'E' && temp ->counter == 0)
		{
			printf("Error\nYou Must Have At Least One Exit !!");
			return (-1);
		}
		else if (temp ->character == 'C' && temp ->counter == 0)
		{
			printf("Error\nYou Must Have At Least One Collectible !!");
			return (-1);
		}
		temp = temp ->next;
	}
	return (0);
}

int	check_player_counter(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		if (temp ->character == 'P' && temp ->counter > 1)
		{
			printf("Error\nYou May Have Multiple Players, \
					Or You May Have No Player !!");
			exit(1);
		}
		temp = temp ->next;
	}
	return (0);
}

void	ft_increment(char character, t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		if (temp ->character == character)
		{
			temp ->counter += 1;
			break ;
		}
		temp = temp -> next;
	}
}

void	ft_which_one_to_increment(char a, t_list *head)
{
	if (a == 'C')
		ft_increment(a, head);
	if (a == 'P')
		ft_increment(a, head);
	if (a == 'E')
		ft_increment(a, head);
}

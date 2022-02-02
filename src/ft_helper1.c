/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:03:35 by ael-hiou          #+#    #+#             */
/*   Updated: 2021/12/18 17:50:30 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../includes/get_next_line.h"

int	ft_length(char **str)
{
	int	i;

	i = 0;
	if (!str)
	{
		printf("Error");
		exit(1);
	}
	while (str[i])
		i++;
	return (i);
}

char	*ft_get_all_lines(int fd)
{
	char	*saver;
	char	*last;

	saver = NULL;
	last = get_next_line(fd);
	while (last)
	{
		saver = ft_strjoin(saver, last);
		free (last);
		last = get_next_line(fd);
		if (!last)
			break ;
	}
	return (saver);
}

int	ft_isrectangle(char **s)
{
	int	i;
	int	first;

	i = 1;
	first = ft_strlen(s[0]);
	while (s[i])
	{
		if ((int)ft_strlen(s[i]) != first)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check(char *str, char a)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != a)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_wall(char *s)
{
	int		i;
	char	**str;
	int		index;

	i = 0;
	str = ft_split(s, '\n');
	index = ft_length(str) - 1;
	if (ft_isrectangle(str) != 0)
		ft_printing_no_rectangle();
	while (str[i])
	{
		if (((i == 0 || i == index) && (ft_check(str[i], '1') == -1))
			|| (((!(i == 0 || i == index) && (str[i][0] != '1'))
				|| str[i][ft_strlen(str[i]) - 1] != '1')))
		{
			free_it(str);
			printf("Error\nThere's No Wall Asi Mohamed");
			return (-1);
		}
		i++;
	}
	free_it(str);
	return (0);
}

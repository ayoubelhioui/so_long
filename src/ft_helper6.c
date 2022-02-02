/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:43:35 by ael-hiou          #+#    #+#             */
/*   Updated: 2021/12/18 17:57:13 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../includes/get_next_line.h"

char	*ft_strrchr(char *s, int c)
{
	int	a;

	a = (int)ft_strlen(s) - 1;
	if (c == 0)
		return ((char *)&s[a + 1]);
	while (a >= 0)
	{
		if (s[a] == (char)c)
			return ((char *)&s[a]);
		a--;
	}
	return (NULL);
}

void	ft_check_elements(char *str, int i)
{
	if ((str[i] != 'C') && (str[i] != '0') && \
	(str[i] != '1') && (str[i] != 'P') && \
	(str[i] != 'E') && (str[i] != '\n') && str[i] != 'N')
	{
		printf("Error\nUnvalid Map -_-\n");
		exit(1);
	}
}

void	free_it(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_printing_no_rectangle(void)
{
	printf("Error\nThe Map Is Not Rectangle");
	exit(1);
}

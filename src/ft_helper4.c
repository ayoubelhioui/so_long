/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:10:42 by ael-hiou          #+#    #+#             */
/*   Updated: 2021/12/18 14:17:58 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_destroy(void)
{
	exit(1);
}

char	*fill(char *str, long n, int size)
{
	int	sign;

	sign = 0;
	str[size--] = '\0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
		sign = 1;
	}
	while (size > 0)
	{
		str[size] = (n % 10) + 48;
		n = n / 10;
		size--;
	}
	if (sign == 0)
		str[size] = (n % 10) + 48;
	return (str);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*alocated;
	long int	c;

	c = n;
	size = ft_get_size(c);
	alocated = malloc(sizeof(char) * size + 1);
	if (!alocated)
		return (NULL);
	return (fill(alocated, c, size));
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*saver;

	temp = *lst;
	while (temp != NULL)
	{
		saver = temp ->next;
		free(temp);
		temp = saver;
	}
	*lst = NULL;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i <= n)
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}

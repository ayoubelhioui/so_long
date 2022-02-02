/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:06:26 by ael-hiou          #+#    #+#             */
/*   Updated: 2021/12/18 14:19:43 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_list	*ft_lstnew(char character, int counter)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->character = character;
	element->counter = counter;
	element->next = NULL;
	return (element);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp -> next)
		temp = temp -> next;
	return (temp);
}

void	ft_lstadd_back(t_list **lst, t_list *newone)
{
	t_list	*temp;
	t_list	*save;

	if (!lst)
		return ;
	if (*lst)
	{
		temp = *lst;
		save = ft_lstlast(*lst);
		save -> next = newone;
		return ;
	}
	*lst = newone;
}

t_list	*ft_create_nodes(void)
{
	t_list	*head;
	t_list	*charc;
	t_list	*charp;
	t_list	*chare;

	head = NULL;
	charc = ft_lstnew('C', 0);
	chare = ft_lstnew('E', 0);
	charp = ft_lstnew('P', 0);
	ft_lstadd_back(&head, charc);
	ft_lstadd_back(&head, chare);
	ft_lstadd_back(&head, charp);
	return (head);
}

int	ft_get_size(long c)
{
	int	cp;

	cp = 0;
	if (c < 0)
	{
		c *= -1;
		cp++;
	}
	while (c >= 0)
	{
		c = c / 10;
		cp++;
		if (c == 0)
			break ;
	}
	return (cp);
}

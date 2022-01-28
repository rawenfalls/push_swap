/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:44:00 by marvin            #+#    #+#             */
/*   Updated: 2022/01/27 23:44:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*создаёт эллимент списка*/
t_list	*ft_lstnew(int content)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	tmp->index = 0;
	return (tmp);
}

//добавляет новый эллимент в начало списка
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
		new->next = (*lst);
	*lst = new;
}

//добавляет новый эллимент в конец списка
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

// int	ft_lstsize(t_list *lst)//считает кол-во эллиментов в списке
// {
// 	int	size;
// 	size = 0;
// 	while (lst)
// 	{
// 		size++;
// 		lst = lst->next;
// 	}
// 	return (size);
// }

//проверяет отсортирован ли массив
int	is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

//выводит все элементы списка и их идексы
void	print_t_list(t_list *tmp)
{
	while (tmp)
	{
		printf("|%d| index(%d)\n", tmp->content, tmp->index);
		(tmp) = (tmp)->next;
	}
	printf("--------------\n");
}

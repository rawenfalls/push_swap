#include "push_swap.h"

t_list	*ft_lstnew(int content)//создаёт эллимент списка
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

void	ft_lstadd_front(t_list **lst, t_list *new)//добавляет новый эллимент в начало списка
{
	if (*lst)
		new->next = (*lst);
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)//добавляет новый эллимент в конец списка
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

int	is_sorted(t_list *lst)//проверяет отсортирован ли массив
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	print_t_list(t_list *tmp)//выводит все элементы списка и их идексы
{
		while (tmp)
		{
			printf("|%d| index(%d)\n", tmp->content, tmp->index);
			(tmp) = (tmp)->next;
		}
		printf("--------------\n");
}
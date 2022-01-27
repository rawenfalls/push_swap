#include "push_swap.h"

void	raspred_f(int size, t_list	**tmp)
{
	t_list	*lstb;

	lstb = NULL;
	if (size == 2)
		write(1,"|sa|\n",5);
	else if (size == 3)
		three_sort(tmp);
	else if (size == 4)
		four_sort(tmp, &lstb, size);
	else if (size == 5)
		five_sort(tmp, &lstb, size);
	else if (size <= 100)
		big_sort(tmp, &lstb, size, 10);
	else
		big_sort(tmp, &lstb, size, 25);
}

void	three_sort(t_list	**tmp)
{
	int	a;
	int	b;
	int	c;

	a = (*tmp)->content;
	b = (*tmp)->next->content;
	c = (*tmp)->next->next->content;
	if (a > b && a > c && b < c)
		ra_rb(tmp, 1, 'a');
	else if (a > b && a > c && b > c)
	{
		ra_rb(tmp, 1, 'a');
		sa_sb(tmp, 1, 'a');
	}
	else if (a < b && a > c)
		rra_rrb(tmp, 1, 'a');
	else if (a < c && a > b)
		sa_sb(tmp, 1, 'a');
	else if (a < b && a < c)
	{
		sa_sb(tmp, 1, 'a');
		ra_rb(tmp, 1, 'a');
	}
}

void	four_sort(t_list **lsta, t_list **lstb, int size)
{
	t_list	*buf;
	int		i;

	i = 0;
	buf = *lsta;
	while (buf)
	{
		if (buf->index == 0 && (i <= size / 2))
			ra_rb(lsta, i, 'a');
		else if (buf->index == 0 && (i > size / 2))
			rra_rrb(lsta, size - i, 'a');
		i++;
		buf = buf->next;
	}
	pa_pb(lsta, lstb, 1, 'a');
	three_sort(lsta);
	pa_pb(lstb, lsta, 1, 'b');
}

void	five_sort(t_list **lsta, t_list **lstb, int size)
{
	t_list	*buf;
	int		i;

	i = 0;
	buf = *lsta;
	while (buf)
	{
		if (buf->index == 4 && (i <= size / 2))
			ra_rb(lsta, i, 'a');
		else if (buf->index == 4 && (i > size / 2))
			rra_rrb(lsta, size - i, 'a');
		i++;
		buf = buf->next;
	}
		pa_pb(lsta, lstb, 1, 'a');
		four_sort(lsta, lstb, size - 1);
		pa_pb(lstb, lsta, 1, 'b');
		ra_rb(lsta, 1, 'a');
}




void	big_sort(t_list **lsta, t_list **lstb, int size, int q)
{
	int	i;
	t_list	*buf;
	int	schet;

	i = 0;
	while (*lsta)
	{
		buf = *lsta;
		schet = 0;
		while (buf->index > (size / 10 + i))
		{
			buf = buf->next;
			schet++;
		}
		if (schet <= (size - i) / 2)
			ra_rb(lsta, schet, 'a');
		else if (schet > (size - i) / 2)
			rra_rrb(lsta, size - schet - i, 'a');
	if (buf->index < i)
	{
		pa_pb(lsta, lstb, 1, 'b');
		ra_rb(lstb, 1, 'b');
	}
	else
	{
		pa_pb(lsta, lstb, 1, 'b');
		if ((*lstb)->next)
		{
			if ((*lstb)->index < (*lstb)->next->index)
				sa_sb(lstb, 1, 'b');
		}
	}
		i++;
	}
	lstb_to_lsta(lsta, lstb, size);
}

void	lstb_to_lsta(t_list **lsta, t_list **lstb, int size)
{
	int		i;
	int		schet;
	t_list	*buf;

	i = 0;
	while (*lstb)
	{
		schet = 0;
		buf = *lstb;
		while (buf->index != size - i - 1)
		{
			schet++;
			buf = buf->next;
		}
		if (schet <= (size - i) / 2)
			ra_rb(lstb, schet, 'b');
		else if (schet > (size - i) / 2)
			rra_rrb(lstb, size - schet - i, 'b');
		pa_pb(lstb, lsta, 1, 'a');
		i++;
	}
}
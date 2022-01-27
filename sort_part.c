#include "push_swap.h"

void	indexing(int argc, const char **argv, t_list *buf)
{
	int	arr[argc];
	int	i;

	i = 0;
	while (*++argv)
		arr[i++] = ft_atoi(*argv);
	arr[argc-1] = '\0';
	qs(arr, 0, argc-2);
	while (buf)
	{
		i = -1;
		while (++i < argc - 1)
		{
			if (arr[i] == buf->content)
			{
				buf->index = i;
				break;
			}
		}
		(buf) = (buf)->next;
	}
}

void	swap(int *i, int *j)
{
	int	q;

	q = *i;
	*i = *j;
	*j = q;
}

void	qs(int *arr, int first, int last)
{
	int	i;
	int	j;
	int	x;

	i = first;
	j = last;
	x = arr[(first + last) / 2];
	while (i <= j)
	{
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;
		if (i <= j)
		{
			if (arr[i] > arr[j]) swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}
	if (i < last)
		qs(arr, i, last);
	if (first < j)
		qs(arr, first, j);
}

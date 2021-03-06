/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:33:32 by marvin            #+#    #+#             */
/*   Updated: 2022/01/27 23:33:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
		res = res * 10 + (*str++ - '0');
	return ((int)(res * sign));
}

int	check_int(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		res = res * 10 + (*str++ - '0');
		if (res * sign > 2147483647 || (res * sign) < -2147483648)
			return (1);
	}
	return (0);
}

int	check_dublicate(int q, const char **argv)
{
	while (*++argv)
	{
		if (q == ft_atoi(*argv))
			return (1);
	}
	return (0);
}

int	check_argv(const char **argv)
{
	char	*e;

	while (*++argv)
	{
		e = (char *)(*argv);
		while (*e)
		{
			if ((*e < '0' || *e > '9') && *e != '-')
				return (1);
			e++;
		}
		if (check_int(*argv) || check_dublicate(ft_atoi(*argv), argv))
			return (1);
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_list	*tmp;
	int		i;

	if (check_argv(argv))
		write(1, "Error\n", 7);
	else if (argc == 1)
		return (0);
	else
	{
		i = 0;
		tmp = NULL;
		while (argv[++i])
			ft_lstadd_back(&tmp, ft_lstnew(ft_atoi(argv[i])));
		indexing(argc, argv, tmp);
		if (is_sorted(tmp))
			raspred_f((argc - 1), &tmp);
		if (is_sorted(tmp))
			write(1, "Error\n", 7);
		clear_mem_lst(&tmp);
	}
	return (0);
}

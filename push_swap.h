/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeanuts <mpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:02:18 by mpeanuts          #+#    #+#             */
/*   Updated: 2021/10/19 19:02:19 by mpeanuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	PUSH_SWAP_H
# define	PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <malloc.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	raspred_f(int size, t_list	**tmp);
void	three_sort(t_list	**tmp);
void	print_t_list(t_list *tmp);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	sa_sb(t_list **lst, int time, char q);
void	ra_rb(t_list **lst, int time, char q);
void	rra_rrb(t_list **lst, int time, char q);
void	swap(int *i, int *j);
void	qs(int *arr, int first, int last);
void	indexing(int argc, const char **argv, t_list *buf);
void	four_sort(t_list **lsta, t_list **lstb, int size);
void	*pa_pb(t_list **lsta, t_list **lstb, int time, char q);
void	five_sort(t_list **lsta, t_list **lstb, int size);
int		ft_atoi(const char *str);
void	big_sort(t_list **lsta, t_list **lstb, int size, int q);
void	lstb_to_lsta(t_list **lsta, t_list **lstb, int size);
int		is_sorted(t_list *lst);
void	raspred_chet(t_list **lsta, t_list **lstb, int i, int size, int q);

#endif
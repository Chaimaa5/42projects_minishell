#include "../inc/header.h"

t_token	*ft_newtoken(int type, char *value)
{
	t_token	*new;

	new = malloc(sizeof(t_token) * 1);
	if (!new)
		return (0);
	new->content = ft_strdup(value);
    new->type = type;
	new->next = NULL;
	return (new);
}

int	ft_tokensize(t_token *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	ft_tokenadd_back(t_token **lst, t_token *new)
{
	new->next = NULL;
	if (!*lst)
		*lst = new;
	else
		ft_tokenlast(*lst)->next = new;
}

void	ft_tokenadd_front(t_token **lst, t_token *new)
{
	if (new)
		new->next = *lst;
	*lst = new;
}

t_token	*ft_tokenlast(t_token *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstclear(t_token **lst)
{
	t_token	*list;
	t_token	*next;
	*lst = (*lst)->next;
	printf("%s-------\n",(*lst)->content);

	list = *lst;
	while (list)
	{
		next = list->next;
		free(list->content);
		list = next;
	}
	*lst = NULL;
}

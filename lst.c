typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	list = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		list = ft_lstlast(*lst);
		list->next = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
		new->next = *lst;
		*lst = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*next;

	list = *lst;
	while (list)
	{
		next = list->next;
		ft_lstdelone(list, del);
		list = next;
	}
	*lst = NULL;
}

t_list	*ft_lstlast(t_list *lst)å
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(void	*content)
{
	t_list	*new;

	new = malloc(sizeof(t_list) * 1);
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *lst)
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

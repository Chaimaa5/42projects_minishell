#include "../../inc/header.h"

env_list	*new_env(char *key, char *content, char *separator)
{
	env_list	*new;

	new = malloc(sizeof(env_list) * 1);
	if (!new)
		return (0);
	new->key = key;
    new->content = content;
	new->separator = separator;
	new->next = NULL;
	return (new);
}

void	env_add_back(env_list **lst, env_list *new)
{
	env_list	*list;

	list = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		list = env_last(*lst);
		list->next = new;
	}
}

env_list	*env_last(env_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
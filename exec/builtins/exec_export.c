#include "../../inc/header.h"

void set_export()
{
    // split args
    // addback(content key)
}

void    print_exort(env_list *env)
{
	env_list *list;

	list = env;
	while (!list)
	{
		printf("declare -x %s%s%s\n", list->key, list->separator, list->content);
		list = list->next;
	}
}

void    exec_export(env_list *env)
{

}
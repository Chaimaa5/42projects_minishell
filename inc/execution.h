#ifndef EXECUTIONS_H
#define EXECUTIONS_H

#define WRITE 1
#define  READ 0

typedef struct  env_list
{
    char            *key;
    char            *content;
    char            *separator;
    struct env_list *next;    
}   env_list;

//builtins
int     exec_cd(char *path, env_list *env);
void    exec_echo(t_parser *parser);
void    exec_env(t_parser *parse, env_list **envp);
void    exec_exit(t_parser *parser);
void    exec_export(t_parser *parse, env_list **envp);
void    exec_pwd(void);
void    exec_unset(env_list **env, t_parser *parser);

//env_list
env_list	*env_last(env_list *lst);
void	    env_add_back(env_list **lst, env_list *new);
env_list    **read_env(char **envp);
env_list	*new_env(char *key, char *content, char *separator);
char        **env_list_to_char(env_list **env);
int         env_size(env_list **env);
env_list    *env_builder(char **envp);
int         search_env(env_list  **env, char *key);
char        *get_env(env_list  **env, char *key);
int         check_doube(env_list **env, char *key);


//export
void    set_export(env_list *env,  char **args);
void	replace_value(env_list  **env, char *key, char *value);
void    print_export(env_list **env);
int     check_key(char *key);


//unset
void    delete_env(env_list **env,  char *key);
int     ft_count_elems(char **str);


void	exec_builtins(t_parser **parse);
void    pipeline_execution(t_parser *parser, env_list **envp);
void    redirections(t_redirection *red, char *cmd);

char	*search(char **env, char *cmd);
char	**find_path(char **envp);
int	    find_path_env(char **envp, char *path);
void	free_array(char **array);


void    heredoc();

#endif
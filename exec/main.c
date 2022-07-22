  #include "../inc/header.h"


int main(int argc, char **argv, char **envp)
{
  redirections(argv, envp);
  loop_pipe()
}

void pipe-loop{
  int *end[2];

  while(cmd->next)
  {
    pipe(ends);
    int pid=fork();
    if (pid ==0)
    {
      child(cmd);
    }
    cmd = cmd->next;
  }
  execute-lastcmd();
}

typedef struct cmd{

  char *cmd;
  char **args;
  cmd *next; 
}

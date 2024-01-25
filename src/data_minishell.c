#include "../include/parsing.h"

void	prompt_user(t_minishell *shell)
{
	shell->prompt = readline("minishell-1.0$ ");
	if (shell->prompt == NULL)
	{
		shell->state = 0;
		shell->error->exit_code = 0;
	}
	else if (shell->prompt[0] != '\0')
		add_history(shell->prompt);
}
//va falloir penser a free ce que readline retourne

void	init_error_handling(t_minishell *shell)
{
	//shell->error = gc_malloc(sizeof(t_node));
	if(!shell->error)
		exit(1);
	shell->error->fd = 0;
	shell->error->exit_code = 0;
}

#include "../include/parsing.h"

int	main(int argc, char *argv[], char **envp)
{
	t_minishell	shell;

	ft_minishell(&shell, argc, argv, envp);
	while (shell.state)
	{
		ft_init_loop(&shell, envp);
		ft_process_loop(&shell);
	}
	return (SUCESS);
}

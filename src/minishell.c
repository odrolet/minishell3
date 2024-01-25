#include "../include/parsing.h"

static void	interrupt(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_minishell(t_minishell *shell, int argc, char *argv[], char **env)
{
	t_info	info;

	(void)argc;
	(void)argv;
	(void)shell;
	tcgetattr(STDIN_FILENO, &shell->term);
	signal(SIGINT, &interrupt);
	signal(SIGQUIT, SIG_IGN);
	ft_initstruct(&info, env);
	if (!info.env)
		ft_free_2darray(info.env);
	//init_error_handling(shell);
	shell->state = 1;
}

void	ft_init_loop(t_minishell *shell, char **envp)
{
	(void)envp;
	prompt_user(shell);
	// if (shell->prompt[0] != '\0')
	// 	add_history(shell->prompt);
}

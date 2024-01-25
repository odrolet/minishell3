#include "../include/parsing.h"

void	update_oldpwd(char	**env)
{
	char	*oldpwd;
	char	*oldpwd_env;
	int		i;
	int		j;
	char	*new_oldpwd_env;

	new_oldpwd_env = NULL;
	i = 0;
	j = 0;
	oldpwd = getenv("PWD");
	oldpwd_env = NULL;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			oldpwd_env = env[i];
			break ;
		}
		i++;
	}
	if (oldpwd_env != NULL)
		ft_memcpy(oldpwd_env + 7, oldpwd, ft_strlen(oldpwd));
	else
	{
		new_oldpwd_env = malloc(ft_strlen(oldpwd) + 8 + 1);
		ft_memcpy(new_oldpwd_env, "OLDPWD", 7);
		ft_memcpy(new_oldpwd_env + 7, oldpwd, ft_strlen(oldpwd));
		while (env[j] != NULL)
			j++;
	}
	env[j] = new_oldpwd_env;
	env[j + 1] = NULL;
}

void	ft_cpyenv(char **env_cpy, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		env_cpy[i] = ft_calloc(ft_strlen(envp[i]) + 1, sizeof(char));
		if (!env_cpy[i])
			return ;
		ft_memcpy(env_cpy[i], envp[i], ft_strlen(envp[i]));
		i++;
	}
}

int	ft_initstruct(t_info *info, char **envp)
{
	int		count;
	int		i;
	char	*initial_oldpwd;

	i = 0;
	count = 0;
	while (envp[count])
		count++;
	info->cmd_list = NULL;
	info->env = malloc((count + 1) * (sizeof(char *)));
	if (!info->env)
		return (MALLOC_FAIL);
	ft_cpyenv(info->env, envp);
	i = 0;
	initial_oldpwd = getcwd(NULL, 0);
	if (initial_oldpwd == NULL)
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
	update_oldpwd(info->env);
	free(initial_oldpwd);
	return (SUCESS);
}

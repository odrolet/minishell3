#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>

enum e_error_list
{
	FAILURE,
	SUCESS,
	MALLOC_FAIL,
};

typedef struct s_node
{
	void			*content;
	void			*address;
	struct Node		*next_mb;
}	t_node;

typedef struct s_errno
{
	int	fd;
	int	exit_code;
}	t_errno;

typedef struct s_minishell
{
	int					state;
	int					exit_code;
	char				**envp;
	char				*prompt;
	struct termios		term;
	t_errno				*error;
}	t_minishell;

typedef struct s_token
{
	int				index;
	int				type;
	char			*value;
	struct token	*next;
}	t_token;

typedef struct s_cmd
{
	char			**cmd;
	char			*token;
	pid_t			pid;
	struct s_cmd	*next;
	bool			built_in;
}		t_cmd;

typedef struct s_info
{
	t_cmd	*cmd_list;
	int		exit_code;
	char	**env;
}		t_info;

int		ft_initstruct(t_info *info, char **envp);
void	*ft_free_2darray(char **array);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	**ft_free(char **split);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
void	ft_minishell(t_minishell *shell, int argc, char *argv[], char **env);
void	ft_init_loop(t_minishell *shell, char **envp);
void	prompt_user(t_minishell *shell);
void	init_error_handling(t_minishell *shell);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
//void	gc_free(void *address);
//void	gc_free_all(void);
//void	*gc_malloc(size_t size);
//t_node	*garbage_collector(void);
t_token		ft_process_loop(t_minishell *shell);

#endif
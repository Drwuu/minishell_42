/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:11:17 by ivarosic          #+#    #+#             */
/*   Updated: 2021/11/13 04:56:28 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "mask.h"
# include "libft.h"
# include <signal.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_cmd
{
	char			*mask;
	char			**cmd;
	t_env			*env;
	bool			is_builtin;
	int				io[3];
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_shell
{
	char				**envp;
	char				*line;
	char				*mask;
	t_cmd				*cmd;
	char				**heredoc;
	int					io_save[2];
	struct sigaction	signal[4];
	size_t				nbcmd;
	t_env				*env;
	int					lastcmdret;
	bool				squote;
	bool				dquote;
}	t_shell;

typedef struct s_builtin
{
	char	*name;
	int		(*function)(t_shell *, char **);
}	t_builtin;

int		g_status;

char	*ft_strfsnr(char *str, char *search, char *replace);
char	*ft_strnsnr(char *str, char *search, char *replace, size_t n);
char	*ft_strsnr(const char *str, char *search, char *replace);
char	*ft_strfnsnr(char *str, char *search, char *replace, size_t n);
char	*ft_str_malloc(int n, char c);
int		syntax_error(char *error, char c);
int		reverse_env(t_shell *minis);
t_env	*ft_set_env(char **env);
size_t	check_nb_cmd(t_shell *minis, const char *line);
int		check_input_output(t_shell *minis, char *mask);
void	create_mask(t_shell *minis, char *str);
bool	set_quote(bool quote, bool quoteif, char c, char t);
char	*check_sp(t_shell *minis, char *str);
void	ft_cd(t_env *env);
void	ft_pwd(t_env *env);
void	ft_env(t_env *env);
void	ft_add_env(t_env *menv, char *env);

/* builtin */
int		builtin_echo(t_shell *shell, char **cmd);
int		builtin_env(t_shell *shell, char **cmd);
int		builtin_exit(t_shell *shell, char **cmd);
int		builtin_export(t_shell *shell, char **cmd);
int		builtin_unset(t_shell *shell, char **cmd);
int		builtin_pwd(t_shell *shell, char **cmd);
int		builtin_cd(t_shell *shell, char **cmd);
char	*getenv_name(t_shell *shell, char *name);

/* parsing */
int		parse_line(t_shell *minis, char *line);
int		replace_dol_int(t_shell *minis, size_t i);
void	calc_heredoc(t_shell *minis);
void	create_mask_post_env(t_shell *minis);
int		check_line_valitidy(t_shell *minis, const char *line);
int		split_command(t_shell *shell);
void	update_env(t_shell *minis);
void	sighandler(int signal);
int		get_cmd_args_nb(char *mask, int from);
void	check_nb_arg_process(t_shell *minis, size_t *i, size_t *arg);
int		check_nb_arg(t_shell *minis, size_t *j);
char	**create_cmd(char *mask, int from);
bool	is_builtin(t_cmd cmd);
char	*ft_strdel(char *str, int index);

/* execution */
void	heredoc(t_shell *shell);
void	exit_heredoc(char *line, char *heredoc, int exit_status, int fd[2]);
void	fill_heredoc(char **heredoc, char *line);
void	write_heredoc(char *line, char *heredoc, int fd[2]);
char	*get_binary(char *cmd, char **env_parsed);
void	execute_commands(t_shell *shell, t_cmd *cmd);
void	execute_builtin(t_shell *shell, char **cmd);
void	redirect_input(int last_elem, t_shell *shell, int *fd_pipe, int i);
void	redirect_output(int last_elem, t_shell *shell, int *fd_pipe, int i);
void	wait_childs(t_shell *shell, pid_t *pid, int nb_cmd);

/* tools */
char	*strjoin_shell(char const *s1, char const *s2);
char	*strdup_shell(const char *s1);

#endif

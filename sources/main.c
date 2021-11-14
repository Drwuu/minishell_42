/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 23:54:26 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/12 19:50:15 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_shlvl(t_shell *minis)
{
	t_env	*ptr;
	int		shlvl;

	ptr = minis->env;
	shlvl = 1;
	while (ptr)
	{
		if (ft_strncmp("SHLVL", ptr->name, ft_strlen("SHLVL") + 1) == 0)
		{
			shlvl += ft_atoi(ptr->value);
			wrfree(ptr->value);
			ptr->value = ft_itoa(shlvl);
		}
		ptr = ptr->next;
	}
}

void	sighandler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	g_status += 128;
}

static void	exec_prompt(t_shell *minis)
{
	char	*line;

	line = NULL;
	while (42)
	{
		minis->io_save[0] = dup(STDIN_FILENO);
		minis->io_save[1] = dup(STDOUT_FILENO);
		line = readline("minishell$ ");
		if (line == NULL)
		{
			write(1, "exit\n", 6);
			break ;
		}
		if (line[0] != 0)
		{
			if (parse_line(minis, line) != -1)
			{
				execute_commands(minis, minis->cmd);
				update_env(minis);
			}
			add_history(line);
		}
		wrfree(minis->cmd);
		free(line);
	}
}

int	main(int ac, char **av, char **env)
{
	t_shell	*minis;

	(void)ac;
	(void)av;
	minis = wrmalloc(sizeof(t_shell));
	minis->signal[0].__sigaction_u.__sa_handler = sighandler;
	minis->signal[2].__sigaction_u.__sa_handler = SIG_IGN;
	sigaction(SIGINT, &minis->signal[0], &minis->signal[1]);
	sigaction(SIGQUIT, &minis->signal[2], NULL);
	minis->env = ft_set_env(env);
	set_shlvl(minis);
	pipe(minis->io_save);
	exec_prompt(minis);
	if (close(minis->io_save[0]) == -1)
		ft_perror("close 3 error");
	if (close(minis->io_save[1]) == -1)
		ft_perror("close 4 error");
	wrdestroy();
	return (0);
}

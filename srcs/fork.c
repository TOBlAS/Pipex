/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:21:30 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/12/12 15:07:10 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	premier_enfant(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[1], 1);
	close(pipex.fd[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	if (access(pipex.cmd_args[0], F_OK) == -1)
	{
		pipex.cmd = cmd_get(pipex.cmd_paths, pipex.cmd_args[0]);
		if (!pipex.cmd)
		{
			free_enfant(&pipex);
			msg(ERROR_CMD);
			exit (1);
		}
	}
	else
		pipex.cmd = pipex.cmd_args[0];
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_enfant(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[0], 0);
	close(pipex.fd[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	if (access(pipex.cmd_args[0], F_OK) == -1)
	{
		pipex.cmd = cmd_get(pipex.cmd_paths, pipex.cmd_args[0]);
		if (!pipex.cmd)
		{
			free_enfant(&pipex);
			msg(ERROR_CMD);
			exit (1);
		}
	}
	else
		pipex.cmd = pipex.cmd_args[0];
	execve(pipex.cmd, pipex.cmd_args, envp);
}

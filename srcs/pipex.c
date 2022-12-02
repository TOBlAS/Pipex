/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobiaslst <tobiaslst@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:05:08 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/12/02 10:54:48 by tobiaslst        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main (int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (msg(ERROR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		error_msg(ERROR_INFILE);
	pipex.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0777);
	if (pipex.outfile < 0)
		error_msg(ERROR_OUTFILE);
	if (pipe(pipex.fd) < 0)
		error_msg(ERROR_PIPE);
	pipex.paths = path_finder(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		premier_enfant(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_enfant(pipex, argv, envp);
	close_fd(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_parent(&pipex);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:47:02 by tobiaslst         #+#    #+#             */
/*   Updated: 2022/12/12 15:10:09 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* write, read, close, access, pipe, dup2, execve, fork*/
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
/*open*/
# include <fcntl.h>
/*malloc, free, exit*/
# include <stdlib.h>
/*waitpid*/
# include <sys/wait.h>
/*perror*/
# include <stdio.h>

/*messages d'erreurs à display*/

# define ERROR_INPUT "Nombre d'arguments invalides.\n"
# define ERROR_INFILE "Infile"
# define ERROR_OUTFILE "Outfile"
# define ERROR_CMD "Command not found.\n"
# define ERROR_PIPE "Pipe"
# define ERROR_ENV "Wrong access (envp).\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

/*libft*/
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*error-msg.c*/
int		msg(char *c);
void	error_msg(char *c);

/*utils.c*/
char	*path_finder(char **envp);
void	close_fd(t_pipex	*pipex);
void	free_parent(t_pipex	*pipex);
void	free_enfant(t_pipex	*pipex);
char	*cmd_get(char **paths, char *cmd);

/*fork.c*/
void	premier_enfant(t_pipex pipex, char **argv, char **envp);
void	second_enfant(t_pipex pipex, char **argv, char **envp);

#endif

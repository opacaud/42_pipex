/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:38:09 by opacaud           #+#    #+#             */
/*   Updated: 2021/07/15 13:22:43 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exec(char *instr, char **cmd, char **envp)
{
	return (execve(instr, cmd, envp));
}

int	ft_child(char **av, char **envp, int pipefd[])
{
	char	**cmd;
	char	*path;
	int		infile;
	int		executed;

	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	infile = open(av[1], O_RDONLY, 0);
	if (infile < 0)
		exit(0);
	if (ft_check_access(av[1], "R_OK") < 0)
		exit(0);
	dup2(infile, STDIN_FILENO);
	cmd = ft_split(av[2], ' ');
	path = ft_get_path(cmd, envp);
	executed = ft_exec(path, cmd, envp);
	ft_free_array(cmd);
	free(path);
	if (executed < 0)
		exit(0);
	return (infile);
}

int	ft_parent(char **av, char **envp, int pipefd[])
{
	char	**cmd;
	char	*path;
	int		outfile;
	int		executed;

	outfile = ft_open_file(av, envp);
	if (ft_check_access(av[4], "W_OK | R_OK") < 0)
		exit(0);
	wait(0);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	dup2(outfile, STDOUT_FILENO);
	cmd = ft_split(av[3], ' ');
	path = ft_get_path(cmd, envp);
	executed = ft_exec(path, cmd, envp);
	ft_free_array(cmd);
	free(path);
	if (executed < 0)
		exit(0);
	return (outfile);
}

void	ft_child_or_parent(char **av, char **envp, int pipefd[], pid_t pid)
{
	int	infile;
	int	outfile;

	infile = 0;
	outfile = 0;
	if (pid == 0)
		infile = ft_child(av, envp, pipefd);
	else
		outfile = ft_parent(av, envp, pipefd);
	ft_close_files(infile, outfile);
}

int	main(int ac, char **av, char **envp)
{
	int		pipefd[2];
	int		ret_pipe;
	pid_t	pid;

	if (ac != 5 || ft_strlen(av[2]) == 0 || ft_strlen(av[3]) == 0)
		return (-1);
	if (access(av[1], F_OK) == -1)
	{
		write(2, "no such file or directory: ", 27);
		write(2, av[1], ft_strlen(av[1]));
		return (-1);
	}
	ret_pipe = pipe(pipefd);
	if (ret_pipe < 0)
		return (-1);
	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed\n");
		return (-1);
	}
	else
		ft_child_or_parent(av, envp, pipefd, pid);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt@student.42.fr <ddecourt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:59:43 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/20 16:23:45 by ddecourt@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **path_array)
{
	char	*path;
	int		i;

	i = -1;
	while (path_array[++i])
	{
		path = ft_strjoin(path_array[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
	}
	ft_clear_tab(&path_array);
	ft_putstr_fd(&cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
	return (NULL);
}

int	process_one(int *pipe, int *fd, char **argv, char **envp)
{
	char	**path_array;
	char	**cmd;

	if (*fd == -1)
	{
		perror(argv[1]);
		exit(0);
	}
	dup2(*pipe, STDOUT_FILENO);
	dup2(*fd, STDIN_FILENO);
	path_array = get_path(envp);
	cmd = ft_split(argv[2], ' ');
	if (path_array == NULL)
		exit(1);
	if (!(execve(find_path(cmd[0], path_array), cmd, envp)))
		return (0);
	return (0);
}

int	process_two(int *pipe, int *fd, char **argv, char **envp)
{
	char	**path_array;
	char	**cmd;

	if (*fd == -1)
	{
		perror(argv[4]);
		exit(0);
	}
	dup2(*fd, STDOUT_FILENO);
	dup2(*pipe, STDIN_FILENO);
	path_array = get_path(envp);
	cmd = ft_split(argv[3], ' ');
	if (path_array == NULL)
		exit (1);
	execve(find_path(cmd[0], path_array), cmd, envp);
	return (0);
}

void	ft_close(int *fd1, int *fd2, int *fd3)
{
	close(*fd1);
	close(*fd2);
	close(*fd3);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pipe_fd[2];
	int		pid;

	check_arg(argc);
	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		close(fd[1]);
		fd[0] = open(argv[1], O_RDONLY);
		process_one(&pipe_fd[1], &fd[0], argv, envp);
	}
	if (pid > 0)
	{
		waitpid(pid, 0, 0);
		close(pipe_fd[1]);
		close(fd[0]);
		fd[1] = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0664);
		process_two(&pipe_fd[0], &fd[1], argv, envp);
	}
	return (0);
}

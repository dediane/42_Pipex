/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:59:43 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/08 18:26:19 by ddecourt         ###   ########.fr       */
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
	free(path_array);
	ft_putstr_fd(&cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
	return (NULL);
}

int	process_one(int *pipe, int *fd, char **envp, char **argv)
{
	char	**cmd;
	char	**path_array;

	if (*fd == -1)
	{
		perror(argv[1]);
		exit(0);
	}
	cmd = NULL;
	dup2(*pipe, STDOUT_FILENO);
	dup2(*fd, STDIN_FILENO);
	cmd = ft_split(argv[2], ' ');
	path_array = get_path(envp);
	if (path_array == NULL)
		exit(1);
	execve(find_path(cmd[0], path_array), cmd, envp);
	free(cmd);
	return (0);
}

int	process_two(int *pipe, int *fd, char **envp, char **argv)
{
	char	**cmd;
	char	**path_array;

	if (fd[1] == -1)
	{
		perror(argv[4]);
		exit(0);
	}
	cmd = NULL;
	dup2(*fd, STDOUT_FILENO);
	dup2(*pipe, STDIN_FILENO);
	cmd = ft_split(argv[3], ' ');
	path_array = get_path(envp);
	if (path_array == NULL)
		exit (1);
	execve(find_path(cmd[0], path_array), cmd, envp);
	free(cmd);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pipe_fd[2];
	int		pid;
	int		status;

	status = 0;
	check_arg(argc);
	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		fd[0] = open(argv[1], O_RDONLY);
		process_one(&pipe_fd[1], &fd[0], envp, argv);
	}
	waitpid(pid, &status, 0);
	if (pid != 0)
	{
		fd[1] = open(argv[4], O_WRONLY | O_CREAT, 0664);
		process_two(&pipe_fd[0], &fd[1], envp, argv);
	}
	return (0);
}

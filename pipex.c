/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:33:44 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/05 21:33:46 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **path_array, char *file)
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
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": command not found\n", 2);
	return (NULL);
}

void	open_files(int *fd, int *fd2, char *s, char *s2)
{
	*fd = open(s, O_RDONLY);
	if (*fd == -1)
	{
		perror(s);
		exit(2);
	}
	*fd2 = open(s2, O_WRONLY | O_CREAT, 0644);
	if (*fd2 == -1)
	{
		perror(s);
		exit(2);
	}
	return ;
}

int	process_one(int *pipe, int *fd, char **envp, char **argv)
{
	char	**cmd;
	char	**path_array;

	cmd = NULL;
	dup2(*pipe, STDOUT_FILENO);
	dup2(*fd, STDIN_FILENO);
	cmd = ft_split(argv[2], ' ');
	path_array = get_path(envp);
	if (path_array == NULL)
		exit(0);
	execve(find_path(cmd[0], path_array, argv[1]), cmd, envp);
	free(cmd);
	return (0);
}

int	process_two(int *pipe, int *fd, char **envp, char **argv)
{
	char	**cmd;
	char	**path_array;

	cmd = NULL;
	dup2(*fd, STDOUT_FILENO);
	dup2(*pipe, STDIN_FILENO);
	cmd = ft_split(argv[3], ' ');
	path_array = get_path(envp);
	if (path_array == NULL)
		exit(0);
	execve(find_path(cmd[0], path_array, argv[4]), cmd, envp);
	free(cmd);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pipe_fd[2];
	int		pid;

	check_arg(argc);
	open_files(&fd[0], &fd[1], argv[1], argv[4]);
	if (pipe(pipe_fd) == -1)
		return (1);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		close(fd[1]);
		process_one(&pipe_fd[1], &fd[0], envp, argv);
	}
	else
	{
		close(pipe_fd[1]);
		close(fd[0]);
		process_two(&pipe_fd[0], &fd[1], envp, argv);
	}
	waitpid(pid, NULL, 0);
	return (0);
}

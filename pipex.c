/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:57:08 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/30 00:19:08 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

char *find_path(char *cmd, char **path_array)
{
	char *path;
	char *tmp;
	int i;

	i = -1;
	while (path_array[++i])
	{
		path = ft_strjoin(path_array[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0);
			return(path);
	}
}

/*int	execute_process(char *path, char *cmd, int out,  int in)
{
	//execve(cmd, cmd, path, NULL);
}*/

int main(int argc, char **argv, char **envp)
{
	int fd[2];
	int pipe_fd[2];
	int pid;
	char **path_array;
	char **cmd;

	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
		perror(argv[1]);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT);
	if (fd[1] == -1)
		perror(argv[argc - 1]);
 	path_array = get_path(envp);
	cmd = get_cmd_array(argv, argc);
	if (path_array == NULL)
		return (1);
 	if (pipe(pipe_fd) == -1)
 		return (1);
	//pipe_fd[0] -> reading pipe
	//pipe_fd[1] -> writing pipe
 	pid = fork();
	//child process part 
 	if (pid == 0)
 	{
 		dup2(pipe_fd[1], STDOUT_FILENO);
 	}
	//parent process part
	else 
	{
		
	}
 	waitpid(pid, NULL, 0);
 	return (0);
}

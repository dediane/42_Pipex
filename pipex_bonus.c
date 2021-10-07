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
	int i;

	i = -1;
	while (path_array[++i])
	{
		path = ft_strjoin(path_array[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
			return(path);
	}
	return (NULL);
}


int main(int argc, char **argv, char **envp)
{
	int fd[2];
	//int pipe_fd[2];
	//int pid;
	char **path_array;
	char **cmd1;

	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
		perror(argv[1]);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
	if (fd[1] == -1)
		perror(argv[argc - 1]);
 	path_array = get_path(envp);
	cmd1 = get_one_cmd(get_cmd_array(argv, argc));
	if (path_array == NULL)
		return (1);
	//"ls" "-l" "wc" (NULL)
	// char **cmds1
	// "ls" (NULL)
	// char **cmds2
	// "wc" "-l" (NULL)
	printf("%s\n", cmd[0]);
	printf("%s\n",find_path(cmd[0], path_array));
	execve(find_path(cmd[0], path_array), NULL, envp);
 	/*if (pipe(pipe_fd) == -1)
 		return (1);
	//pipe_fd[0] -> reading pipe
	//pipe_fd[1] -> writing pipe
	char *path;
	path = find_path(cmd[0], path_array);
 	pid = fork();
	//child process part 
 	if (pid == 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
	}
	//execute_child_process(path_array, cmd, pipe_fd[1], fd[0]);
	//parent process part
	else 
	{
		
	}
	close(pipe_fd[0]);
	close(fd[0]);
	close(fd[1]);
 	waitpid(pid, NULL, 0);*/
 	return (0);
}

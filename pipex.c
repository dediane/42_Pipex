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

/*char **get_command_list(char *s)
{

}*/

int main(int argc, char **argv, char **envp)
{
	int fd;
	//int pid1;
	char **path;
	char **cmd;
	char *s;

 	path = get_path(envp);
	s = convert_argv(argv, argc);
	cmd = ft_split(s, ' ');
	if (path == NULL)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		perror(argv[1]);
 	/*if (pipe(fd) == -1)
 		return (1);
 	pid1 = fork();
 	if (pid1 == 0)
 	{
 		dup2(fd[1], STDOUT_FILENO);
 		close(fd[0]);
 		close(fd[1]);
 	}
 	waitpid(pid1, NULL, 0);*/
 	return (0);
}

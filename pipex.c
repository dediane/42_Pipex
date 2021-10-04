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


/* 
1 - Récuperer le PATH d'envp
2 - Pipe et fork en deux process (child & parent)
3 - Executer la commande dans le Child process en redirigeant
 la sortie en utilisant dup2 & STDOUT_FILENO
 4 - Attendre la fin du process pour executer le 
 Parent process
 5 - Rediriger */
/*int main(int argc, char **argv, char **envp)
{
	int i = -1;

	printf("Valeur de ac = %d\n", argc);
	printf("Valeur de av[0] = %s\n", argv[0]);
	while (envp[++i])
	{
		printf("%s\n", envp[i]);
	}
}*/

char	**get_path(char **envp)
{
	int i;
	int j;
	char *path;

	i = -1;
	j = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH", 4) != 0)
			path = ft_strnstr(envp[i], "PATH", 4);
	}
	return (ft_split(path + 5, ':'));
}

char **parse_argv(char **argv, int argc)
{
	char *buffer;

	buffer = NULL;
	buffer = ft_strjoin(buffer, argv[argc - 1]);
	printf("Voici ma string -> %s\n", buffer);
	return(ft_split(buffer, ' '));	
}

int main(int argc, char **argv, char **envp)
{
	int fd[2];
	int pid1;
	char **path;
	char **cmd;

 	path = get_path(envp);
	cmd = parse_argv(argv, argc);
	if (path == NULL)
		return (1);
	printf("%s\n", path[0]);
	printf("%s\n", argv[0]);
	//printf("%s\n", cmd[0]);
	printf("%d\n", argc);
 	if (pipe(fd) == -1)
 		return (1);
 	pid1 = fork();
 	if (pid1 == 0)
 	{
 		dup2(fd[1], STDOUT_FILENO);
 		close(fd[0]);
 		close(fd[1]);
 	}
 	waitpid(pid1, NULL, 0);
 	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:02:09 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/05 13:02:12 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_path(char **envp)
{
	int		i;
	int		j;
	char	*path;

	i = -1;
	j = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH", 4) != 0)
			path = ft_strnstr(envp[i], "PATH", 4);
	}
	return (ft_split(path + 5, ':'));
}

char	*convert_argv(char **argv, int argc)
{
	int		size;
	int		i;
	char	*buffer;

	size = 0;
	i = 1;
	while (argv[++i] != argv[argc - 1])
		size += ft_strlen(argv[i]);
	buffer = malloc(sizeof(char) * (size + 1));
	ft_bzero(buffer, (size + 1));
	i = 1;
	while (argv[++i] != argv[argc - 1])
	{
		buffer = ft_strjoin(buffer, argv[i]);
		buffer = ft_strcat(buffer, " ");
	}
	argv[i + 1] = NULL;
	return (buffer);
}

int	get_size(char **tab)
{
	int	i;
	int	size;

	size = 0;
	i = -1;
	while (tab[++i] != NULL)
		size += ft_strlen(tab[i]);
	return (size);
}

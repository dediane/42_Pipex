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

char	**get_cmd_array(char **argv, int argc)
{
	char	*s;
	char	**array;

	s = convert_argv(argv, argc);
	array = ft_split(s, ' ');
	free(s);
	return (array);
}

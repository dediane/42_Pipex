/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:31:40 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/07 13:31:42 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pipex.h"

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

int check_arg(int i)
{
	if (i != 5)
	{
		ft_putstr_fd("Usage: [infile] [cmd1] [cmd2] [outfile]\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}

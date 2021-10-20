/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:44:18 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/15 17:24:16 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "inc/pipex_utils.h"
# include "inc/pipex_utils2.h"

char	**ft_split(char const *s, char c);

typedef struct s_a {
	char **envp;
	char **argv;
	char **cmd1;
	char **cmd2;
} t_a;

#endif

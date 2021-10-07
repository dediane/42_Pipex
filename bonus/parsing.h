/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:02:29 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/05 13:02:31 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		get_size(char **tab);
char	*convert_argv(char **argv, int argc);
char	**get_path(char **envp);
char	**get_cmd_array(char **argv, int argc);
void	ft_putstr_fd(char *s, int fd);
int		check_arg(int i);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:33:18 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/15 17:29:49 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS2_H
# define PIPEX_UTILS2_H

char	**get_path(char **envp);
int		check_arg(int i);
void	ft_clear_tab(char ***s);

#endif

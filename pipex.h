/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:57:18 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/28 20:57:20 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);

#endif
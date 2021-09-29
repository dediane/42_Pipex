/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:29:58 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/30 00:30:01 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strstr(char *haystack, char *needle)
{
	int i;
	int j;

	if (!(*needle))
		return ((char *)haystack);
	i = -1;
	while (haystack[++i])
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && needle[j])
			j++;
		if (!(needle[j]))
			return ((char *)(haystack + i));
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:38:09 by opacaud           #+#    #+#             */
/*   Updated: 2021/07/15 13:23:12 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*ft_search_path(char **paths, char *cmd)
{
	int		i;
	char	*path;
	char	*part_path;

	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free (part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free (path);
		i++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*car_spe1;
	unsigned char	*car_spe2;

	i = 0;
	car_spe1 = (unsigned char *)s1;
	car_spe2 = (unsigned char *)s2;
	while (i < n && s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	if (i == n)
		return (0);
	return (car_spe1[i] - car_spe2[i]);
}

int	ft_find_line(char **envp, char *path)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(path, envp[i], ft_strlen(path)) != 0)
		i++;
	return (i);
}

char	*ft_get_path(char **cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		line;

	line = ft_find_line(envp, "PATH");
	paths = ft_split(envp[line] + 5, ':');
	path = ft_search_path(paths, *cmd);
	if (path == 0)
	{
		write(2, "command not found: ", 19);
		write(2, *cmd, ft_strlen(*cmd));
		write(2, "\n", 1);
		exit (0);
	}
	ft_free_array(paths);
	return (path);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:38:09 by opacaud           #+#    #+#             */
/*   Updated: 2021/07/15 12:56:26 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_access(char *av, char *flag)
{
	if (ft_strncmp(flag, "R_OK", ft_strlen(flag)) == 0)
	{
		if (access(av, R_OK) < 0)
			return (-1);
	}
	else if (ft_strncmp(flag, "W_OK | R_OK", ft_strlen(flag)) == 0)
	{
		if (access(av, W_OK | R_OK) < 0)
			return (-1);
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;
	size_t	len;

	len = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_open_file(char **av, char **envp)
{
	int		outfile;
	char	*start;
	char	*path;
	int		line;

	line = ft_find_line(envp, "PWD");
	start = ft_strjoin(envp[line] + 4, "/");
	path = ft_strjoin(start, av[4]);
	outfile = open(path, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (outfile < 0)
		exit(0);
	free(start);
	free(path);
	return (outfile);
}

void	ft_close_files(int infile, int outfile)
{
	close(infile);
	close(outfile);
}

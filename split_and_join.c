/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:38:09 by opacaud           #+#    #+#             */
/*   Updated: 2021/07/15 10:48:45 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_count_lines(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0' && str[i] != c)
			count++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (count);
}

int	ft_str_s(char *str, int j, char c)
{
	int	str_size;

	str_size = 0;
	while (str[j] != '\0' && str[j] != c)
	{
		str_size++;
		j++;
	}
	return (str_size);
}

char	**ft_split(char *str, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = (char **)malloc(sizeof(char *) * (ft_count_lines(str, c) + 1));
	if (tab == 0)
		return (0);
	i = -1;
	j = 0;
	while (++i < ft_count_lines(str, c))
	{
		tab[i] = malloc(sizeof(char) * (ft_str_s(str, j, c) + 1));
		if (tab[i] == 0)
			return (0);
		k = 0;
		while (str[j] != '\0' && str[j] != c)
			tab[i][k++] = str[j++];
		tab[i][k] = '\0';
		j++;
	}
	tab[i] = 0;
	return (tab);
}

char	*ft_strjoin(char *ins, char *tmp)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	if (ins == 0 && tmp == 0)
		return (0);
	res = (char *)malloc(sizeof(char) * (ft_strlen(ins) + ft_strlen(tmp) + 1));
	if (res == 0)
		return (0);
	i = -1;
	size = ft_strlen(ins);
	while (++i < size)
		res[i] = ins[i];
	j = 0;
	size = ft_strlen(tmp);
	while (j < size)
	{
		res[i] = tmp[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

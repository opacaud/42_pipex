/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:41:52 by opacaud           #+#    #+#             */
/*   Updated: 2021/07/15 13:20:47 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_check_access(char *av, char *flag);
char	*ft_strdup(char *str);
int		ft_open_file(char **av, char **envp);
void	ft_close_files(int infile, int outfile);
int		ft_exec(char *instr, char **cmd, char **envp);
int		ft_child(char **av, char **envp, int pipefd[]);
int		ft_parent(char **av, char **envp, int pipefd[]);
void	ft_child_or_parent(char **av, char **envp, int pipefd[], pid_t pid);
void	ft_free_array(char **array);
char	*ft_search_path(char **paths, char *cmd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_find_line(char **envp, char *path);
char	*ft_get_path(char **cmd, char **envp);
int		ft_strlen(char *s);
int		ft_count_lines(char *str, char c);
int		ft_str_s(char *str, int j, char c);
char	**ft_split(char *str, char c);
char	*ft_strjoin(char *inst, char *tmp);

#endif

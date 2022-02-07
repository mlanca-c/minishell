/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:06:14 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/05 11:15:36 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*list_files(char *source);
t_list	*get_files(t_list *files, char *str);

/* This function handles filename expansion */
void	filename_expansion(void **word)
{
	char	*str;
	t_list	*files;

	if (!*word)
		return ;
	str = (char *)*word;
	if (ft_strfind(str, "*") == -1)
		return ;
	files = list_files(".");
	if (!files)
		return ;
	files = get_files(files, str);
	str = ft_lst_tostr(files, " ");
	if (!str)
		return ;
	free(*word);
	ft_lst_clear(files, free);
	*word = (void *)str;
}

t_list	*list_files(char *source)
{
	t_list			*list;
	DIR				*open_dir;
	struct dirent	*dir;

	if (!source)
		return (NULL);
	open_dir = opendir(source);
	if (!open_dir)
		return (NULL);
	list = NULL;
	while (true)
	{
		dir = readdir(open_dir);
		if (!dir)
			break ;
		if (ft_strncmp(dir->d_name, ".", 1) && ft_strncmp(dir->d_name, "..", 2))
			ft_lst_add_back(&list, ft_lst_new(ft_strdup(dir->d_name)));
	}
	closedir(open_dir);
	return (list);
}

t_list	*update_list_prefix(t_list *list, char *prefix)
{
	t_list	*l;
	char	*str;

	if (!prefix)
		return (list);
	l = NULL;
	while (list)
	{
		str = (char *)list->content;
		if (!ft_strncmp(str, prefix, ft_strlen(prefix)))
			ft_lst_add_back(&l, ft_lst_new(ft_strdup(str)));
		list = list->next;
	}
	ft_lst_clear(list, free);
	return (l);
}

t_list	*update_list_suffix(t_list *list, char *suffix)
{
	t_list	*l;
	char	*str;

	if (!suffix)
		return (list);
	l = NULL;
	while (list)
	{
		str = (char *)list->content;
		if (!ft_strncmp(&str[ft_strlen(str) - ft_strlen(suffix)],
				suffix, ft_strlen(suffix)))
			ft_lst_add_back(&l, ft_lst_new(ft_strdup(str)));
		list = list->next;
	}
	ft_lst_clear(list, free);
	return (l);
}

t_list	*get_files(t_list *files, char *str)
{
	char	*prefix;
	char	*suffix;
	int		i;

	i = ft_strfind(str, "*");
	if (i != 0)
	{
		prefix = ft_substr(str, 0, i);
		files = update_list_prefix(files, prefix);
	}
	if (i != (int)ft_strlen(str) - 1)
	{
		suffix = ft_substr(str, i + 1, ft_strlen(str));
		files = update_list_suffix(files, suffix);
	}
	return (files);
}

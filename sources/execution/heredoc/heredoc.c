/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:53:27 by josantos          #+#    #+#             */
/*   Updated: 2022/04/01 13:20:19 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*find_heredoc(t_list **lst);
static void		heredoc(t_cmd *command, t_list *eof);
static void		heredoc_cli(int fd, char *delimiter);

void	handle_heredoc(t_list *lst)
{
	t_cmd	*command;
	t_list	*eof;

	while (lst)
	{
		command = (t_cmd *)lst->content;
		eof = find_heredoc(&(command->redirection));
		if (eof)
			heredoc(command, eof);
		lst = lst->next;
	}
}

static t_list	*find_heredoc(t_list **lst)
{
	t_list	*copy;
	t_list	*tmp;
	t_list	*eof;
	t_red	*redirection;

	tmp = *lst;
	copy = NULL;
	eof = NULL;
	while (tmp)
	{
		redirection = (t_red *)tmp->content;
		if (redirection->io_type == DLESS)
			ft_lst_add_back(&eof, ft_lst_new(ft_strdup(redirection->io_file)));
		else
			ft_lst_add_back(&copy, ft_lst_new(copy_red(redirection)));
		tmp = tmp->next;
	}
	tmp = *lst;
	ft_lst_clear(tmp, free_redirection);
	*lst = copy;
	return (eof);
}

static void	heredoc(t_cmd *command, t_list *eof)
{
	t_list	*tmp;
	int		fd;
	char	*file;

	tmp = eof;
	file = NULL;
	while (eof)
	{
		if (file)
			unlink(file);
		file = "heredoc.tmp";
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		heredoc_cli(fd, eof->content);
		ft_lst_add_front(&command->suffix,
			ft_lst_new(ft_strdup("heredoc.tmp")));
		eof = eof->next;
	}
	ft_lst_clear(tmp, free);
}

static void	heredoc_cli(int fd, char *delimiter)
{
	char	*line;

	signals_heredoc();
	while (true)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, delimiter) == 0)
			break ;
		if (!ft_strlen(line))
		{
			free(line);
			continue ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
	close(fd);
	signals();
}

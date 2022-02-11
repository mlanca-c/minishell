/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:35:26 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/11 12:26:51 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_red		*redirection_get(t_list *lst);
static t_list		*redirection_clean(t_list *lst);
static t_token_t	redirection_get_type(char *str);

void	file_redirections(t_cmd *command)
{
	t_red	*redirection;
	t_list	*lst;

	lst = NULL;
	redirection = redirection_get(command->prefix);
	if (redirection)
	{
		ft_lst_add_back(&lst, ft_lst_new(redirection));
		command->prefix = redirection_clean(command->prefix);
	}
	redirection = redirection_get(command->suffix);
	if (redirection)
	{
		ft_lst_add_back(&lst, ft_lst_new(redirection));
		command->suffix = redirection_clean(command->suffix);
	}
	command->redirection = lst;
}

static t_token_t	redirection_get_type(char *str)
{
	static char	*type[] = {">", "<", ">>", "<<", NULL};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(type[i], str, ft_strlen(str)) == 0)
			return (i + 2);
		i++;
	}
	return (0);
}

static t_red	*redirection_get(t_list *lst)
{
	t_token_t	type;
	t_red		*redirection;
	char		*content;

	while (lst)
	{
		content = (char *)lst->content;
		type = redirection_get_type(content);
		if (type)
		{
			redirection = ft_calloc(1, sizeof(t_red));
			if (!redirection)
				exit_shell();
			redirection->io_type = type;
			lst = lst->next;
			content = (char *)lst->content;
			redirection->io_file = ft_strdup(content);
			return (redirection);
		}
		lst = lst->next;
	}
	return (NULL);
}

static t_list	*redirection_clean(t_list *lst)
{
	char		*content;
	t_token_t	type;
	t_list		*command;

	command = NULL;
	while (lst)
	{
		content = (char *)lst->content;
		type = redirection_get_type(content);
		if (type)
			lst = lst->next;
		else
			ft_lst_add_back(&command, ft_lst_new(ft_strdup(content)));
		lst = lst->next;
	}
	ft_lst_clear(lst, free);
	return (command);
}

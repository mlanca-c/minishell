/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_recognition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:29:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/13 18:51:24 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_recognition(char *line);

/*
#define NOTHING		0
#define OPERATOR	1
#define COMMENT		2
#define WORD		3
#define SQUOTE		4
#define DQUOTE		5

void	token_recognition(char *line)
{
	char	*current_token;
	t_list	*token_list;
	int		status;
	int		i;
	int		start;

	token_list = NULL;
	start = 0;
	i = 0;
	while (line[start])
	{
		while (ft_isspace(line[i]))
			i++;
		start = i;
		status = NOTHING;
		while (line[i])
		{
			if (status == OPERATOR)
			{
				if (ft_strchr("|&<>", line[i]))
				{
					i++;
					break ;
				}
				else
					break ;
			}
			if (line[i] == '\'' && status == SQUOTE)
			{
				i++;
				break ;
			}
			if (line[i] == '\'' && status == NOTHING)
			{
				status = SQUOTE;
				i++;
			}
			if (line[i] == '\"' && status == DQUOTE)
			{
				i++;
				break ;
			}
			if (line[i] == '\"' && status == NOTHING)
			{
				status = DQUOTE;
				i++;
			}
			else if (status == DQUOTE || status == SQUOTE)
				i++;
			else if (line[i] == '$' && status != SQUOTE && status != DQUOTE)
				while (!ft_isspace(line[i]))
					i++;
			else if (ft_strchr("|&<>", line[i]))
			{
				status = OPERATOR;
				i++;
			}
			else if (ft_isspace(line[i]))
				break ;
			else if (status == WORD)
				i++;
			else if (line[i] == '#')
			{
				status = COMMENT;
				i = ft_strlen(line);
				break ;
			}
			else
				status = WORD;
		}
		current_token = ft_substr(&line[start], 0, i - start);
		ft_lst_add_back(&token_list, ft_lst_new(current_token));
	}
	ft_lst_print(token_list);
	return ;
}

int	main(int argc, char **argv)
{
	//char *str = "file1 < echo -n \"Hello World\" | ls -la > file2";
	//char	*str = "echo -n \"Hello World \'$USER\'\"";
	char	*str = argv[1];
	printf("%s\n", str);
	token_recognition(str);
	return (0);
}
*/

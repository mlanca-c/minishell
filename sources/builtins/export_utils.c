#include "minishell.h"

void	print_export_env(t_list *env)
{
	while (env)
	{
		printf("declare -x ");
		printf("%s\n", (char *)env->content);
		env = env->next;
	}
}

void	sort_env(t_list *lst)
{
	char	*temp;

	while (lst && lst->next)
	{
		if (strncmp(lst->content, lst->next->content,
				ft_strlen(lst->content) + ft_strlen(lst->next->content)) > 0)
		{
			temp = lst->content;
			lst->content = lst->next->content;
			lst->next->content = temp;
		}
		lst = lst->next;
	}
}

int	sorted(t_list *lst)
{
	int	checker;

	checker = 0;
	while (lst && lst->next)
	{
		if (strncmp(lst->content, lst->next->content,
				ft_strlen(lst->content) + ft_strlen(lst->next->content)) > 0)
		{
			checker++;
		}
		lst = lst->next;
		if (checker != 0)
			break ;
	}
	return (checker);
}

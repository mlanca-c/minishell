

	typedef struct s_dictionary
	{
		struct s_dictionary	*next;
		void				*key;
		void				*content;
	}	t_dict;

	t_dict	*ft_dict_new(void *key, void *content);
	void	ft_dict_add_back(t_dict **dict, t_dict *new);
	void	ft_dict_add_front(t_dict **dict, t_dict *new);
	void	ft_dict_clear(t_dict *dict, void (*del)(void *));
	void	ft_dict_delete(t_dict *dict, void (*del)(void *));

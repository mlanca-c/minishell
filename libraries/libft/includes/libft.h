/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:17:39 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/03/31 11:40:26 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define MALLOC_ERROR "failed at allocating memory.\n"

/*
** This structure represents the elements of the singly-list.
**
** void	*content		- data contained in the element. The void * allows to
** 						store any kind of data.
** struct s_list *next	- next element’s address or NULL if it’s the last
** 						element.
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
** This structure represents the elements of the doubly-list.
**
** void	*content			- data contained in the element. The void * allows
** 							to store any kind of data.
** struct s_list *next		- next element’s address or NULL if it’s the last
** 							element.
** struct s_list *previous	- previous element’s address or NULL if it’s the
**							first element.
*/
typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*previous;
}	t_dlist;

/*
** This structure represents the elememts of a stack of integers.
**
** void	*data				- data contained in the element (integer).
** struct s_stack *next		- next element’s address or NULL if it’s the last
** 							element.
** struct s_stack *previous	- previous element’s address or NULL if it’s the
**							first element.
*/
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_ast
{
	void			*content;
	struct s_ast	*right;
	struct s_ast	*left;
}	t_ast;

typedef struct s_dictionary
{
	struct s_dictionary	*next;
	struct s_dictionary	*previous;
	void				*key;
	void				*content;
}	t_dict;

/* Dictionary functions */

t_dict		*ft_dict_new(void *key, void *content);
void		ft_dict_add_back(t_dict **dict, t_dict *new);
void		ft_dict_add_front(t_dict **dict, t_dict *new);
void		ft_dict_clear(t_dict *dict, void (*del)(void *));
void		ft_dict_delete(t_dict *dict, void (*del)(void *));
t_dict		*ft_dict_last(t_dict *dict);
t_dict		*ft_dict_front(t_dict *dict);
void		ft_dict_print(t_dict *dict, char *message1, char *message2);
void		*ft_dict_find(t_dict *dict, void *key);
void		*ft_dict_replace(t_dict *dict, void *key, void *value);
int			ft_dict_size(t_dict *dict);
char		**ft_dict_to_arr(t_dict *dict, char *delimiter);
t_dict		*ft_dict_copy(t_dict *dict);
void		ft_dict_sort(t_dict **dict);
int			ft_dict_key_exists(t_dict *dict, char *key);
void		ft_dict_remove(t_dict **dict, void (*del)(void *));

/*
** Abstract Syntax Tree (ast) Functions
*/
t_ast		*ft_ast_new(void *content);
void		ft_ast_add_left(t_ast **root, t_ast *new);
void		ft_ast_add_right(t_ast **root, t_ast *new);
void		ft_ast_delete(t_ast *node, void (*del)(void *));
void		ft_ast_clear(t_ast *root, void (*del)(void *));
void		ft_ast_print(t_ast *root);

/*
** Memory Functions
*/
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_malloc(int size, void (*error_message)(char *));
int			**ft_free_dintpointer(int **pipe);
char		**ft_free_dpointer(char **str);

/*
** String Functions
*/
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(const char *s);
int			ft_str_isalpha(char *str);
int			ft_str_isnumeric(char *str);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strncat(char *dst, char *src, unsigned int n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
void		ft_str_toupper(char *str);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoinc(char *s, char c);
int			ft_strfind(const char *s, char *find);
char		*ft_str_replace(char *source, char *sub, char *with);

/*
** Character Functions
*/
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isint(long long int n);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

/*
** Convertion Functions
*/
double		ft_atof(char *str);
long long	ft_atoi(const char *str);
int			ft_atoi_base(char *str, char *base);
int			ft_base_check(char *base);
char		*ft_itoa(int n);
char		*ft_itoa_base(unsigned long long int n, char *base);
long long	ft_atoll(char *str);
char		*ft_litoa(long n);
char		*ft_llitoa_base(unsigned long long n, char *base);
char		*ft_llitoa(long long n);

/*
** Print functions
*/
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

/*
** Math Functions
*/
int			ft_abs(int j);
int			ft_is_even(int j);
int			ft_is_negative(int n);
int			ft_nbrlen(unsigned long long int number, int base);
long long	ft_power(long long n, long long times);
void		ft_sort(int *array, int size);
void		ft_swap(int *a, int *b);

/*
** Single List Functions
*/
void		ft_lst_add_back(t_list **lst, t_list *new);
void		ft_lst_add_front(t_list **lst, t_list *new);
void		ft_lst_clear(t_list *lst, void (*del)(void *));
void		ft_lst_delete(t_list *lst, void (*del)(void *));
t_list		*ft_lst_last(t_list *lst);
t_list		*ft_lst_new(void *content);
void		ft_lst_print(t_list *lst, char *delimiter);
void		ft_lst_remove(t_list **lst, void (*del)(void *));
int			ft_lst_size(t_list *lst);
t_list		*ft_lst_copy(t_list *origin, int end);
char		*ft_lst_tostr(t_list *list, char *delimiter);
void		ft_lst_remove_first(t_list **lst, void (*del)(void *));
void		ft_lst_insert_pos(t_list **lst, t_list *insert, int pos);
void		ft_lst_remove_pos(t_list **lst, void (*del)(void *), int pos);

/*
** Double List Functions
*/
t_dlist		*ft_dlst_new(void *content);
void		ft_dlst_add_back(t_dlist **lst, t_dlist *new);
void		ft_dlst_add_front(t_dlist **lst, t_dlist *new);
void		ft_dlst_clear(t_dlist *lst, void (*del)(void *));
void		ft_dlst_delete(t_dlist *lst, void (*del)(void *));
t_dlist		*ft_dlst_last(t_dlist *lst);
void		ft_dlst_print(t_dlist *lst, char *delimiter);
int			ft_dlst_size(t_dlist *lst);
t_dlist		*ft_dlst_copy(t_dlist *origin, int end);
char		*ft_dlst_tostr(t_dlist *list, char *delimiter);
t_dlist		*ft_dlst_first(t_dlist *lst);

/*
** Stack Functions
*/
void		ft_stack_add_back(t_stack **stack, t_stack *new);
void		ft_stack_add_front(t_stack **stack, t_stack *new);
void		ft_stack_clear(t_stack **stack);
t_stack		*ft_stack_duplicate(t_stack *stack);
int			ft_stack_find(t_stack *stack, int value);
t_stack		*ft_stack_first(t_stack *stack);
int			ft_stack_get(t_stack *stack, int position);
int			ft_stack_has_bigger(t_stack *stack, int value);
int			ft_stack_is_duplicate(t_stack *stack);
int			ft_stack_is_sorted(t_stack *stack);
t_stack		*ft_stack_last(t_stack *stack);
int			ft_stack_max_value(t_stack *stack_a);
int			ft_stack_median(t_stack *stack);
int			ft_stack_min_value(t_stack *stack_a);
t_stack		*ft_stack_new(int data);
void		ft_stack_print(t_stack *stack);
void		ft_stack_remove(t_stack **stack);
int			ft_stack_size(t_stack *stack);
void		ft_stack_sort(t_stack **stack);

/*
** get_next_line Functions
*/
int			return_value(int reader);
int			has_new_line(char *saved);
char		*join_saved_buf(char *saved, char *buf);

#endif  /* LIBFT_H */

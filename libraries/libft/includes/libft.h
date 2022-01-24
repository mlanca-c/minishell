/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:52:45 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/23 12:52:11 by mlanca-c         ###   ########.fr       */
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

/*
** String Functions
*/
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(const char *s);
int			ft_str_isalpha(char *str);
int			ft_str_isnumeric(char *str);
int			ft_str_isoperator(char *str);
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
int			ft_isoperator(int c);

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
void		ft_lst_print(t_list *lst);
void		ft_lst_remove(t_list **lst);
int			ft_lst_size(t_list *lst);
t_list		*ft_lst_copy(t_list *origin, int end);

/*
** Double List Functions
*/
void		ft_dlist_add_back(t_dlist **dlist, t_dlist *new);
void		ft_dlist_add_front(t_dlist **dlist, t_dlist *new);
void		ft_dlist_clear(t_dlist **dlist);
t_dlist		*ft_dlist_duplicate(t_dlist *dlist);
t_dlist		*ft_dlist_last(t_dlist *dlist);
t_dlist		*ft_dlist_new(void *content);
void		ft_dlist_print(t_dlist *dlist);
void		ft_dlist_remove(t_dlist **dlist);
int			ft_dlist_size(t_dlist *dlist);

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
t_stack		*ft_merge_sort(t_stack *first, t_stack *second);
t_stack		*ft_stack_split(t_stack	*head);

/*
** get_next_line Functions
*/
int			return_value(int reader);
int			has_new_line(char *saved);
char		*join_saved_buf(char *saved, char *buf);

#endif

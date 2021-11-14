/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:31:31 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/11 14:10:54 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include <sys/time.h>
# include "wr_malloc.h"
# include "split_utils.h"
# include "get_next_line.h"

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_color
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_type
{
	T_CHAR,
	T_STRING,
	T_INT,
	T_UINT,
	T_LONG,
	T_ULONG,
	T_LONGLONG,
	T_ULONGLONG,
	T_FLOAT,
	T_DOUBLE,
	T_DICT
}	t_type;

typedef struct s_dictionary
{
	int		key;
	void	*value;
}			t_dictionary;

typedef struct s_list
{
	void			*content;
	t_type			type;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

/* compare */
t_bool			ft_is_smaller(int nb1, int nb2);
t_bool			ft_is_equal(int nb1, int nb2);
t_bool			ft_is_greater(int nb1, int nb2);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_ischar(const char *str, char c);
int				ft_ischars(const char *str, const char *chars);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isalpha(int c);
int				ft_iswhitespace(int c);

/* convert */
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_char_to_str(char c);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_ui(unsigned int n);
char			*ft_itoa_base(const char *base, unsigned long long n);

/* error */
void			ft_error(void *to_free, void **to_free_2, \
				t_list **lst_nullable, const char *msg_error);
void			ft_perror(const char *msg);

/* find */
int				ft_chr_index(const char *str, const char c, int i);
char			*ft_find_str_in_str(char *str, char *to_find);

/* graphic */
t_color			ft_create_color(unsigned char a, unsigned char r, \
					unsigned char g, unsigned char b);

/* list */
t_list			*ft_lstlast_to(t_list *last, int count);
t_list			*ft_lstnew(void *content, t_type type);
t_list			*ft_lstnew_addback(t_list **alst, void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstfirst(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *));
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list **lst);
void			ft_lstclear(t_list **lst);
void			ft_lstiter(t_list *lst, void (*f)(void *));
int				ft_lstsize(t_list *lst);

/* math */
float			ft_radian(float angle);
t_vec3			ft_vec3_create(float x, float y, float z);
t_vec3			ft_vec3_sub(t_vec3 vec_1, t_vec3 vec_2);
t_vec3			ft_vec3_normalize(t_vec3 vector);

/* mem */
void			*ft_calloc(size_t size, size_t count);
void			*ft_recalloc(char *old, size_t size, size_t count);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memreplace(void *b, int c, int from, int to);
void			**ft_free_dbl_array(void **datas, int size_nullable);

/* sort */
void			ft_sort_array_ascending(int **pt_array, int size);
void			ft_sort_array_descending(int **pt_array, int size);

/* split */
char			**ft_split(const char *s, const char *sep);

/* str */
size_t			ft_strlen(const char *s);
int				ft_strlen_dbl_array(char **double_array);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t destsize);
size_t			ft_strlcat(char *dst, const char *src, size_t destsize);
char			*ft_strnstr(const char *haystack, const char *needle, \
					size_t len);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_wfree(char *s1, char *s2);
char			*ft_strjoin_with_sep(char *s1, char const *s2, char c);
char			*ft_strjoinchar(char const *s1, char c);
char			*ft_strjoinchar_wfree(char *s1, char c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_strdup_dblarray(const char **dbl_array, int size);

/* time */
long long		ft_get_time(void);

/* write */
int				ft_putchar(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr_at_fd(const char *s, int start, int end, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/* debug */
typedef enum e_pf_color
{
	RED,
	BLUE,
	GREEN,
	YELLOW,
	CYAN,
	MAGENTA,
	BLACK,
	RESET
}	t_pf_color;
char			*get_printf_color(t_pf_color color);

#endif

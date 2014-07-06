/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:22:00 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/02 18:57:20 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_list	t_list;

struct			s_list
{
	void		*content;
	size_t		content_size;
	t_list		*next;
};

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int nb);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			*ft_memalloc(size_t n);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memset(void *b, int c, size_t n);
int				ft_putchar(char c);
int				ft_putchar_fd(char c, int fd);
int				ft_putendl(const char *s);
int				ft_putendl_fd(const char *s, int fd);
int				ft_putnbr(int c);
void			ft_putnbr_fd(int n, int fd);
int				ft_putstr(const char *str);
int				ft_putstr_fd(const char *s, int fd);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *str, int i);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *s1, const char *s2);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
int				ft_strequ(const char *s1, const char *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlcat(char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *s1, const char *s2, size_t n);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *str, int i);
char			**ft_strsplit(const char *s, char c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
size_t			ft_count_char_befor(char *str, char c);
int				ft_count_nb(int c);
int				ft_match(char *s1, char *s2);
int				ft_nmatch(char *s1, char *s2);
int				ft_putlnbr(long n);
unsigned int	ft_putpnbr(unsigned int n);
char			*ft_realloc_str(char *str, size_t n);
char			*ft_reverse_str(char *str);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_verify_word(char *word, char *verify);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:45:49 by jleann            #+#    #+#             */
/*   Updated: 2019/04/17 20:07:53 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "ft_get_next_line.h"

# ifndef LONG_MAX
#  define LONG_MAX	9223372036854775807
# endif
# ifndef LONG_MIN
#  define LONG_MIN	(-LONG_MAX -1L)
# endif
# ifndef ULONG_MAX
#  define ULONG_MAX	(LONG_MAX *2UL+1UL)
# endif

typedef unsigned char	t_byte;
typedef	struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}						t_list;

void					ft_bzero(void *s, size_t n);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
									size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memset(void *b, int c, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strdup(const char *s1);
size_t					ft_strlen(const char *s);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strstr(const char *haystack,
									const char *needle);
char					*ft_strnstr(const char *haystack, const char *needle,
									size_t len);
int						ft_tolower(int c);
int						ft_toupper(int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strchr(const char *s, int c);
int						ft_atoi(const char *str);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s,
							void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1,
								char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
									size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
char					*ft_itoa(int n);
char					**ft_strsplit(char const *s, char c);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstadd(t_list **alst, t_list *new);
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_lstdelone(t_list **alst, void (*del)(void*,
										size_t));
size_t					ft_lstlen(t_list *lst);
char					*ft_lsttostr(t_list *lst);
void					ft_lstaddend(t_list **alst, t_list *new);
void					*ft_lstat(t_list *alst, size_t at);
void					*ft_lstfind(t_list *alst, void *content,
		int (*f)(void *, void *));

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:46:25 by mpendilh          #+#    #+#             */
/*   Updated: 2024/11/20 10:41:19 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/gnl.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(char *nptr);
void	ft_bzero(char *s, int n);
char	*ft_calloc(int nmemb, int size);
int		ft_is_sign(int c);
int		ft_is_isspace(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
char	*ft_memchr(char *s, int c, int n);
int		ft_memcmp(char *s1, char *s2, int n);
char	*ft_memcpy(char *dest, char *src, int n);
char	*ft_memmove(char *dest, char *src, int n);
char	*ft_memset(char *s, int c, int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
char	*ft_strchr(char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s);
void	ft_striteri(char *s, void (*f)(int, char *));
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlcat(char *dst, char *src, int size);
int		ft_strlcpy(char *dst, char *src, int size);
int		ft_strlen(char *s);
char	*ft_strmapi(char *s, char (*f)(int, char));
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strnstr(char *big, char *little, int len);
char	*ft_strrchr(char *s, int c);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(char *s, int start, int len);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif

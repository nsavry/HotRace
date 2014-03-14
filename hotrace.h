/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 20:45:42 by nsavry            #+#    #+#             */
/*   Updated: 2013/12/14 15:28:17 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HOTRACE_H_
# define _HOTRACE_H_
# include <string.h>

typedef struct	s_key
{
	char	*tag;
	char	*link;
}				t_key;

int		ft_get_next_line(const int fd, char **line);
void	ft_putendl(const char *str);
void	ft_putstr(const char *str);
void	ft_putchar(char c);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *str1, const char *str2);
int		ft_strcmp(const char *str1, const char *str2);
void	ft_not_found(char *line);

#endif /* !_HOTRACE_H_ */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 12:10:22 by nsavry            #+#    #+#             */
/*   Updated: 2013/12/14 15:26:51 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strcpy(char *str1, const char *str2)
{
	int		i;

	i = 0;
	while (str2[i] != 0)
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = 0;
	return (str1);
}

int		ft_strcmp(const char *str1, const char *str2)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while ((str1[i] == str2[i]) && str1[i] && str2[i])
		i++;
	if (str1[i] < str2[i])
		result = -1;
	else if (str1[i] > str2[i])
		result = 1;
	else
		result = 0;
	return (result);
}

int		ft_get_next_line(const int fd, char **line)
{
	int		i;
	char	buf[2];
	char	*str;
	char	*tmp;

	str = malloc(sizeof(*str) * 2);
	str[0] = 0;
	i = 0;
	buf[0] = 't';
	while (buf[0] != '\n')
	{
		if (read(fd, buf, 1) == 0)
			return (0);
		buf[1] = 0;
		tmp = malloc(sizeof(*str) * (i + 2));
		str[i] = buf[0];
		str[i + 1] = 0;
		tmp = str;
		str = malloc(sizeof(*str) * (i + 2));
		str = tmp;
		i++;
	}
	str[i - 1] = 0;
	*line = str;
	return (1);
}

void	ft_not_found(char *line)
{
	ft_putstr(line);
	ft_putendl(": Not found.");
}

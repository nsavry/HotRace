/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 05:30:51 by nsavry            #+#    #+#             */
/*   Updated: 2013/12/14 15:27:04 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putendl(const char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

void	ft_putstr(const char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != 0)
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strdup(const char *str)
{
	int		len;
	char	*dup;

	len = ft_strlen(str);
	dup = (char *)malloc(sizeof(*dup) * (len + 1));
	dup = ft_strcpy(dup, str);
	return (dup);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

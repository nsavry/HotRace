/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 20:36:23 by nsavry            #+#    #+#             */
/*   Updated: 2013/12/15 15:47:51 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>
static t_key	*ft_store_key(int *i, int *p, int test);
static void		ft_search_and_display(int i, t_key *k);
static t_key	ft_fill_database(t_key k, t_key f, int *i, int *p);

int				main(void)
{
	t_key	*k;
	int		i;
	int		p;
	int		test;

	p = 0;
	test = 0;
	k = ft_store_key(&i, &p, test);
	if (ft_strcmp(k[0].tag, "errorempty") == 0)
	{
		if (ft_strcmp(k[0].link, "errorempty") == 0)
			ft_putendl("Error: File is empty");
		return (0);
	}
	if ((p % 2) != 0)
	{
		ft_putendl("Error: Database must be even");
		return (0);
	}
	ft_search_and_display(i, k);
	return (0);
}

static t_key	*ft_store_key(int *i, int *p, int test)
{
	t_key	*k;
	t_key	kread;

	*i = 0;
	k = (t_key *)malloc(sizeof(t_key) * 500000000);
	if (ft_get_next_line(0, &kread.tag) == 0)
	{
		k[0].tag = ft_strdup("errorempty");
		k[0].link = ft_strdup("errorempty");
		return (k);
	}
	while (1)
	{
		if (test == 1)
			ft_get_next_line(0, &kread.tag);
		test = 1;
		if (kread.tag[0] == 0)
			break ;
		(*p)++;
		if (ft_get_next_line(0, &kread.link) == 0)
			break ;
		k[*i] = ft_fill_database(k[*i], kread, p, i);
	}
	return (k);
}

static t_key	ft_fill_database(t_key k, t_key f, int *i, int *p)
{
	k.tag = ft_strdup(f.tag);
	k.link = ft_strdup(f.link);
	(*i)++;
	(*p)++;
	return (k);
}

static void		ft_search_and_display(int i, t_key *k)
{
	int		end;
	int		test;
	char	*tag;

	end = i - 1;
	while (ft_get_next_line(0, &tag))
	{
		i = end;
		test = 0;
		while (i + 1)
		{
			if (ft_strcmp(k[i].tag, tag) == 0)
			{
				test = 1;
				break ;
			}
			i--;
		}
		if (test == 0)
			ft_not_found(tag);
		else
			ft_putendl(k[i].link);
	}
	free(k);
}

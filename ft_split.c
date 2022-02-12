/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akirmizi <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:57:17 by akirmizi          #+#    #+#             */
/*   Updated: 2022/01/29 16:30:16 by akirmizi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static int	ft_strlen_c(const char	*s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	*ft_free_all(char **res, int i)
{
	while (i--)
		free(res[i]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		countwords;

	if (!s)
		return (NULL);
	i = 0;
	countwords = ft_count_words(s, c);
	res = malloc(sizeof(char *) * (countwords + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < countwords)
	{
		while (*s == c && *s)
			s++;
		res[i] = ft_substr(s, 0, ft_strlen_c(s, c));
		if (res[i] == NULL)
			return (ft_free_all(res, i));
		s += ft_strlen_c(s, c);
		i++;
	}
	res[i] = NULL;
	return (res);
}

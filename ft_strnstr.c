/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akirmizi <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:38:35 by akirmizi          #+#    #+#             */
/*   Updated: 2022/01/31 13:25:28 by akirmizi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (nd[0] == '\0')
		return ((char *)hs);
	while (hs[i] != 0 && i < len)
	{
		j = 0;
		while (hs[i + j] == nd[j] && hs[i + j] != '\0' && (i + j) < len)
		{
			if (nd[j + 1] == '\0')
				return ((char *)&hs[i]);
			j++;
		}
		i++;
	}
	return (0);
}

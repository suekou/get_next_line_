/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuenaga <ksuenaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:45:24 by ksuenaga          #+#    #+#             */
/*   Updated: 2024/02/13 17:24:47 by ksuenaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_locate_char(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	char	*start;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	concat = (char *)malloc((s1_size + s2_size + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	start = concat;
	while (*s1)
		*concat++ = *s1++;
	while (*s2)
		*concat++ = *s2++;
	*concat = '\0';
	return (start);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	s1_size;
	size_t	i;

	s1_size = ft_strlen(s1);
	dest = (char *)malloc((s1_size + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i <= s1_size)
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	size_t			substring_size;
	size_t			i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	substring_size = ft_strlen(s + start);
	if (substring_size > len)
		substring_size = len;
	substring = (char *)malloc((substring_size + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < substring_size && s[start + i])
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

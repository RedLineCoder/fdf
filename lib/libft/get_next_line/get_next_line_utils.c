/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moztop <moztop@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:10:06 by moztop            #+#    #+#             */
/*   Updated: 2024/06/07 18:21:44 by moztop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *str)
{
	if (str == NULL)
		return (0);
	if (*str == 0)
		return (0);
	return (1 + ft_strlen_gnl(str + 1));
}

int	ft_linesize(const char *str)
{
	if (str == NULL)
		return (0);
	if (*str == 0 || *str == '\n')
		return (0);
	return (1 + ft_linesize(str + 1));
}

char	*ft_strchr_gnl(const char *s, int c)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	if (s == NULL)
		return (NULL);
	if (*s == 0)
		return (NULL);
	if (*s == chr)
		return ((char *)s);
	return (ft_strchr_gnl((s + 1), c));
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (free(s1), NULL);
	str[s1_len + s2_len] = '\0';
	while (s2_len--)
		str[s1_len + s2_len] = s2[s2_len];
	while (s1_len--)
		str[s1_len] = s1[s1_len];
	return (free(s1), str);
}

char	*ft_substr_gnl(char *s, int start, int len)
{
	char	*substr;
	int		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen_gnl(s);
	if (s_len < start)
		return (NULL);
	if (s_len < len + start)
		len = s_len - start;
	substr = (char *)malloc((sizeof(char) * len + 1));
	if (!substr)
		return (free(s), NULL);
	substr[len] = '\0';
	while (len--)
		substr[len] = s[start + len];
	return (free(s), substr);
}

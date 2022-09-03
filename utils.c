/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:31:53 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:31:54 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_numlen(int n)
{
	unsigned int	len;
	long			m;

	m = n;
	len = 0;
	if (m < 0)
	{
		len++;
		m *= -1;
	}
	while (m > 9)
	{
		m /= 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		revind;
	int		misign;
	long	m;

	m = n;
	misign = 0;
	revind = ft_numlen(n);
	number = (char *)malloc(sizeof(char) * (ft_numlen(n) + 1));
	if (!number)
		return (NULL);
	number[revind] = '\0';
	if (m < 0)
	{
		misign = 1;
		m *= -1;
		number[0] = '-';
	}
	while (revind-- > misign)
	{
		number[revind] = (m % 10) + '0';
		m /= 10;
	}
	return (number);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	ind1;
	unsigned int	ind2;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ind1 = 0;
	while (s1[ind1])
	{
		str[ind1] = s1[ind1];
		ind1++;
	}
	ind2 = 0;
	while (s2[ind2])
		str[ind1++] = s2[ind2++];
	str[ind1] = '\0';
	return (str);
}

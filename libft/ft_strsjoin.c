/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:06:46 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 11:06:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsjoin(char *s1, char *s2, int free_s1, int free_s2)
{
	size_t	size;
	int		s1_length;
	int		s2_length;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	size = 0;
	s1_length = -1;
	while (s1[++s1_length])
		size++;
	s2_length = -1;
	while (s2[++s2_length])
		size++;
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, s1_length + 1);
	ft_strlcat(ptr, s2, size + 1);
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	return (ptr);
}
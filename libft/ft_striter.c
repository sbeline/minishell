/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:00:41 by sbeline           #+#    #+#             */
/*   Updated: 2015/01/07 12:46:22 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	int		i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(&s[i++]);
	}
}

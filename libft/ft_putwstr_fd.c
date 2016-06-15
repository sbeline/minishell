/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:07:34 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 17:07:36 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void 	ft_putwstr_fd(wchar_t *s, int fd)
{
	while (*s)
		ft_putwchar_fd(*s++, fd);
}
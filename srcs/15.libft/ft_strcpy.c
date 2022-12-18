/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:39:57 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/16 23:41:07 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*beg_pos;

	beg_pos = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (beg_pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:05:13 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/13 00:18:26 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

size_t	ft_strlen(const char *s)
{
	int	inc;

	inc = 0;
	while (*(s + inc) != '\0')
		inc++;
	return ((size_t)inc);
}

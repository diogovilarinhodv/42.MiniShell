/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:56:58 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/16 22:57:25 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			cnt;
	unsigned char	*ps;

	cnt = 0;
	ps = (unsigned char *) s;
	while (cnt < n)
	{
		*(ps + cnt) = '\0';
		cnt++;
	}
}

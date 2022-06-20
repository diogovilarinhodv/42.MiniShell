/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:34:21 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/20 18:35:26 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	inc;

	inc = 0;
	while (*(s1 + inc) != '\0' && *(s2 + inc) != '\0' && n > 0)
	{
		if (*(s1 + inc) > *(s2 + inc) || *(s1 + inc) < *(s2 + inc))
			break ;
		inc++;
		n--;
	}
	if (*(s1 + inc) > *(s2 + inc) && n > 0)
		return ((unsigned char) *(s1 + inc) - (unsigned char) *(s2 + inc));
	else if (*(s1 + inc) < *(s2 + inc) && n > 0)
		return ((unsigned char) *(s1 + inc) - (unsigned char) *(s2 + inc));
	else
		return (0);
}
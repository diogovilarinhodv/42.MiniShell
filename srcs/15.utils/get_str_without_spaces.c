/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_without_spaces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:18:55 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/08 16:33:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*get_str_without_spaces(char *str)
{
	int		inc;
	int		pos;
	char	*tmp_str;
	char	*new_str;

	inc = 0;
	pos = 0;
	tmp_str = malloc(sizeof(char) * ft_strlen(str));
	while (*(str + inc) == '\0')
	{
		while (*(str + inc) == ' ')
			inc++;
		*(tmp_str + pos) = *(str + inc);
		inc++;
		pos++;
	}
	*(tmp_str + pos) = '\0';
	new_str = ft_strdup(tmp_str);
	free_str(&tmp_str);
	return (new_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:58:54 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/13 15:51:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static char	*build_path(t_data *data, char *full_path, int beg, int end)
{
	char	*path;
	char	*new_path;
	int		inc;
	int		len;

	inc = 0;
	len = end - beg;
	if (len == 0)
		return (NULL);
	path = malloc(sizeof(char) * (len + 2));
	while (len > 0)
	{
		*(path + inc) = *(full_path + beg);
		beg++;
		inc++;
		len--;
	}
	*(path + inc) = '/';
	*(path + inc + 1) = '\0';
	new_path = ft_strjoin(path, *data->cur.cmd->token);
	free_str(&path);
	return (new_path);
}

char	*get_path(t_data *data, char *full_path)
{
	int		inc;
	int		last_pos;
	char	*new_path;

	inc = -1;
	last_pos = 0;
	while (*(full_path + ++inc) != '\0')
	{
		if (*(full_path + inc) == ':')
		{
			new_path = build_path(data, full_path, last_pos, inc);
			if (is_correct_path(new_path) == YES)
				return (new_path);
			free_str(&new_path);
			last_pos = inc + 1;
		}
	}
	if (inc > last_pos)
	{
		new_path = build_path(data, full_path, last_pos, inc);
		if (is_correct_path(new_path) == YES)
			return (new_path);
		free_str(&new_path);
	}
	return (NULL);
}

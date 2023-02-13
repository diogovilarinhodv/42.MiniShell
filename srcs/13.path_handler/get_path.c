/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:58:54 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/13 12:41:29 by dpestana         ###   ########.fr       */
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
	char	*path;

	inc = 0;
	last_pos = 0;
	while (*(full_path + inc) != '\0')
	{
		if (*(full_path + inc) == ':')
		{
			path = build_path(data, full_path, last_pos, inc);
			if (is_correct_path(path) == YES)
				return (path);
			free_str(&path);
			last_pos = inc + 1;
		}
		inc++;
	}
	if (inc > last_pos)
	{
		path = build_path(data, full_path, last_pos, inc);
		if (is_correct_path(path) == YES)
			return (path);
	}
	return (NULL);
}

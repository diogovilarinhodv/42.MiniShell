/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:58:54 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/02 22:36:17 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*get_path(t_data *data, char *str)
{
	char	*beg;
	char	*end;
	char	*path;
	char	*tmp;
	int		idx;

	idx = 0;
	beg = str;
	end = ft_strchr(str, ':');
	while (end != NULL)
	{
		path = ft_strndup(beg, ft_strlen(beg) - ft_strlen(end));
		tmp = ft_strjoin(path, "//");
		free_str(&path);
		path = ft_strjoin(tmp, *data->cur.cmd->token);
		free_str(&tmp);
		if (is_correct_path(path) == YES)
			return (path);
		free_str(&path);
		idx++;
		beg = end + 1;
		end = ft_strchr(beg, ':');
	}
	return (NULL);
}

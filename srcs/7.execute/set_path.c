/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:34:30 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/09 12:02:34 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	count_char(char *str, char c)
{
	int	inc;
	int	count;

	inc = 0;
	count = 0;
	while (*(str + inc) != '\0')
	{
		if (*(str + inc) == c)
			count++;
		inc++;
	}
	return (count);
}

static char	**split_str(char *str, char split_char)
{
	char	**str_return;
	char	*tmp;
	int		total_splits;
	int		inc;
	int		splits;
	int		beg;

	inc = 0;
	beg = 0;
	splits = 0;
	total_splits = count_char(str, split_char);
	if (total_splits == 0)
	{
		str_return = malloc(sizeof(char *) * 1);
		*str_return = ft_strdup(str);
	}
	else
	{
		str_return = malloc(sizeof(char *) * (total_splits + 1));
		while (*(str + inc) != '\0')
		{
			if (*(str + inc) == split_char)
			{
				tmp = ft_strndup((str + beg), inc - beg);
				*(str_return + splits) = ft_strjoin(tmp, "/");
				free(tmp);
				beg = inc + 1;
				splits++;
			}
			inc++;
		}
	}
	return (str_return);
}

static void	free_arr(char **arr)
{
	int	inc;

	inc = 0;
	if (arr != NULL)
	{
		while (*(arr + inc) != NULL)
		{
			free(*(arr + inc));
			*(arr + inc) = NULL;
			inc++;
		}
		free(arr);
		arr = NULL;
	}
}

void	set_path(t_data *data)
{
	char	*path_env;
	char	**path_env_splited;
	int		inc;
	char	*path;
	struct stat	statbuf;

	path = NULL;
	if (**data->cur.cmd->token == '/' || **data->cur.cmd->token == '.')
		return ;
	path_env = get_env_value(data, "PATH");
	path_env_splited = split_str(path_env, ':');
	inc = 0;
	while (*(path_env_splited + inc))
	{
		path = ft_strjoin(*(path_env_splited + inc), *data->cur.cmd->token);
		if (stat(path, &statbuf) == EXIT_SUCCESS)
			break ;
		free(path);
		path = NULL;
		inc++;
	}
	free_arr(path_env_splited);
	if (path != NULL)
	{
		free(*data->cur.cmd->token);
		*data->cur.cmd->token = path;
	}
}
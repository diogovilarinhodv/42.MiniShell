/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:09:47 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/10 17:18:51 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static char	*search_env_val(t_data *data, char *str)
{
	int		inc;
	char	*env_name;
	char	*env_val;

	inc = 0;
	env_val = NULL;
	while (*(str + inc) != '\0')
	{
		if (*(str + inc)  == ' ')
		{
			env_name = ft_strndup(str, inc);
			env_val = get_env_value(data, env_name);
			free(env_name);
			return (env_val);
		}
		inc++;
	}
	env_name = ft_strndup(str, inc);
	env_val = get_env_value(data, env_name);
	free(env_name);
	return (env_val);
}

static char	*search_dollar_signal(t_data *data)
{
	char	*clone;
	char	*token;
	char	*env_val;
	int		inc_chr;

	token = NULL;
	inc_chr = 0;
	while (*(data->cur.token + inc_chr) != '\0')
	{
		if (*(data->cur.token + inc_chr) == '$')
		{
			if (inc_chr > 0)
				token = ft_strndup(data->cur.token, inc_chr);
			env_val = search_env_val(data, (data->cur.token + inc_chr + 1));
			if (env_val == NULL)
			{
				free_str(&token);
				if (inc_chr == 0)
					token = ft_strdup("");
				return (token);
			}
			if (token != NULL)
			{
				clone = ft_strjoin(token, env_val);
				free(token);
				token = clone;
			}
			else
				token = ft_strdup(env_val);
			inc_chr++;
			env_val = (data->cur.token + inc_chr);
			break ;
		}
		inc_chr++;
	}
	return (token);
}

void	replace_env_var(t_data *data)
{
    char	*token;
	
	token = search_dollar_signal(data);
	free(data->cur.token);
	data->cur.token = token;
}
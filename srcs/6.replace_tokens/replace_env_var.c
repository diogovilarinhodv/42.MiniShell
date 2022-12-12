/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:09:47 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/11 23:40:48 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static char	*get_new_token(t_data *data)
{
	int		inc_chr;
	int		pos1;
	int		str_one_pos;
	char	*str_one;
	char	*str_two;
	char	*env_val;
	char	*new_token;
	char	*clone;

	new_token = NULL;
	clone = NULL;
	str_one = NULL;
	str_two = NULL;
	inc_chr = 0;
	str_one_pos = 0;
	while (*(data->cur.token + inc_chr) != '\0')
	{
		if (*(data->cur.token + inc_chr) == '$')
		{
			if (inc_chr != str_one_pos)
				str_one = ft_strndup((data->cur.token + str_one_pos), inc_chr - str_one_pos);
			else
				str_one = ft_strdup("");
			inc_chr++;
			pos1 = inc_chr;
			while (*(data->cur.token + inc_chr) != '\0' && *(data->cur.token + inc_chr) != ' ' && *(data->cur.token + inc_chr) != '$')
				inc_chr++;
			str_two = ft_strndup((data->cur.token + pos1), inc_chr - pos1);
			env_val = get_env_value(data, str_two);
			if (env_val == NULL)
			{
				if (new_token != NULL)
				{
					clone = ft_strjoin(new_token, str_one);
					free_str(&new_token);
					new_token = clone;
				}
				else
					new_token = ft_strdup(str_one);
			}
			else
			{
				if (new_token != NULL)
				{
					clone = ft_strjoin(new_token, str_one);
					free_str(&new_token);
					new_token = clone;
					clone = ft_strjoin(new_token, env_val);
					free_str(&new_token);
					new_token = clone;
				}
				else
					new_token = ft_strjoin(str_one, env_val);
			}
			free_str(&str_one);
			free_str(&str_two);
			if (*(data->cur.token + inc_chr) == '\0')
				break ;
			str_one_pos = inc_chr;
			inc_chr--;
		}
		inc_chr++;
	}
	return (new_token);
}

void	replace_env_var(t_data *data)
{
    char	*new_token;
	
	new_token = get_new_token(data);
	free(data->cur.token);
	data->cur.token = new_token;
}
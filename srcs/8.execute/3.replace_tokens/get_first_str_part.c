/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_str_part.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:21:00 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/15 14:10:55 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

static char	*set_env_value(t_data *data, char *env_value, char *bef_cipher_str)
{
	if (bef_cipher_str == NULL && env_value != NULL)
		env_value = ft_strdup(env_value);
	else
	{
		if (env_value != NULL)
			env_value = ft_strjoin(bef_cipher_str, env_value);
		else if (bef_cipher_str != NULL)
			env_value = ft_strdup(bef_cipher_str);
		free_str(&bef_cipher_str);
	}
	return (env_value);
}

char	*get_first_str_part(t_data *data)
{
	int		beg_pos;
	char	*env_name;
	char	*bef_cipher_str;
	char	*env_value;

	bef_cipher_str = NULL;
	if (data->cur.idx_chr > 0)
		bef_cipher_str = ft_strndup(data->cur.token, data->cur.idx_chr);
	data->cur.idx_chr++;
	beg_pos = data->cur.idx_chr;
	if (*(data->cur.token + data->cur.idx_chr) == '?')
		data->cur.idx_chr++;
	else
		while (is_letter(data) == YES)
			data->cur.idx_chr++;
	if (beg_pos == data->cur.idx_chr && data->cur.idx_chr == 0)
		return (NULL);
	else if (beg_pos == data->cur.idx_chr && data->cur.idx_chr > 0)
		return (bef_cipher_str);
	env_name = ft_strndup((data->cur.token + beg_pos),
			data->cur.idx_chr - beg_pos);
	env_value = get_env_value(data, env_name);
	free_str(&env_name);
	env_value = set_env_value(data, env_value, bef_cipher_str);
	return (env_value);
}

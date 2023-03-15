/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tilde.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:42:51 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/15 04:36:08 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	replace_tilde(t_data *data)
{
	char	*env_val;
	char	*new_tkn;
	char	*bef_tilde_str;
	int		len;

	bef_tilde_str = NULL;
	if (data->cur.idx_chr > 0)
		bef_tilde_str = ft_strndup(data->cur.token, data->cur.idx_chr);
	env_val = get_env_value(data, "HOME");
	if (env_val != NULL)
	{
		if (bef_tilde_str != NULL)
			env_val = ft_strjoin(bef_tilde_str, env_val);
		len = ft_strlen(env_val);
		if (*(data->cur.token + data->cur.idx_chr + 1) == '\0')
			new_tkn = ft_strdup(env_val);
		else
			new_tkn = ft_strjoin(env_val,
					(data->cur.token + data->cur.idx_chr + 1));
		free_str(&data->cur.token);
		data->cur.token = new_tkn;
		if (bef_tilde_str != NULL)
			free_str(&env_val);
		data->cur.idx_chr = len;
	}
	else
		data->cur.idx_chr++;
	free_str(&bef_tilde_str);
}

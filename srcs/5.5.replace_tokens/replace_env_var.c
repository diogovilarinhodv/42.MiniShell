/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:09:47 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/17 12:16:51 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	replace_env_var(t_data *data, int inc)
{
	char	*str;
	char	*env_val;
    char    *token;

	str = ft_strdup((*(data->tmp.cmd->token + inc) + 1));
	env_val = get_env_value(data, str);
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (env_val != NULL)
	{
        token = ft_strdup(env_val);
        free(*(data->tmp.cmd->token + inc));
        *(data->tmp.cmd->token + inc) = token;
	}
}
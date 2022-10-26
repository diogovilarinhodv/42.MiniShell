/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:09:47 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/19 12:22:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	replace_env_var(t_data *data, int inc)
{
	char	*str;
	char	*env_val;
    char	*token;

	str = ft_strdup((*(data->cur.cmd->token + inc) + 1));
	env_val = get_env_value(data, str);
	if (str != NULL)
		free(str);
	if (env_val != NULL)
		token = ft_strdup(env_val);
	else
		token = ft_strdup("");
	free(*(data->cur.cmd->token + inc));
	*(data->cur.cmd->token + inc) = token;
}
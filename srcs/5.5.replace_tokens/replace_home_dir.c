/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_home_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:12:13 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/17 14:14:30 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	replace_home_dir(t_data *data, int inc)
{
	char	*env_val;
    char    *token;

	env_val = get_env_value(data, "HOME");
	if (env_val != NULL)
	{
        token = ft_strdup(env_val);
        free(*(data->tmp.cmd->token + inc));
        *(data->tmp.cmd->token + inc) = token;
	}
}
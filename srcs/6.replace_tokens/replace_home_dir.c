/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_home_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:12:13 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/09 21:25:09 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	replace_home_dir(t_data *data)
{
	char	*env_val;
    char    *token;

	env_val = get_env_value(data, "HOME");
	if (env_val != NULL)
	{
        token = ft_strdup(env_val);
        free(data->cur.token);
        data->cur.token = token;
	}
}
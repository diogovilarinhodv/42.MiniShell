/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:12:09 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/04 16:20:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	initialize_env(t_data *data, char **env)
{
	data->env.full = NULL;
	set_env_lst(data, env);
	unset_env(data, "OLDPWD");
	set_shlvl_env(data);
}

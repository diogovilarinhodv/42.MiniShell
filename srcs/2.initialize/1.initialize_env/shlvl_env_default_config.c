/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl_env_default_config.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:15:34 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/04 18:01:57 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	shlvl_env_default_config(t_data *data)
{
	char	*str_shlvl_value;

	str_shlvl_value = get_env_value(data, "SHLVL");
	if (str_shlvl_value == NULL)
		set_env(data, "SHLVL", "1");
	else
		shlvl_env_increase(data, str_shlvl_value);
}

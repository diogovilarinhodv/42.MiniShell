/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shlvl_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:15:34 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/16 23:16:19 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_shlvl_env(t_data *data)
{
	char	*str_value;
	int		int_value;

	str_value = get_env_value(data, "SHLVL");
	if (str_value == NULL)
		set_env(data, "SHLVL", "1");
	else
	{
		int_value = ft_atoi(str_value);
		int_value++;
		str_value = ft_itoa(int_value);
		if (str_value == NULL)
			end_program(data, FAIL);
		set_env(data, "SHLVL", str_value);
		free(str_value);
		str_value = NULL;
	}
}
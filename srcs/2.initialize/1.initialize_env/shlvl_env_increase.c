/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl_env_increase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:54:12 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/04 18:00:48 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	shlvl_env_increase(t_data *data, char *str_shlvl_value)
{
	int		int_shlvl_value;

	int_shlvl_value = ft_atoi(str_shlvl_value);
	int_shlvl_value++;
	str_shlvl_value = ft_itoa(int_shlvl_value);
	if (str_shlvl_value == NULL)
		end_program(data, FAIL);
	set_env(data, "SHLVL", str_shlvl_value);
	free_str(&str_shlvl_value);
}

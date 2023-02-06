/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit_status_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:47:26 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 16:53:01 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_exit_status_env(t_data *data)
{
	char	*str_exit_status;

	str_exit_status = ft_itoa(data->exit_status);
	if (str_exit_status == NULL)
		end_program(data, FAIL);
	set_env(data, "?", str_exit_status);
	free(str_exit_status);
}

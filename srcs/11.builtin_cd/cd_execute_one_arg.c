/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_execute_one_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:59:51 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/28 16:00:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	cd_execute_one_arg(t_data *data)
{
	if (ft_strcmp(*(data->cur.cmd->token + 1), "-") == 0)
		cd_back(data);
	else
		cd_arg(data);
}

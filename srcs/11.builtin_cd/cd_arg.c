/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:00:12 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/28 16:05:21 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	cd_arg(t_data *data)
{
	if (chdir(*(data->cur.cmd->token + 1)) == -1)
	{	
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	cd_update_pwd_oldpwd(data);
}

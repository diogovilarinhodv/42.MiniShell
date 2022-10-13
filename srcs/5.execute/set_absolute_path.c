/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:34:30 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/13 09:34:59 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_absolute_path(t_data *data)
{
	char	*cmd;

	if (!(ft_strncmp(*data->tmp.cmd->token, "/bin/", 5) == 0))
	{
		cmd = ft_strjoin("/bin/", *data->tmp.cmd->token);
		free(*data->tmp.cmd->token);
		*data->tmp.cmd->token = cmd;
	}
}
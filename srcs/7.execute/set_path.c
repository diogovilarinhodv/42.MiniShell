/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:34:30 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/06 12:15:28 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_path(t_data *data)
{
	char	*cmd;

	if (*data->cur.cmd->token == '/' || *data->cur.cmd->token == '.')
		return ;
	
	
	
	/*
	if (!(ft_strncmp(*data->cur.cmd->token, "/bin/", 5) == 0))
	{
		cmd = ft_strjoin("/bin/", *data->cur.cmd->token);
		free(*data->cur.cmd->token);
		*data->cur.cmd->token = cmd;
	}
	*/
}
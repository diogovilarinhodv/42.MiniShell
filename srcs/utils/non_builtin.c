/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:01:54 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/12 17:55:10 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	non_builtin(t_data *data)
{
	int		id;
	int		inc;
	char	*cmd;
	char	**args;
	
	cmd = ft_strjoin("/bin/", data->input.cmd);
	args = malloc(sizeof(char **) * (data->input.qty_args + 1));
	inc = 0;
	while (inc < data->input.qty_args + 1)
	{
		if (inc == 0)
			*args = cmd;
		else
			*(args + inc) = *(data->input.args + inc - 1);
		inc++;
	}
	id = fork();
	if (id == 0)
		execve(cmd, args, NULL);
	if (id != 0)
		wait(0);
	if (cmd != NULL)
		free(cmd);
	if (args != NULL)
		free(args);
}

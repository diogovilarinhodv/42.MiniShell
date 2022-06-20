/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/19 17:01:16 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void builtin_cd(t_data *data)
{
	int		inc;
	int		success;

	inc = 0;
	while (*(data->cmd + inc) == ' ')
		inc++;
	if (*(data->cmd + inc) == 'c')
		inc++;
	else
		return ;
	if (*(data->cmd + inc) == 'd')
		inc++;
	else
		return ;
	while (*(data->cmd + inc) == ' ')
		inc++;
	if (*(data->cmd + inc) == '\0')
		success = chdir("");
	else
		success = chdir((data->cmd + inc));
	if (success < 0)
		printf("error!\n");
	if (data->pwd != NULL)
		free(data->pwd);
	data->pwd = getcwd(NULL, 0);
}
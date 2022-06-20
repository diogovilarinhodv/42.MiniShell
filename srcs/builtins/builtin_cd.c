/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:56:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/20 20:54:44 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void builtin_cd(t_data *data)
{
	int		success;

	if (data->input.qty_args == 1)
		success = chdir(*data->input.args);
	else
		success = chdir("..");
	if (success < 0)
		printf("error!\n");
	if (data->pwd != NULL)
		free(data->pwd);
	data->pwd = getcwd(NULL, 0);
}
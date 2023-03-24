/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_set_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:50:04 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/24 12:08:16 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

char	*export_set_name(t_data *data, int *inc)
{
	char	*env_name;

	while (*(*(data->cur.cmd->token + 1) + *inc) != '='
		&& *(*(data->cur.cmd->token + 1) + *inc) != '\0')
		(*inc)++;
	if ((*inc) == 0)
		return (NULL);
	env_name = ft_substr(*(data->cur.cmd->token + 1), 0, *inc);
	return (env_name);
}

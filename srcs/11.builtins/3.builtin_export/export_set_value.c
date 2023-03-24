/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_set_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:51:40 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/24 12:20:58 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

char	*export_set_value(t_data *data, int inc)
{
	char	*env_value;
	int		len;

	if (*(*(data->cur.cmd->token + 1) + inc) == '\0')
		return (NULL);
	len = ft_strlen(*(data->cur.cmd->token + 1));
	if (*(*(data->cur.cmd->token + 1) + inc + 1) == '\"'
		&& *(*(data->cur.cmd->token + 1) + len - 1) == '\"')
		env_value = ft_substr(*(data->cur.cmd->token + 1),
				inc + 2,
				len - (inc + 3));
	else
		env_value = ft_substr(*(data->cur.cmd->token + 1),
				inc + 1,
				len - (inc + 1));
	return (env_value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:36:49 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/08 13:55:04 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

int	is_line_empty(t_data *data)
{
	if (data->input.line == NULL)
		return (YES);
	if (*data->input.line == '\0')
		return (YES);
	return (NO);
}

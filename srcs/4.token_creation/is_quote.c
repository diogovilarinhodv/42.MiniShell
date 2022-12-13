/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:22:33 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:03:17 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_quote(t_data *data)
{
	if (*(data->input.line + data->input.idx) == '"'
		|| *(data->input.line + data->input.idx) == '\'')
		return (YES);
	return (NO);
}

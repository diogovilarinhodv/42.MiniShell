/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_has_tilde.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:21:33 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:06:25 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	token_has_tilde(t_data *data)
{
	if (*data->cur.token == '~')
		return (YES);
	if (*data->cur.token == '~' && (*data->cur.token + 1) == '/')
		return (YES);
	return (NO);
}

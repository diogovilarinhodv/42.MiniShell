/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:09:47 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 02:58:23 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	replace_env_var(t_data *data)
{
	char	*new_token;

	new_token = new_tkn_replace(data);
	free(data->cur.token);
	data->cur.token = new_token;
}

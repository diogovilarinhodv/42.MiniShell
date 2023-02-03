/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_double_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:01:08 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:04:49 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	remove_double_quotes(t_data *data)
{
	char	*token;

	token = ft_strndup((data->cur.token + 1), ft_strlen(data->cur.token) - 2);
	free(data->cur.token);
	data->cur.token = token;
}

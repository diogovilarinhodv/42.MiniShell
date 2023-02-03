/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_single_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:04:22 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 04:04:54 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	remove_single_quotes(t_data *data)
{
	char	*token;

	token = ft_strndup((data->cur.token + 1), ft_strlen(data->cur.token) - 2);
	free(data->cur.token);
	data->cur.token = token;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_one_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:56:00 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 02:56:15 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*get_str_one_replace(t_data *data, int **inc_chr, int pos)
{
	char	*str_one;

	if (**inc_chr != pos)
		str_one = ft_strndup((data->cur.token + pos), **inc_chr - pos);
	else
		str_one = ft_strdup("");
	(**inc_chr)++;
	return (str_one);
}

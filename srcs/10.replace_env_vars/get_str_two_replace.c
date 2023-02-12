/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_two_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:56:28 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 17:17:13 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*get_str_two_replace(t_data *data, int **inc_chr)
{
	int		pos;
	char	*str_two;
	char	*env_val;

	pos = **inc_chr;
	while (*(data->cur.token + **inc_chr) != '\0'
		&& *(data->cur.token + **inc_chr) != ' '
		&& *(data->cur.token + **inc_chr) != '$')
		(**inc_chr)++;
	str_two = ft_strndup((data->cur.token + pos), **inc_chr - pos);
	env_val = get_env_value(data, str_two);
	free_str(&str_two);
	return (env_val);
}

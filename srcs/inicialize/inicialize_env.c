/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:27:08 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/20 18:34:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	inicialize_env(t_data *data, char **env)
{
	int		inc;
	int		len;
	char	*str;

	inc = 0;
	data->env.qty = 0;
	while (*(env + inc) != NULL)
		inc++;
	data->env.name = malloc(sizeof(char **) * inc);
	data->env.value = malloc(sizeof(char **) * inc);
	while (*(env + data->env.qty) != NULL)
	{
		inc = 0;
		while (*(*(env + data->env.qty) + inc) != '=')
			inc++;
		len = ft_strlen(*(env + data->env.qty)) - (inc + 1);
		str = *(env + data->env.qty);
		*(data->env.name + data->env.qty) = ft_substr(str, 0, inc);
		*(data->env.value + data->env.qty) = ft_substr(str, inc + 1, len);
		data->env.qty++;
	}
}

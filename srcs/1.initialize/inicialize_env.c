/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:27:08 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/14 02:05:28 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	set_env_lst(t_data *data, char **env)
{
	int		inc;
	int		len;
	char	*str;

	inc = 0;
	while (*(*(env + (data->env.qty - 1)) + inc) != '=')
		inc++;
	len = ft_strlen(*(env + (data->env.qty - 1))) - (inc + 1);
	str = *(env + (data->env.qty - 1));
	*(data->env.name + (data->env.qty - 1)) = ft_substr(str, 0, inc);
	*(data->env.value + (data->env.qty - 1)) = ft_substr(str, inc + 1, len);
	data->env.qty--;
}

void	initialize_env(t_data *data, char **env)
{
	int	env_qty;

	data->env.qty = 0;
	if (env == NULL)
		env_empty();
	while (*(env + data->env.qty) != NULL)
		data->env.qty++;
	env_qty = data->env.qty;
	data->env.name = malloc(sizeof(char **) * data->env.qty);
	data->env.value = malloc(sizeof(char **) * data->env.qty);
	while (data->env.qty > 0)
		set_env_lst(data, env);
	data->env.qty = env_qty;
}

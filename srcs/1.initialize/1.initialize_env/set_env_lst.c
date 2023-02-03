/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:27:08 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/02 19:12:44 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

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

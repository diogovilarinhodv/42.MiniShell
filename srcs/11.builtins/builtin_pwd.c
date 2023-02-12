/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:02:27 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/12 13:05:44 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_pwd(t_data *data)
{
	char	*pwd_val;

	pwd_val = get_env_value(data, "PWD");
	if (pwd_val == NULL)
		return ;
	write_str(pwd_val);
	write_str("\n");
}

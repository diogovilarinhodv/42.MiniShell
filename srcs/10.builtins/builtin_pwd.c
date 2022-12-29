/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:02:27 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/28 16:33:58 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	builtin_pwd(t_data *data)
{
	char	*pwd_val;

	pwd_val = get_env_value(data, "PWD");
	if (pwd_val == NULL)
		return ;
	write(STDOUT_FILENO, pwd_val, ft_strlen(pwd_val));
	write(STDOUT_FILENO, "\n", ft_strlen("\n"));
}

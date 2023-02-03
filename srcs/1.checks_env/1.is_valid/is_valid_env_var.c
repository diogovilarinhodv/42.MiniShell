/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:40:25 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/02 19:45:27 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	is_valid_env_var(char **env)
{
	if (env == NULL)
	{
		write(STDOUT_FILENO, "Error\n", ft_strlen("Error\n"));
		exit(1);
	}
}
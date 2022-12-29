/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_empty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:48:36 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/20 13:10:28 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	env_empty(void)
{
	write(STDOUT_FILENO, "Error\n", ft_strlen("Error\n"));
	exit(1);
}
